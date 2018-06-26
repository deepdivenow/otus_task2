//
// Created by dro on 25.06.18.
//

#include "test.h"
#include "gtest/gtest.h"
#include "ipaddr.h"
#include <sstream>

TEST (IpAddr, InputTest) {
    std::stringstream ss("1.11.111.1");
    addr_t  a;
    ss >> a;
    EXPECT_TRUE ( (a == addr_t{1,11,111,1}) );
    EXPECT_TRUE ( (a.get_raw() == 17526529 ) );
}

TEST (IpAddr, InputTest2) {
    addr_t  a{std::array<uint16_t, 4>{1,11,111,1}};
    addr_t  b(1,11,111,1);
    EXPECT_TRUE ( (a == b) );
    EXPECT_TRUE ( (a.get_raw() == 17526529 ) );
}

TEST (IpAddr, OutputTest) {
    std::stringstream ss;
    addr_t  a{11,22,33,44};
    ss << a;
    EXPECT_TRUE ( (ss.str() == std::string("11.22.33.44") ) );
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
};