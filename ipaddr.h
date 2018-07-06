//
// Created by dro on 25.06.18.
//
#pragma once
#include <cstdint>
#include <array>
#include <iostream>
#include <sstream>
#include <memory>

//using addr_t = std::array<uint16_t, 4> ;

class addr_t{
public:
    addr_t () {}
    addr_t (const std::array<uint16_t, 4>& arr );
    addr_t (uint16_t a, uint16_t b, uint16_t c, uint16_t d);

    unsigned long get_raw() const;
private:
    uint32_t addr_;
};

std::ostream& operator<<(std::ostream& stream, const addr_t& addr) ;

std::istream& operator>>(std::istream& stream, addr_t& addr) ;

bool operator== (const addr_t& lhs, const addr_t& rhs);

bool operator< (const addr_t& lhs, const addr_t& rhs);
bool operator<= (const addr_t& lhs, const addr_t& rhs);

bool operator> (const addr_t& lhs, const addr_t& rhs);
bool operator>= (const addr_t& lhs, const addr_t& rhs);


