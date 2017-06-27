
#include <boost/bind.hpp>
#include <gtest/gtest.h>

int f(int a, int b) {
    return a + b;
}

TEST(boost_test_case, bind_test_1) {

    int h = boost::bind(f, boost::placeholders::_1, boost::placeholders::_2)(1, 2);

    EXPECT_EQ(h, 3);

    int i = boost::bind(f, boost::placeholders::_1, 4)(1);

    EXPECT_EQ(i, 5);
}

TEST(boost_test_case, bind_test_2) {

    struct F {
        int operator()(int a, int b) { return a - b; }
        bool operator()(long a, long b) { return a == b; }
    };

    F f;

    int x = 10;

    int h = boost::bind<int>(f, boost::placeholders::_1, 4)(x);

    EXPECT_EQ(h, 6);

    bool i = boost::bind<bool>(f, boost::placeholders::_1, 4)(4);

    EXPECT_EQ(i, false);
}
