
#include <iostream>

#include <boost/program_options.hpp>

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

int main(int argc, char **argv) {

    namespace po = boost::program_options;

    po::options_description desc;

    desc.add_options()
        ("help,h", "Print command line options.")
        ("template", "");

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

    if (vm.count("template")) {
        ClassTemplate<int> tmpl;

        tmpl = ClassTemplate<int>();
        tmpl.append(1);
        tmpl.append(2);

        std::cout << tmpl.elements.size() << std::endl;
    }

    return EXIT_SUCCESS;
}
