#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <stdexcept>
#include <algorithm>
#include <list>
#include "day2.h"

namespace day2
{
    int a(void) {
        std::ifstream t("day2/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;
        std::string line;
        buffer << t.rdbuf(); 
        std::regex rgx("(\\d+)x(\\d+)x(\\d+)");
        uint32_t surface = 0;
        while (std::getline(buffer, line)) {
            // std::cout << line << std::endl;
            std::smatch matches;
            if(std::regex_search(line, matches, rgx) && matches.size() == 4){
                uint32_t l = stoi(matches[1].str());
                uint32_t w = stoi(matches[2].str());
                uint32_t h = stoi(matches[3].str());
                // std::cout << "l: " << l << ", w: " << w << ", h: " << h << "\n";
                surface += (2*l*w + 2*w*h + 2*h*l) + std::min({l*w,w*h,h*l});
            } else {
                throw std::invalid_argument( "invalid line!");
            }
        }

        return surface;
    }
    int b(void) {
        std::ifstream t("day2/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;//("2x3x4\n");
        std::string line;
        buffer << t.rdbuf(); 
        std::regex rgx("(\\d+)x(\\d+)x(\\d+)");
        uint32_t length = 0;
        while (std::getline(buffer, line)) {
            // std::cout << line << std::endl;
            std::smatch matches;
            if(std::regex_search(line, matches, rgx) && matches.size() == 4){
                uint32_t l = stoi(matches[1].str());
                uint32_t w = stoi(matches[2].str());
                uint32_t h = stoi(matches[3].str());
                // std::cout << "l: " << l << ", w: " << w << ", h: " << h << "\n";
                std::list<uint32_t> list = {l,w,h};
                list.sort();
                auto it = list.begin();
                auto l1 = *it;
                auto l2 = *std::next(it);
                // std::cout << "l1: " << l1 << ", l2: " << l2 << "\n";
                length += l*w*h + 2*l1 + 2*l2;
            } else {
                throw std::invalid_argument( "invalid line!");
            }
        }

        return length;
    }
}