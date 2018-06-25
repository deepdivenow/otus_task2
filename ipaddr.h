//
// Created by dro on 25.06.18.
//
#pragma once
#include <cstdint>
#include <array>
#include <iostream>
#include <sstream>

using addr_t = std::array<uint16_t, 4> ;

std::ostream& operator<<(std::ostream& stream, const addr_t& addr) ;

std::istream& operator>>(std::istream& stream, addr_t& addr) ;



