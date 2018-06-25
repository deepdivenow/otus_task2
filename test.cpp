//
// Created by dro on 25.06.18.
//

#include "test.h"
#include "gtest/gtest.h"
#include "ipaddr.h"
#include <sstream>

TEST (IpAddrInputTest, PositiveNos) {
    std::stringstream ss("1.11.111.1");
    addr_t  a;
    ss >> a;
    EXPECT_TRUE ( (a == addr_t{1,11,111,1}) );
}

TEST (IpAddrOutputTest, PositiveNos) {
    std::stringstream ss;
    addr_t  a{1,11,111,1};
    ss << a;
    EXPECT_TRUE ( (ss.str() == std::string("1.11.111.1") ) );
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};