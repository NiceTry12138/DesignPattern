<!--
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-02 16:24:15
 * @LastEditors: LC
 * @LastEditTime: 2021-12-03 11:49:31
 * @Description: 适配器模式
-->
# 适配器模式

## 目标

- 美标插头转换国标插头
- 国标插头转换美标插头
- 支持双向转换，二合一

## 实现

电器都有电压要求，有额定电压的初始值，所以定义`BaseSocket`作为所有插头的基类

```cpp
class BaseSocket
{
public:
	void SetCurrentVoltag(int voltag);
	int GetRatedVoltag();
	BaseSocket(int ratedvoltag);
	virtual ~BaseSocket();
	void DoWork();
protected:
	virtual void WorkNormal();
	virtual void WorkWarning();

private:
	int m_RatedVoltag;		// 额定电压
	int m_CurrentVoltag;	// 当前电压
};
```

- 插头工作分为`WOrkNormal`正常工作和`WorkWarning`异常工作，子类重写该方法可以自定义工作状态，区分工作状态的条件就是当前电压`m_CurrentVoltag`与额定电压`m_RatedVoltag`是否相等
- 额定电压初始之后不可设置，所以只提供Get方法；当前电压外界一般都知道，所以只提供Set方法

随后使用继承`BaseSocket`，来分别实现`AmericanSocket`和`ChineseSocket`，并分别定义自己的`AmericanSocketInput`和`ChineseSocketInput`方法

-----

定义适配器`Adapter`，使用双继承的方式分别继承`ChineseSocket`和`AmericanSocket`

```cpp
class Adapter : public AmericanSocket, public ChineseSocket
{
public:
    Adapter(ChineseSocket* ChineseSocket, AmericanSocket* AmericanSocket);

    std::string AmericanSocketInput() const;
    std::string ChineseSocketInput() const;

    void SetCurrentVoltag(int voltag)   {
        if (voltag != BaseSocket::GetRatedVoltag())   {
            voltag = BaseSocket::GetRatedVoltag();
        }
        BaseSocket::SetCurrentVoltag(voltag);
    }
protected:

private:
    ChineseSocket* m_ChineseSocket{ nullptr };
    AmericanSocket* m_AmericanSocket{ nullptr };
};
```

- 分别针对美标和国标进行方法的重写适配
- `SetCurrentVoltag`方法对电压的设置进行覆盖操作，从而不考虑外界电压是多少都可以对插口正常的额定电压供给

------

运行样例

```cpp
std::shared_ptr<AmericanSocket> americanSocket(new AmericanSocket);
std::shared_ptr<ChineseSocket> chineseSocket(new ChineseSocket);

std::shared_ptr<Adapter> adapter(new Adapter(chineseSocket.get(), americanSocket.get()));

UserAmericanPlug(americanSocket.get());
UseChinesePlug(chineseSocket.get());

UserAmericanPlug(adapter.get());
UseChinesePlug(adapter.get());

void AppDelegate::UseChinesePlug(ChineseSocket* socket)
{
	socket->SetCurrentVoltag(220);
	std::cout << socket->ChineseSocketInput() << std::endl;
	socket->DoWork();
	std::cout << std::endl;
}
```

1. 智能指针，引用计数的方式管理内存
2. 分别展现正常情况下和适配器情况下使用的情况
3. 针对不同的接口会设定不同的电压，而适配器会根据电压和接口进行适配

## 修改

```cpp
void Adapter::SetCurrentVoltag(int voltag)
{
	if (m_AmericanSocket != nullptr && m_AmericanSocket->GetRatedVoltag() != voltag)
	{
		m_AmericanSocket->SetCurrentVoltag(voltag);
	}
	if (m_ChineseSocket != nullptr && m_ChineseSocket->GetRatedVoltag() != voltag)
	{
		m_ChineseSocket->SetCurrentVoltag(voltag);
	}
}

```

- 修改`SetCurrentVoltag`方法的实现，之前的实现方式修改的是适配器的电压数值，并没有实际就改到`Socket`插头的电压数值，所以之前的写法是个BUG

```cpp
std::string Adapter::ChineseSocketInput() const
{
	if (m_AmericanSocket == nullptr)
	{
		return "Error : No Sockeet Input";
	}
	return this->m_AmericanSocket->AmericanSocketInput();
}
```

- 对于初始值为`nullptr`的指针进行操作的时候判断是否为空，做防御式编程

```cpp
std::shared_ptr<AmericanSocket> americanSocket = std::make_shared<AmericanSocket>();
std::shared_ptr<ChineseSocket> chineseSocket = std::make_shared<ChineseSocket>();

std::shared_ptr<Adapter> adapter = std::make_shared<Adapter>(chineseSocket.get(), americanSocket.get());
```

- 修改`shared_ptr`的创建方式，改用`make_shared`的方式进行创建