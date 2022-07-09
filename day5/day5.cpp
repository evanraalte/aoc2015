#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <map>
#include "day5.h"

namespace day5
{
    int a(void) {
        std::ifstream t("day5/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;
        std::string line;
        buffer << t.rdbuf(); 

        std::regex three_vowels(".*?[aeoiu].*?[aeoiu].*?[aeoiu].*?");
        std::regex twice_in_row(R"(([a-z])\1)");
        std::regex illegal_pattern("ab|cd|pq|xy");
        std::smatch matches;
        int nice_strings = 0;
        while (std::getline(buffer, line)) {
            bool match_three_vowels = std::regex_search(line, matches, three_vowels);
            bool match_twice_in_row = std::regex_search(line, matches, twice_in_row);
            bool match_illegal_pattern = std::regex_search(line, matches,  illegal_pattern);
            if(match_three_vowels && match_twice_in_row && !match_illegal_pattern){
                nice_strings++;
            }

        }
        return nice_strings;
    }
    int b(void) {
        std::ifstream t("day5/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;
        std::string line;
        buffer << t.rdbuf(); 

        std::regex pair_appears_twice(R"(([a-z][a-z]).*\1)");
        std::regex repeat_letter_between(R"(([a-z])[a-z]\1)");
        std::smatch matches;
        int nice_strings = 0;
        while (std::getline(buffer, line)) {
            bool match_pair_appears_twice = std::regex_search(line, matches, pair_appears_twice);
            bool match_repeat_letter_between = std::regex_search(line, matches, repeat_letter_between);
            if(match_pair_appears_twice && match_repeat_letter_between){
                nice_strings++;
            }

        }
        return nice_strings;
    }
}