//
// Created by dro on 25.06.18.
//
#pragma once
#include <cstdint>
#include <array>
#include <iostream>
#include <sstream>

//using addr_t = std::array<uint16_t, 4> ;

class addr_t{
public:
    addr_t () {}
    addr_t (const std::array<uint16_t, 4>& arr ) {
        for (const auto& a : arr){
            if (0 <= a <= 255){
                addr_ = addr_ << 8 | a ;
            } else {
                throw std::logic_error("Wrong ip addr number" ); //Need add wrong date string
            }
        }
    }
    addr_t (uint16_t a, uint16_t b, uint16_t c, uint16_t d) {
        if ((0 <= a <= 255) && (0 <= b <= 255) &&
            (0 <= c <= 255) && (0 <= d <= 255)) {
            addr_ = (a << 24) | (b << 16) | (c << 8) | d;
        } else {
            throw std::logic_error("Wrong ip addr number" ); //Need add wrong date string
        }
    }
    unsigned long get_raw() const;
private:
    uint32_t addr_;
};

std::ostream& operator<<(std::ostream& stream, const addr_t& addr) ;

std::istream& operator>>(std::istream& stream, addr_t& addr) ;

bool operator== (const addr_t& lhs, const addr_t& rhs);

bool operator< (const addr_t& lhs, const addr_t& rhs);

bool operator> (const addr_t& lhs, const addr_t& rhs);


