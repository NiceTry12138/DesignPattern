#include "NumberProxy.h"
#include <iostream>
#include <memory>

void ShowInfo(NumberProxy* number){
    number->ShowInfo();
    number->ShowCache();

    //std::cout << "***************************" << std::endl;
}

int main()
{
    //for (int i = 0; i < 120; i++) {
    //    std::cout << "-";
    //}
    //std::cout << std::endl;

    auto number = std::make_unique<NumberProxy>(USER::ADMIN, "");

    ShowInfo(number.get());

    auto ratNumber = number->generate("Rat");
    std::cout << (ratNumber.first ? "find " : "not find ") << ratNumber.second << std::endl;

    auto horseNumber = number->generate("Horse");
    std::cout << (horseNumber.first ? "find " : "not find ") << horseNumber.second << std::endl;

    ShowInfo(number.get());

    number->Remove("Horse");

    number->Add("Dragon", 3521);
    number->Update("Rat", 1920);

    ShowInfo(number.get());

    /////////////////////////////////////////////////////////////////

    for (int i = 0; i < 120; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;

    auto number_normal = std::make_unique<NumberProxy>(USER::CONSUMER, "normal");

    ShowInfo(number_normal.get());

    auto ratNumber_normal = number_normal->generate("Rat");
    std::cout << (ratNumber_normal.first ? "find " : "not find ") << ratNumber_normal.second << std::endl;

    auto normal_number = number_normal->generate("normal");
    std::cout << (normal_number.first ? "find " : "not find ") << normal_number.second << std::endl;

    ShowInfo(number_normal.get());

    number_normal->Add("normal", 3521);
    number_normal->Update("normal", 1920);

    ShowInfo(number_normal.get());


    return 0;
}
