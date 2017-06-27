
#include <gtest/gtest.h>

template <typename T>
class ClassTemplate {
public:
    std::vector<T> elements;

    void append(const T element);
};

template <typename T>
void ClassTemplate<T>::append(const T element) {
    this->elements.push_back(element);
}

TEST(cpp_test_case, template_test_1) {
    ClassTemplate<int> tmpl;

    tmpl = ClassTemplate<int>();
    tmpl.append(1);
    tmpl.append(2);

    EXPECT_EQ(tmpl.elements.size(), 2);
}