/*
 * @Autor: LC
 * @Date: 2021-11-29 17:30:53
 * @LastEditors: LC
 * @Description: 运行主类
 * @LastEditTime: 2021-11-29 17:34:38
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include "FurnitureFactory.h"
#include "TransportFactory.h"
using namespace std;

// 直接运行方式
void Test() {
    auto landTransport = TransportCreateFactory::GetInstance().CreateTransport("Land");
    landTransport->AddFurniture(FurnitureCreateFactory::GetInstance().CreateChair("A", "1"));
    landTransport->AddFurniture(FurnitureCreateFactory::GetInstance().CreateSofa("A", "2"));
    landTransport->AddFurniture(FurnitureCreateFactory::GetInstance().CreateTable("B", "3"));
    landTransport->AddFurniture(FurnitureCreateFactory::GetInstance().CreateChair("B", "4"));
    landTransport->AddFurniture(FurnitureCreateFactory::GetInstance().CreateSofa("A", "5"));
    landTransport->AddFurniture(FurnitureCreateFactory::GetInstance().CreateTable("C", "6"));
    landTransport->AddFurniture(FurnitureCreateFactory::GetInstance().CreateSofa("C", "7"));

    landTransport->ShowTransportInfo();
    landTransport->ShowFurnitreInfo();
    landTransport->DoTransport();

    delete landTransport;
    landTransport = nullptr;
}

// 选择家具种类 椅子 桌子 沙发
BaseFurniture* SelectFurniture(const std::string &type)
{
    std::cout << std::string("Input Number Select Furniture : 1.Chair  2.Table  3.Sofa") << std::endl;
    int furnitureType = 1;
    cin >> furnitureType;
    std::cout << std::string("Input Furniture Name") << std::endl;
    std::string name{""};
    cin >> name;
    while (true) {
        switch (furnitureType)
        {
        case 1:
            return FurnitureCreateFactory::GetInstance().CreateChair(type, name);
            break;
        case 2:
            return FurnitureCreateFactory::GetInstance().CreateTable(type, name);
            break;
        case 3:
            return FurnitureCreateFactory::GetInstance().CreateSofa(type, name);
            break;
        default:
            std::cout << "Input Right Number" << std::endl;
            cin >> furnitureType;
            break;
        }
    }
}

// 选择家具风格 A、B、C
BaseFurniture* SelectTheme() {
    std::cout << std::string("Input Number Select Furniture Theme : 1.A  2.B  3.C") << std::endl;
    int furnitureType = 1;
    while (true) {
        cin >> furnitureType;
        switch (furnitureType)
        {
        case 1:
            return SelectFurniture( "A");
            break;
        case 2:
            return SelectFurniture( "B");
            break;
        case 3:
            return SelectFurniture( "C");
            break;
        default:
            std::cout << "Input Right Number" << std::endl;
            break;
        }
    }
}

bool IsQuitTransport() {
    std::cout << std::string("Input Number, Stop Add Furniture : 0.Stop  1.Continue") << std::endl;
    int furnitureType = 1;
    cin >> furnitureType;
    return furnitureType == 0;
}

// 选择传输方式 陆路 水路 空运
void SelectTranportOnce() {

    int transportType = 0;
    std::cout << std::string("Input Number Select Transport : 1.Land  2.Liquid  3.Air") << std::endl;
    BaseTransport* tranportObj = nullptr;
    bool isInputFalse{ false };
    do{
        isInputFalse = false;
        cin >> transportType;
        switch (transportType)
        {
        case 1:
            tranportObj = TransportCreateFactory::GetInstance().CreateTransport("Land");
            break;
        case 2:
            tranportObj = TransportCreateFactory::GetInstance().CreateTransport("Liquid");
            break;
        case 3:
            tranportObj = TransportCreateFactory::GetInstance().CreateTransport("Air");
            break;
        default:
            std::cout << "Please Input Right Number " << std::endl;
            isInputFalse = true;
            break;
        }
    } while (isInputFalse);
    bool isQuit = false;
    do
    {
        tranportObj->AddFurniture(SelectTheme());
        system("cls");
        tranportObj->ShowTransportInfo();
        tranportObj->ShowFurnitreInfo();
        cout << std::endl;
        isQuit = IsQuitTransport();
    } while (!isQuit);

    system("cls");
    tranportObj->ShowTransportInfo();
    tranportObj->ShowFurnitreInfo();
    tranportObj->DoTransport();
}

bool IsQuitInteraction() {
    std::cout << std::string("Input Number To Quit : 0.Quit  1.Continue") << std::endl;
    int furnitureType = 1;
    cin >> furnitureType;
    return furnitureType == 0;
}
// 交互方式
void Interaction() {
    bool isQuit = false;
    do {
        SelectTranportOnce();
        isQuit = IsQuitInteraction();
    } while (!isQuit);
}

int main(int argv, char *args[])
{
    Interaction();  // 交互方式
    //Test(); // 直接运行方式
    system("pause");
    return 0;
}