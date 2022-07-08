#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <map>
#include "day4.h"
#include "md5.h"



namespace day4
{
    int a(void) {
        std::string key = "iwrupvqb";
        uint32_t num = 0;
        
        // std::cout << "test" << std::endl;
        while(num < UINT32_MAX){
            std::string res = md5(key + std::to_string(num));
            // std::cout << num << std::endl;
            if (res.rfind("00000", 0) == 0)
                return num;
            num++;
        }
        return -1;
    }
    int b(void) {
        std::string key = "iwrupvqb";
        uint32_t num = 0;
        
        // std::cout << "test" << std::endl;
        while(num < UINT32_MAX){
            std::string res = md5(key + std::to_string(num));
            // std::cout << num << std::endl;
            if (res.rfind("000000", 0) == 0)
                return num;
            num++;
        }
        return -1;
    }
}