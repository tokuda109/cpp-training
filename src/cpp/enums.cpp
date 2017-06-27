
#include <gtest/gtest.h>

enum A {
    letter,
    number
};

TEST(cpp_enums_case, enums_are_not_confusing) {

    A character = number;

    switch (character) {
        case letter:
            FAIL();
            break;
        case number:
            SUCCEED();
            break;
        default:
            FAIL();
            break;
    }
}
