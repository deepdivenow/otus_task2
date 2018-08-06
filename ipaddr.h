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
    explicit addr_t (const std::array<uint8_t, 4>& arr );
    addr_t (uint8_t a, uint8_t b, uint8_t c, uint8_t d);

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

bool compare_by_mask(const addr_t& lhs, const addr_t& rhs, const addr_t& mask);


