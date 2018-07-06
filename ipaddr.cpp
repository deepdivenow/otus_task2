//
// Created by dro on 25.06.18.
//

#include "ipaddr.h"

addr_t::addr_t (const std::array<uint16_t, 4>& arr ) {
    for (const auto& a : arr){
        if (0 <= a <= 255){
            addr_ = addr_ << 8 | a ;
        } else {
            throw std::logic_error("Wrong ip addr number" ); //Need add wrong date string
        }
    }
}

addr_t::addr_t(uint16_t a, uint16_t b, uint16_t c, uint16_t d) {
    if ((0 <= a <= 255) && (0 <= b <= 255) &&
        (0 <= c <= 255) && (0 <= d <= 255)) {
        addr_ = (a << 24) | (b << 16) | (c << 8) | d;
    } else {
        throw std::logic_error("Wrong ip addr number"); // add wrong addr string
    }
}

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

bool operator< (const addr_t& lhs, const addr_t& rhs){
    return lhs.get_raw() < rhs.get_raw();
}

bool operator> (const addr_t& lhs, const addr_t& rhs){
    return lhs.get_raw() > rhs.get_raw();
}

//    addr_t& operator= (const addr_t& addr){
//        return *this;
//    }
//    addr_t& operator= (addr_t&& addr){
//        std::swap(addr_,addr.addr_);
//        return *this;
//    }

//    xray &operator=(xray &&rhs) noexcept {
//        x.swap(rhs.x);
//        std::cout << "move assign from " << rhs.x << " to " << x << std::endl;
//        return *this;
//    }