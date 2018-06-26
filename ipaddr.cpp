//
// Created by dro on 25.06.18.
//

#include "ipaddr.h"

unsigned long addr_t::get_raw() const {
    return addr_;
}

std::ostream& operator<<(std::ostream& stream, const addr_t& addr) {
    for (size_t i = 0; i < sizeof(addr); ++i) {
        size_t  j=sizeof(addr)-i-1;
        unsigned char byte = *((unsigned char *) &addr + j);
        stream << (unsigned) byte;
        if (i < sizeof(addr) - 1) {
            stream << '.';
        }
    }
    return stream;
}

std::istream& operator>>(std::istream& stream, addr_t& addr) {
    bool ok = true;
    std::array<uint16_t, 4> arr;
    std::string word;
    std::stringstream ss;
    stream >> word;
    ss << word;

    for (auto& a : arr){
        ok = ok && (ss >> a);
        if (&a != &arr.back()){
            ok = ok && (ss.peek() == '.');
            ss.ignore(1);
        }
    }
    addr = addr_t(arr);
    if (!ok) {
        throw std::logic_error("Wrong ip addr format: "+word ); //Need add wrong date string
    }
    return stream;
}

bool operator== (const addr_t& lhs, const addr_t& rhs){
    return lhs.get_raw() == rhs.get_raw();
}

bool operator> (const addr_t& lhs, const addr_t& rhs){
    return lhs.get_raw() < rhs.get_raw();
}

bool operator< (const addr_t& lhs, const addr_t& rhs){
    return lhs.get_raw() > rhs.get_raw();
}