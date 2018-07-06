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
}