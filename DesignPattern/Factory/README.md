<!--
 * @Version: 
 * @Autor: LC
 * @Date: 2021-11-30 15:04:26
 * @LastEditors: LC
 * @LastEditTime: 2021-11-30 15:20:33
 * @Description: 工厂模式
-->
# 工厂模式

## 工厂方法

Transport为传输基类，有空运、水运、陆运三个子类，传输类维护一个`std::vector<BaseFurniture*> m_transports`数组来添加/删除需要运输的家具  
因为可以运输不同种类的家具，所以家具需要一个统一的家具基类，可以保证未来添加新的家具也可以被传输类使用  
最后所有的传输类交给`TransportCreateFactory`简单工厂使用，简单工厂维护一个`std::map<std::string, TransportFactory*>`映射表以此来方便的创建不同的运输方式

## 抽象工厂

家具分为A、B、C三种风格，又分为桌子、椅子、沙发三种家具，所以使用抽线工厂，可以生成同种类型的不同家具  
有为了保证运输类的开闭原则，所以所以的家具都有一个父类`BaseFurniture`  
A、B、C三种工厂交给`FurnitureCreateFactory`简单工厂使用，简单工厂维护一个`std::map<std::string, FurnitureFactory*>`映射表，来方便的创建家具对象

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

`InitTransportCreateFactory()` 初始化所有运输工厂

`InitFurnitureCreateFactory()` 初始化所有家具工厂