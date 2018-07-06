#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include "ipaddr.h"

int main() {
    std::vector<addr_t> db;
//    std::set<addr_t> db;
    std::string line;
    while (std::getline(std::cin, line)){
        std::stringstream ss(line);
        addr_t addr;
        ss >> addr;
        db.emplace_back(std::move(addr));
    }
    std::sort(db.begin(),db.end(),
              [](const addr_t& a,const addr_t& b){return a>b;});

    //Or we can do it like this:
    //std::sort(db.rbegin(),db.rend());

    for (const auto& a : db){
        std::cout << a << std::endl;
    }
    {
        addr_t c{46,70,0,0};
        addr_t mask{255,255,0,0};
        for (const auto& a : db){
            auto hash=a.get_raw()&mask.get_raw();
            if (hash == c.get_raw()) {
                std::cout << a << std::endl;
            }
        }

    }
    {
        uint16_t num = 46;
        std::vector<addr_t> c{{num,0,0,0},{0,num,0,0},{0,0,num,0},{0,0,0,num}};
        std::vector<addr_t> mask{{255,0,0,0},{0,255,0,0},{0,0,255,0},{0,0,0,255}};
        for (const auto& a : db){
            for (size_t i=0;i<4;i++) {
                uint32_t hash=a.get_raw()&mask[i].get_raw();
                if (hash == c[i].get_raw()) {
                    std::cout << a << std::endl;
                    break;
                }
            }
        }
    }
}