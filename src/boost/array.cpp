
#include <boost/array.hpp>
#include <gtest/gtest.h>

TEST(boost_test_case, array_1) {

    boost::array<int, 3> a = {1, 2, 3};

    EXPECT_EQ(a.size(), 3);

    int *p = a.data();

    EXPECT_EQ(p[0], 1);
}
