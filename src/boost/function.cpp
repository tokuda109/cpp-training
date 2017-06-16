
#include <iostream>

#include <boost/function.hpp>

int add(int a, int b) {
    return a + b;
}

int main(int argc, char **argv) {

    boost::function<int(int, int)> f = add;

    const int result = f(2, 3);

    std::cout << result << std::endl;

    return EXIT_SUCCESS;
}
