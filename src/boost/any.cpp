
#include <iostream>
#include <string>

#include <boost/any.hpp>
#include <gtest/gtest.h>

TEST(boost_test_case, any_1) {
    boost::any x = 1;
    x = std::string("Hello");

    std::string val1 = boost::any_cast<std::string>(x);

    std::string& val2 = boost::any_cast<std::string&>(x);

    std::string* val3 = boost::any_cast<std::string>(&x);

    EXPECT_EQ(val1, "Hello");
    EXPECT_EQ(val2, "Hello");

    // std::cout << val1 << std::endl;
    // std::cout << val2 << std::endl;
    // std::cout << val3 << std::endl;
}
