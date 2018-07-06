//
// Created by dro on 26.06.18.
//

#include <bits/stdc++.h>
#include <boost/static_assert.hpp>

// Реализовать constexpr функцию bin_id - определения ближайшей большей степени двойки
namespace
{
    constexpr size_t bin_id(size_t x)
//     size_t bin_id(size_t x)
    {
        if (x < 2) {return 0;}
        size_t y=x;
        size_t i=0;
        while (y>1){
            y=y>>1;
            i++;
        }
        if (x > 1u<<i ){
            return i+1;
        } else {
            return i;
        }
//        int min=1<<(i-1);
//        int max=1<<i;
//        if (max-x < x-min) {
//            return i;
//        } else {
//            return i-1;
//        }
        return i; // Never run
    }

    BOOST_STATIC_ASSERT(bin_id(0) == 0);
    BOOST_STATIC_ASSERT(bin_id(1) == 0);
    BOOST_STATIC_ASSERT(bin_id(2) == 1);
    BOOST_STATIC_ASSERT(bin_id(4) == 2);
    BOOST_STATIC_ASSERT(bin_id(7) == 3);
    BOOST_STATIC_ASSERT(bin_id(8) == 3);
    BOOST_STATIC_ASSERT(bin_id(9) == 4);
    BOOST_STATIC_ASSERT(bin_id(1023) == 10);
    BOOST_STATIC_ASSERT(bin_id(1024) == 10);
    BOOST_STATIC_ASSERT(bin_id(1025) == 11);
    BOOST_STATIC_ASSERT(bin_id(1024*1024-33) == 20);
    BOOST_STATIC_ASSERT(bin_id(1024*1024) == 20);
    BOOST_STATIC_ASSERT(bin_id(1024*1024+33) == 21);
    BOOST_STATIC_ASSERT(bin_id(1024*1024*1024-127) == 30);
    BOOST_STATIC_ASSERT(bin_id(1024*1024*1024) == 30);
    BOOST_STATIC_ASSERT(bin_id(1024*1024*1024+127) == 31);
}

int main()
{
    size_t n;
    while(std::cin >> n)
        std::cout << bin_id(n) << std::endl;
    return 0;
}