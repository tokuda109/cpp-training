
#include <string>
#include <tuple>

#include <gtest/gtest.h>

std::tuple<int, std::string> getTuple() {
    return std::forward_as_tuple(3, "c++ tuple");
};

TEST(cpp_tuple_case, tuple_test_1) {

    int intVal;
    std::string strVal;

    std::tie(intVal, strVal) = getTuple();

    EXPECT_EQ(intVal, 3);
    EXPECT_EQ(strVal, "c++ tuple");
}
