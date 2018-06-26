#include <iostream>
#include <set>
#include "ipaddr.h"

int main() {
    std::set<addr_t> db;
    std::string line;
    while (std::getline(std::cin, line)){
        std::stringstream ss(line);
        addr_t addr;
        ss >> addr;
        db.insert(addr);
    }
    for (const auto& a : db){
        std::cout << a << std::endl;
    }
}