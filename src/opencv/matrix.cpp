
#include <iostream>

#include <boost/program_options.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
    namespace po = boost::program_options;

    po::options_description opt;

    opt.add_options()
            ("help,h", "ヘルプを表示");

    po::variables_map vm;

    try {
        po::store(po::parse_command_line(argc, argv, opt), vm);
    } catch (const po::error_with_option_name &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    po::notify(vm);

    if (vm.count("help")) {
        std::cout << opt << std::endl;
    } else {
        cv::Mat mat1 = cv::Mat::zeros(3, 3, CV_8U);
        cv::Mat mat3 = cv::Mat::zeros(3, 3, CV_8UC3);

        // [
        //   0, 0, 0,
        //   0, 0, 0,
        //   0, 0, 0
        // ]
        std::cout << mat1 << std::endl;

        // [
        //   0, 0, 0, 0, 0, 0, 0, 0, 0,
        //   0, 0, 0, 0, 0, 0, 0, 0, 0,
        //   0, 0, 0, 0, 0, 0, 0, 0, 0
        // ]
        std::cout << mat3 << std::endl;
    }

    return EXIT_SUCCESS;
}
