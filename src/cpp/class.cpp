
#include <gtest/gtest.h>

class MyClass {
public:
    MyClass();

    int getSize() const;

    void setSize(int size);
private:
    int size;
};

MyClass::MyClass() {
    size = 0;
}

int MyClass::getSize() const {
    return size;
}

void MyClass::setSize(int size) {
    this->size = size;
}

TEST(cpp_class_case, basic_class) {

    MyClass myClass;

    EXPECT_EQ(myClass.getSize(), 0);

    MyClass myClass1;
    myClass1.setSize(3);

    EXPECT_EQ(myClass1.getSize(), 3);
}
