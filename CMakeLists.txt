cmake_minimum_required(VERSION 3.9)
project(pr_ip_filter VERSION 0.0.0$ENV{TRAVIS_BUILD_NUMBER})
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
            "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
            FORCE)
endif(NOT CMAKE_BUILD_TYPE)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
set(CMAKE_CXX_FLAGS "-Wpedantic -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

add_executable(ip_filter main.cpp ipaddr.cpp ipaddr.h)
add_executable(bin_id bin_id.cpp)
add_executable(test_ip_filter test.cpp test.h ipaddr.cpp ipaddr.h)

#set_target_properties(ip_filter test_ip_filter bin_id PROPERTIES
#        CXX_STANDARD 17
#        CXX_STANDARD_REQUIRED ON
#        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
#        )

find_package(GTest REQUIRED)

set_target_properties(test_ip_filter PROPERTIES
        INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
        )

target_link_libraries(test_ip_filter GTest::GTest GTest::Main)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set_target_properties(bin_id PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

target_link_libraries(bin_id ${Boost_LIBRARIES})


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
