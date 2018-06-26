cmake_minimum_required(VERSION 3.9)
project(pr_ip_filter VERSION 0.0.0$ENV{TRAVIS_BUILD_NUMBER})

set(CMAKE_CXX_STANDARD 14)

add_executable(ip_filter main.cpp ipaddr.cpp ipaddr.h)
add_executable(bin_id bin_id.cpp)
add_executable(test_ip_filter test.cpp test.h ipaddr.cpp ipaddr.h)

set_target_properties(ip_filter test_ip_filter bin_id PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )

find_package(GTest REQUIRED)

set_target_properties(test_ip_filter PROPERTIES
        INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
        )

target_link_libraries(test_ip_filter GTest::GTest GTest::Main)

install(TARGETS ip_filter bin_id RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT deepdivenow@gmail.com)
set(CPACK_PACKAGE_NAME ip_filter)

include (CPack)

enable_testing()

add_test(test_addr_valid test_ip_filter)
