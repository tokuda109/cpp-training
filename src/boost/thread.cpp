
#include <iostream>

#include <boost/thread.hpp>

void PrintHello() {
    std::cout << "hello\n" << std::endl;
}

void PrintWorld() {
    std::cout << "world\n" << std::endl;
}

int main(int argc, char **argv) {

    boost::thread hello(&PrintHello);
    boost::thread world(&PrintWorld);

    hello.join();
    world.join();

    return EXIT_SUCCESS;
}
