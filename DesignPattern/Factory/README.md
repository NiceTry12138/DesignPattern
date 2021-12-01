<!--
 * @Version: 
 * @Autor: LC
 * @Date: 2021-11-30 15:04:26
 * @LastEditors: LC
 * @LastEditTime: 2021-12-01 12:09:56
 * @Description: 工厂模式
-->
# 工厂模式

## 工厂方法

Transport为传输基类，有空运、水运、陆运三个子类，传输类维护一个`std::vector<BaseFurniture*> m_transports`数组来添加/删除需要运输的家具  
因为可以运输不同种类的家具，所以家具需要一个统一的家具基类，可以保证未来添加新的家具也可以被传输类使用  
最后所有的传输类交给`TransportCreateFactory`简单工厂使用，简单工厂维护一个`std::map<std::string, TransportFactory*>`映射表以此来方便的创建不同的运输方式

```cpp
class TransportCreateFactory {
public:
	static TransportCreateFactory& GetInstance();

public:
	void AddTransportFactory(std::string key, TransportFactory* factory);
	BaseTransport* CreateTransport(const std::string key);
	~TransportCreateFactory();
	TransportCreateFactory(const TransportCreateFactory&) = delete;    // 不允许拷贝构造
	TransportCreateFactory& operator=(const TransportCreateFactory&) = delete;
private:
	TransportCreateFactory() = default;

	std::map<std::string, TransportFactory*> m_factories;
};
```

> 管理运输工厂的类使用单例模式进行使用  
> 使用`delelte`删除拷贝构造和赋值构造，防止TransportCreateFactory被手动创建  
> 在private作用域定义构造函数的方式防止TransportCreateFactory被手动创建  

## 抽象工厂

家具分为A、B、C三种风格，又分为桌子、椅子、沙发三种家具，所以使用抽象工厂，可以生成同种类型的不同家具  
有为了保证运输类的开闭原则，所以所以的家具都有一个父类`BaseFurniture`  
A、B、C三种工厂交给`FurnitureCreateFactory`简单工厂使用，简单工厂维护一个`std::map<std::string, FurnitureFactory*>`映射表，来方便的创建家具对象

```cpp
// 家具工厂基类
class FurnitureFactory {
public:
	FurnitureFactory(const std::string& name) : m_name(name) {
		FurnitureCreateFactory::GetInstance().AddFurnitureFactory(name, this);
	}
private:
	std::string m_name;
};

// 家具A类工厂
class Factory_A : public FurnitureFactory {
public:
	Factory_A() : FurnitureFactory("A") {}

private:
	static Factory_A _self;
};
```

> 此处家具A类工厂通过构造函数和static的变量，来保证系统启动的时候即可通过父类的构造函数自动注册到FurnitureCreateFactory的单例对象中  
> 同理TransportCreateFactory也通过这种方式来自动注册家具工厂对象  

## main方法

```cpp
int main(int argv, char *args[])
{
    Interaction();  // 交互方式
    //Test(); // 直接运行方式
    system("pause");
    return 0;
}
```

`Interaction()`交互方法分三层  

1. 选择运输模式`SelectTranportOnce`： 1.陆路 2.水路 3.空运
2. 选择家具风格`SelectTheme`：1.A 2.B 3.C
3. 选择家具种类`SelectFurniture`：1.椅子 2.桌子 3.沙发 并且设置家具的名称

在选择完家具种类后，可以输入0来开始配送，也可以输入1来继续添加其他家具  
在一次配送完毕后，可以输入0来退出程序，也可以输入1来继续其他方式的配送

`Test()` 为直接测试模式，运行直接出指定结果  

`InitTransportCreateFactory()` 初始化所有运输工厂，**在本版本中被删除**，因为所有工厂都是自动注册无需手动注册

`InitFurnitureCreateFactory()` 初始化所有家具工厂，**在本版本中被删除**，因为所有工厂都是自动注册无需手动注册  

因为所有的工厂和创建工厂的工厂都是static对象，所以无需使用`delete`/`new`来管理对象内存，也不用担心这几个类的内存泄露，但是实体类的对象是`new`创建出来的，所以实体类依旧需要进行内存管理  