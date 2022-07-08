#include <iostream>
#include <fstream>
#include <sstream>
#include "day1.h"

namespace day1
{
    int a(void) {
        std::ifstream t("day1/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;
        buffer << t.rdbuf();
        int floor = 0;
        for(char c: buffer.str()){
            if (c == '(')
                floor++;
            else
                floor--;
        }

        return floor;
    }
    int b(void) {
        std::ifstream t("day1/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;
        buffer << t.rdbuf();
        int floor = 0;
        int cnt = 1;
        for(char c: buffer.str()){
            if (c == '(')
                floor++;
            else
                floor--;

            if (floor == -1)
                return cnt;
            cnt++;       
        }
        return -1;
    }
}