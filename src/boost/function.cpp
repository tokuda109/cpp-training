
#include <boost/function.hpp>
#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(boost_test_case, function_test_1) {

    boost::function<int(int, int)> f;

    f = &add;

    const int result = f(2, 3);

    EXPECT_EQ(result, 2);
}
