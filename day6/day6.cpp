#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <map>
#include "day6.h"
#include <set>
namespace day6
{


    struct Coordinate{
        int x;
        int y;

        bool operator==(const Coordinate &o)  const {
            return x == o.x && y == o.y;
        }

        bool operator<(const Coordinate &o)  const {
            return x < o.x || (x == o.x && y < o.y);
        }
    };

    struct Compare {
        std::string str;
        Compare(const std::string& str) : str(str) {}
    };
    bool operator==(const std::pair<int, std::string>&p, const Compare& c) {
        return c.str == p.second;
    }
    bool operator==(const Compare& c, const std::pair<int, std::string>&p) {
        return c.str == p.second;
    }

    enum Command {turn_on, turn_off, toggle};

    int a(void) {
        std::ifstream t("day6/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;
        std::string line;
        buffer << t.rdbuf(); 
        std::regex rexp(R"((turn off|turn on|toggle) (\d+),(\d+) through (\d+),(\d+))");
        std::smatch matches;
        std::set<int> grid;
        while (std::getline(buffer, line)) {
            if(std::regex_search(line, matches, rexp)){
                std::string cmd_string = matches[1].str();
                Command cmd;
                if (cmd_string.compare("turn on") == 0){
                    cmd = turn_on;
                } else if (cmd_string.compare("turn off") == 0){
                    cmd = turn_off;
                } else if (cmd_string.compare("toggle") == 0){
                    cmd = toggle;
                }
                int x0 = stoi(matches[2].str());
                int y0 = stoi(matches[3].str());
                int x1 = stoi(matches[4].str());
                int y1 = stoi(matches[5].str());

                std::function<void(int, std::set<int>*)> f;
                switch(cmd){
                    case turn_on:
                        f = [](int c, std::set<int> *grid) {grid->insert(c);};
                        break;
                    case turn_off:
                        f = [](int c, std::set<int> *grid) {grid->erase(c);};
                        break;
                    case toggle:
                        f = [](int c, std::set<int> *grid) {
                            if (grid->count(c)>0){
                                grid->erase(c);
                            } else {
                                grid->insert(c);
                            }
                        };
                        break;
                }
                for(int x=x0; x <=x1; x++){
                    for(int y=y0; y <=y1; y++){
                        int c = x + 1000*y;
                        f(c,&grid);
                    }
                }
            } else {
                std::invalid_argument("Could not parse: " + line);
            }


        }
        return grid.size();
    }
    int b(void) {
        std::ifstream t("day6/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;
        std::string line;
        buffer << t.rdbuf(); 
        std::regex rexp(R"((turn off|turn on|toggle) (\d+),(\d+) through (\d+),(\d+))");
        std::smatch matches;
        std::map<Coordinate, int> grid;
        while (std::getline(buffer, line)) {
            if(std::regex_search(line, matches, rexp)){
                std::string cmd_string = matches[1].str();
                Command cmd;
                if (cmd_string.compare("turn on") == 0){
                    cmd = turn_on;
                } else if (cmd_string.compare("turn off") == 0){
                    cmd = turn_off;
                } else if (cmd_string.compare("toggle") == 0){
                    cmd = toggle;
                }
                int x0 = stoi(matches[2].str());
                int y0 = stoi(matches[3].str());
                int x1 = stoi(matches[4].str());
                int y1 = stoi(matches[5].str());

                for(int x=x0; x <=x1; x++){
                    for(int y=y0; y <=y1; y++){
                        if (cmd == turn_on){
                                grid[Coordinate{x,y}]++;
                        } else if (cmd == turn_off && grid[Coordinate{x,y}]>=1){
                                grid[Coordinate{x,y}]--;
                        } else if (cmd == toggle){
                                grid[Coordinate{x,y}] +=2;
                        }
                    }
                }
            } else {
                std::invalid_argument("Could not parse: " + line);
            }


        }
        auto count = 0;
        for (auto&& p : grid)
            count += p.second;
        return count;
    }
}