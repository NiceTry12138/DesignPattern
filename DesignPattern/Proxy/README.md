<!--
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-06 17:03:22
 * @LastEditors: LC
 * @LastEditTime: 2021-12-06 18:04:54
 * @Description: 代理模式
-->

# 代理模式

## 目标

1. 使用智能指针管理对象
2. 包含代理模式应用场景
   - 延迟初始化
   - 数据缓存
   - 权限控制 (对某些参数做一些判断等等)

## 实现

- 添加增删改查功能

```cpp
class Number {
public:
    virtual std::pair<bool, int> generate(std::string animal) = 0;
    virtual void Update(std::string _key, int _val) = 0;
    virtual void Remove(std::string _key) = 0;
    virtual void Add(std::string _key, int _val) = 0;
    virtual void ShowInfo() const = 0;
    virtual ~Number() = default;
};
```

> 这里对`generate`函数返回值类型进行修改，用**bool**变量表示是否查找到，防止表中value的值也为0从而出现含义不明的问题

- 代理对象`ProxyNumber`组合了`LuckyNumber`对象，针对`LuckyNumber`应该是只存在单独一例，所以使用`unique_ptr`

```cpp
std::unique_ptr<Number> m_Number{ nullptr };
```

- 用户分为两种，一种是管理员`Admin`，另一种是普通用户`CONSUMER`

```cpp
enum class USER {
	CONSUMER,		// 普通用户
	ADMIN			// 管理员
};

// 构造函数
NumberProxy::NumberProxy(USER _user, const std::string& _name) : m_USER(_user), m_UserName(_name)
{
}

// 权限控制
bool NumberProxy::IsLegalRequest(const std::string& _key)
{
	if (m_USER == USER::ADMIN)
	{
		return true;
	}
	else if (_key == m_UserName) {
		return true;
	}
	return false;
}
```

> 在`ProxyNumber`创建的时候需要传入用户的权限以及用户名，方便后续进行权限处理  
> 管理员在使用`ProxyNumber`时默认拥有全部权限，而普通用户在使用的时候需要判断他要操作的数据是否是**自身数据**（普通用户只能操作自身数据）  

- 延迟初始化，只在需要调用`LuckyNumber`的时候创建对象

```cpp
void NumberProxy::InitNumber()
{
	if (m_Number.get() == nullptr)
	{
		m_Number.reset(new LuckyNumber());
	}
}
```

- 数据缓存

```cpp
std::list<std::pair<std::string, int>> m_Cache;

void NumberProxy::AddCache(const std::string& _key, const int& _val)
{
	if (m_Cache.size() >= g_CacheMaxNumber)
	{
		m_Cache.erase(m_Cache.begin());
	}

	m_Cache.push_back(std::make_pair(_key, _val));
}
```

维护缓存列表，缓存有一个数量上限，超过上限的时候使用**最久未使用**调度算法，将链表头部的节点从缓存中删除，当某个缓存节点被调用时将这个节点移动至链表的最后  
只有调用`generate`方法才会将数据添加到缓存当中  

## 运行

1. 创建管理员用户的代理，对数据进行增删改查，所有数据处理不会权限错误，并且对`generate`方法请求到的数据进行缓存

```cpp
auto number = std::make_unique<NumberProxy>(USER::ADMIN, "");

auto ratNumber = number->generate("Rat");
std::cout << ratNumber << std::endl;

auto horseNumber = number->generate("Horse");
std::cout << horseNumber << std::endl;

number->Remove("Horse");

number->Add("Dragon", 3521);
number->Update("Rat", 1920);
```

2. 创建普通用户，对数据进行增删改查，对名字不叫`normal`的数据进行操作会报权限错误，并且不会对数据做修改；只有处理名为`normal`的数据时才会成功

```cpp
auto number_normal = std::make_unique<NumberProxy>(USER::CONSUMER, "normal");

auto ratNumber_normal = number_normal->generate("Rat");	// ERROR : Normal User Can Only Request Yourself Data!
std::cout << ratNumber_normal << std::endl;

auto normal_number = number_normal->generate("normal");
std::cout << normal_number << std::endl;

ShowInfo(number_normal.get());

number_normal->Add("normal", 3521);
number_normal->Update("normal", 1920);
```

## 修改