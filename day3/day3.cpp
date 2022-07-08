#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <map>
#include "day3.h"




namespace day3
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

    int a(void) {
        std::ifstream t("day3/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;
        buffer << t.rdbuf();
        std::map<Coordinate, int> grid;
        int x = 0, y = 0;
        grid[Coordinate{x,y}] = 1;
        for(char c: buffer.str()){
            switch(c){
                case '<':
                    x--;
                    break;
                case '>':
                    x++;
                    break;
                case '^':
                    y++;
                    break;
                case 'v':
                    y--;
                    break;
            }
            // std::cout << "x: " << x << ", y: " << y << "\n";
            Coordinate coord = Coordinate{.x=x,.y=y};
            if (grid.find(coord) == grid.end())
                grid[coord] = 0; // doesn't exist, assign
            grid[coord]++;
        }
        return grid.size();
    }
    int b(void) {
        std::ifstream t("day3/input");
        if (!t){
            std::cout << "File not found!";
            return 1;
        }
        std::stringstream buffer;
        buffer << t.rdbuf();
        std::map<Coordinate, int> grid;
        grid[Coordinate{0,0}] = 1;
        Coordinate coord_santa = Coordinate{0,0};
        Coordinate coord_robo = Coordinate{0,0};
        bool turn = false;
        for(char c: buffer.str()){
            turn = !turn;
            Coordinate *coord = turn?(&coord_santa):(&coord_robo);
            switch(c){
                case '<':
                    coord->x--;
                    break;
                case '>':
                    coord->x++;
                    break;
                case '^':
                    coord->y++;
                    break;
                case 'v':
                    coord->y--;
                    break;
            }
            // std::cout << "x: " << x << ", y: " << y << "\n";
            if (grid.find(*coord) == grid.end())
                grid[*coord] = 0; // doesn't exist, assign
            grid[*coord]++;
        }
        return grid.size();
    }
}