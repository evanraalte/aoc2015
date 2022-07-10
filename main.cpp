#include <iostream>
#include <string>
#include <day1.h>
#include <day2.h>
#include <day3.h>
#include <day4.h>
#include <day5.h>
#include <day6.h>

int main(int argc, char** argv){
    if(argc != 2){
        std::cout << "Error: Invalid numner of arguments\n";
        return 1;
    }
    int day_num = 0;
    try {
        day_num = std::stoi(argv[1]);
    }
    catch(std::invalid_argument){
        std::cout << "Error: Argument must be an integer\n";
        return 1;
    }
    std::cout << "Running day " << day_num << "\n";

    switch(day_num){
        case 1:
            std::cout << "day1::a() = " << day1::a() << "\n";
            std::cout << "day1::b() = " << day1::b() << "\n";
            break;
        case 2:
            std::cout << "day2::a() = " << day2::a() << "\n";
            std::cout << "day2::b() = " << day2::b() << "\n";
            break;
        case 3:
            std::cout << "day3::a() = " << day3::a() << "\n";
            std::cout << "day3::b() = " << day3::b() << "\n";
            break;
        case 4:
            std::cout << "day4::a() = " << day4::a() << "\n";
            std::cout << "day4::b() = " << day4::b() << "\n";
            break;
        case 5:
            std::cout << "day5::a() = " << day5::a() << "\n";
            std::cout << "day5::b() = " << day5::b() << "\n";
            break;
        case 6:
            std::cout << "day6::a() = " << day6::a() << "\n";
            std::cout << "day6::b() = " << day6::b() << "\n";
            break;
        default:
            std::cout << "Not implemented\n";

    }
    return 0;
}