//
// Created by dro on 25.06.18.
//

#include "ipaddr.h"

std::ostream& operator<<(std::ostream& stream, const addr_t& addr) {
    for ( auto& a : addr){
        stream << a ;
        if (&a != &addr.back()){
            stream << '.';
        }
    }
    return stream;
}

std::istream& operator>>(std::istream& stream, addr_t& addr) {
    bool ok = true;

    std::string word;
    std::stringstream ss;
    stream >> word;
    ss << word;

    for (auto& a : addr){
        ok = ok && (ss >> a);
        if (&a != &addr.back()){
            ok = ok && (ss.peek() == '.');
            ss.ignore(1);
        }
    }

    if (!ok) {
        throw std::logic_error("Wrong ip addr format: "+word ); //Need add wrong date string
    }

    return stream;
}