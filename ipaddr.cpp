//
// Created by dro on 25.06.18.
//

#include "ipaddr.h"

addr_t::addr_t (const std::array<uint8_t, 4>& arr ) {
    for (const auto& a : arr){
        if (0 <= (uint8_t)a <= 255){
            addr_ = addr_ << 8 | (unsigned)a ;
        } else {
            throw std::logic_error("Wrong ip addr number" ); //Need add wrong date string
        }
    }
}

addr_t::addr_t(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
    if ((0 <= (unsigned)a <= 255) && (0 <= (unsigned)b <= 255) &&
        (0 <= (unsigned)c <= 255) && (0 <= (unsigned)d <= 255)) {
        addr_ = ((unsigned)a << 24) | ((unsigned)b << 16) | ((unsigned)c << 8) | (unsigned)d;
    } else {
        throw std::logic_error("Wrong ip addr number"); // add wrong addr string
    }
}

unsigned long addr_t::get_raw() const {
    return addr_;
}

std::ostream& operator<<(std::ostream& stream, const addr_t& addr) {
    uint32_t addr_raw = addr.get_raw();
    for (size_t i=0; i<4; i++) {
        size_t j=3-i;
        stream << (unsigned)(( addr_raw >> (j*8) ) & 0xFF);
        if (i < 3) {
            stream << '.';
        }
    }
    return stream;
}

std::istream& operator>>(std::istream& stream, addr_t& addr) {
    bool ok = true;
    std::array<uint8_t, 4> arr;
    std::string word;
    std::stringstream ss;
    stream >> word;
    ss << word;
    for (auto& a : arr){
        uint16_t tmp;
        ok = ok && (ss >> tmp);
        if (tmp > 255){
            throw std::logic_error("Wrong ip addr format: "+word );
        }
        a = tmp & 0xFF;
        if (&a != &arr.back()){
            ok = ok && (ss.peek() == '.');
            ss.ignore(1);
        }
    }
    addr = addr_t(arr);
    if (!ok) {
        throw std::logic_error("Wrong ip addr format: "+word ); //wrong date string
    }
    return stream;
}

bool operator== (const addr_t& lhs, const addr_t& rhs){
    return lhs.get_raw() == rhs.get_raw();
}

bool operator< (const addr_t& lhs, const addr_t& rhs){
    return lhs.get_raw() < rhs.get_raw();
}

bool operator<= (const addr_t& lhs, const addr_t& rhs){
    return lhs < rhs || lhs == rhs;
}

bool operator> (const addr_t& lhs, const addr_t& rhs){
    return lhs.get_raw() > rhs.get_raw();
}

bool operator>= (const addr_t& lhs, const addr_t& rhs){
    return lhs > rhs || lhs == rhs;
}

bool compare_by_mask(const addr_t& lhs, const addr_t& rhs, const addr_t& mask){
    uint32_t lhs_raw_by_mask = lhs.get_raw()&mask.get_raw();
    uint32_t rhs_raw_by_mask = rhs.get_raw()&mask.get_raw();
    return lhs_raw_by_mask == rhs_raw_by_mask;
}