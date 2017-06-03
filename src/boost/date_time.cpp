
#include <iostream>

#include <boost/date_time/posix_time/posix_time_types.hpp>

int main(int argc, char **argv) {

    namespace pt = boost::posix_time;

    pt::ptime now = pt::second_clock::local_time();

    printf(
        "%04d-%02d-%02d %02d:%02d:%02d\n",
        (int) now.date().year(),
        (int) now.date().month(),
        (int) now.date().day(),
        (int) now.time_of_day().hours(),
        (int) now.time_of_day().minutes(),
        (int) now.time_of_day().seconds()
    );

    return EXIT_SUCCESS;
}
