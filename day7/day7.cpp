#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <map>
#include "day7.h"
#include <set>
namespace day7
{

    void parse_line(std::string line, std::string *left, std::string *right){
        std::string delimiter = " -> ";
        size_t pos = line.find(delimiter);
        *left = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        *right = line.substr(0, pos);
    }

    bool is_number(const std::string& s)
    {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }

    bool try_get_number(const std::map<std::string, uint16_t> *wires, std::string value, uint16_t *result){
        if (is_number(value)){
            *result = stoi(value);
            return true;
        } else if(wires->find(value) != wires->end()){
            *result = wires->find(value)->second;
            return true;
        } else {
            return false;
        }
    }

    bool try_resolve(std::string left, std::string right, std::map<std::string, uint16_t> *wires){
        std::regex r_literal(R"(^([a-z\d]+)$)");
        std::regex r_not(R"(^NOT ([a-z\d]+)$)");
        std::regex r_other_op(R"(^([a-z\d]+) ([A-Z]+) ([a-z\d]+)$)");
        // std::cout << "resolving, left: " << left << ", right: " << right << std::endl;
        std::smatch matches;
        uint16_t p_left, p_right;
        if(std::regex_match(left, matches, r_literal)){
            std::string literal = matches[1].str();
            if (try_get_number(wires, literal, &p_right)){
                (*wires)[right] = p_right;
                return true;
            }
        } else if (std::regex_match(left, matches, r_not)){
            std::string literal = matches[1].str();
            if (try_get_number(wires, literal, &p_right)){
                (*wires)[right] = ~p_right;
                return true;
            }
        } else if (std::regex_match(left, matches, r_other_op)){
            std::string op_left = matches[1].str();
            std::string operation = matches[2].str();
            std::string op_right = matches[3].str();
            if (try_get_number(wires, op_left, &p_left) && try_get_number(wires, op_right, &p_right)){
                if(operation.compare("LSHIFT") == 0){
                    (*wires)[right] = p_left << p_right;
                }
                if(operation.compare("RSHIFT") == 0){
                    (*wires)[right] = p_left >> p_right;
                }
                if(operation.compare("AND") == 0){
                    (*wires)[right] = p_left & p_right;
                }
                if(operation.compare("OR") == 0){
                    (*wires)[right] = p_left | p_right;
                }
                return true;
            }
        }
        return 0;
    }

    int a(void) {
        std::ifstream t("day7/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;
        std::string line;
        buffer << t.rdbuf(); 
        std::map<std::string, uint16_t> wires;
        std::map<std::string, std::string> todo;
        while (std::getline(buffer, line)) {
            std::string left, right;
            parse_line(line, &left, &right);
            // std::cout << "left: " <<  left << ", right: " << right << std::endl;
            todo[left] = right;
        }
        while(wires.find("a") == wires.end()){
            std::set<std::string> to_remove;
            for (auto const& x : todo){
                if(try_resolve(x.first, x.second,&wires)){
                    to_remove.insert(x.first);
                }
            }
            for(auto const&x : to_remove){
                todo.erase(x);
            }
        }
        return wires.find("a")->second;
    }
    int b(void) {
        std::ifstream t("day7/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;
        std::string line;
        buffer << t.rdbuf(); 
        std::map<std::string, uint16_t> wires;
        std::map<std::string, std::string> todo;
        while (std::getline(buffer, line)) {
            std::string left, right;

            parse_line(line, &left, &right);
            if(right.compare("b") == 0){
                left = "3176";
            }
            todo[left] = right;
        }
        while(wires.find("a") == wires.end()){
            std::set<std::string> to_remove;
            for (auto const& x : todo){
                if(try_resolve(x.first, x.second,&wires)){
                    to_remove.insert(x.first);
                }
            }
            for(auto const&x : to_remove){
                todo.erase(x);
            }
        }
        return wires.find("a")->second;
    }
}