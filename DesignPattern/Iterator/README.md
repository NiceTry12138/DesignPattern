<!--
 * @Version: 
 * @Autor: LC
 * @Date: 2021-12-06 17:03:22
 * @LastEditors: LC
 * @LastEditTime: 2021-12-09 16:32:37
 * @Description: 迭代器模式
-->

# 迭代器模式

## 目标

- 需要有两个类：迭代器类和容器类
- 容器类类需要添加 begin() 与 end() 方法，并返回合适的迭代器
- 迭代器类需要实现运算符重载：  
➢ operator*  
➢ operator!=  
➢ operator++  

## 实现

1. 容器类

- 普通数组容器，通过构造函数确定数量，提供设置指定坐标值、获得指定坐标值、末尾添加的功能，提供正向迭代器和反向迭代器

```cpp
class MyBaseDocker
{
public:
	MyBaseDocker(size_t size);
	virtual ~MyBaseDocker();
	MyDockerIterator<T> begin();
	MyDockerIterator<T> end();

	MyDockerIterator<T> rbegin();
	MyDockerIterator<T> rend();
	
	int GetCurrentSize();
	int GetMaxSize();

	void AddItem(T _val);
	void Clear();
	T at(int _index);
	void SetVal(int _pos, const T& _val);

private:
	T* m_Items{ nullptr };
	int m_MaxSize{ 0 };
	int m_CurrentSize{ 0 };

};
```

- 链表容器，提供末尾插入、末尾删除、当前容器大小，提供正向迭代器和反向迭代器

```cpp

template<typename T>
class MyList
{
public:
	MyList();
	virtual ~MyList();

	void push_back(const T &_val);
	T pop_back();

	size_t Size();

	MyListIterator<T> begin();
	MyListIterator<T> end();

	MyListIterator<T> rbegin();
	MyListIterator<T> rend();
protected:
	ListNode<T>* GetLastNode();

private:
	size_t m_Size{ 0 };
	ListNode<T>* m_head{ nullptr };
};
```

2. 迭代器

- 普通数组迭代器，判断当前是否迭代完成、往后迭代、往前迭代，根据是否是反向迭代器判断`++`和`--`操作的执行方式

```cpp
template<typename T>
class MyDockerIterator : public BaseIterator<T>
{
public:
	MyDockerIterator(MyBaseDocker<T> *_docker, int _cur, bool reverse = false);

	virtual void next() override;
	virtual void behind() override;
	T operator *();
	bool operator != (const MyDockerIterator<T> _other);
	MyDockerIterator<T>& operator ++ ();

	virtual bool isDone();

	void SetVal(const T& _val) override;

private:
	int m_startIndex;
	int m_cur{ 0 };
	MyBaseDocker<T>* m_Docker{ nullptr };
};
```

- 链表迭代器，判断迭代是否完成、往后迭代、往前迭代、根据是否是反向迭代器判断`++`和`--`操作的执行方式

```cpp
template<typename T>
class MyListIterator : public BaseIterator<T>
{
public:
	void next() override;
	void behind() override;
	bool isDone() override;

	MyListIterator(ListNode<T>* _node, ListNode<T>* _head, bool reverse = false) : m_Node(_node), m_Head(_head), BaseIterator<T>(reverse) {}

	T operator *();
	MyListIterator<T>& operator ++();
	MyListIterator<T>& operator --();
	bool operator !=(const MyListIterator<T>& _other);

	void SetVal(const T &_val) override;

private:
	ListNode<T>* m_Node;
	ListNode<T>* m_Head;

};
```

3. 正向、反向链表

通过设定参数来判断当前迭代方向，`++`和`--`对应做出不同的操作

```cpp
template<typename T>
inline MyListIterator<T>& MyListIterator<T>::operator++()
{
	if (BaseIterator<T>::ISReverse())
	{
		behind();
	}
	else {
		next();
	}
	return *this;
}
```

4. 双向链表

```cpp
template<typename T>
class ListNode
{
public:
	ListNode() : next(nullptr) ,behind(nullptr) {}
	ListNode(T data) : _data(data), next(nullptr), behind(nullptr) {}

	T _data;
	ListNode* next;
	ListNode* behind;
};
```

## 运行

- `my_find_if`自定义查找

```cpp
template<typename Iteartor, typename T>
Iteartor my_find_if(Iteartor _begin, Iteartor _end, T _val)
{
	for (auto _it = _begin; _it != _end; ++_it)
	{
		if ((*_it) == _val)
		{
			return _it;
		}
	}
}
```

- 普通数组的运行，插入、遍历、反向遍历、查找

```cpp
MyBaseDocker<int> doc(10);
doc.AddItem(1);
doc.AddItem(2);
doc.AddItem(3);
for (int val : doc) {
	std::cout << val << std::endl;
}

for (auto _begin = doc.rbegin(); _begin != doc.rend(); ++_begin) {
	std::cout << *_begin << std::endl;
}

std::cout << "find " << *my_find_if(doc.begin(), doc.end(), 3) << std::endl;
```

- 链表的运行测试，插入、遍历、反向遍历、查找

```cpp
MyList<int> mylist;
mylist.push_back(1);
mylist.push_back(2);
mylist.push_back(3);
mylist.push_back(4);

std::cout << "find " << *my_find_if(mylist.begin(), mylist.end(), 3) << std::endl;

for (auto val : mylist) {
	std::cout << val << std::endl;
}
for (auto _begin = mylist.rbegin(); _begin != mylist.rend(); ++_begin) {
	std::cout << *_begin << std::endl;
}
while (mylist.Size() > 0) {
	std::cout << mylist.pop_back() << std::endl;
}
```