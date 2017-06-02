
#include <iostream>

#include <boost/program_options.hpp>

int main(int argc, char **argv) {

    namespace po = boost::program_options;

    po::options_description desc;

    desc.add_options()
        ("help,h", "Print command line options.")
        ("opt1", po::value<int>())
        ("opt2", po::value<int>()->default_value(1));

    po::variables_map vm;

    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
    } catch (const po::error_with_option_name &e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
    }

    if (vm.count("opt1")) {
        int opt1 = vm["opt1"].as<int>();
        int opt2 = vm["opt2"].as<int>();

        std::cout << "opt1: " << opt1 << ", opt2: " << opt2 << std::endl;
    }

    return EXIT_SUCCESS;
}