
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

        // [
        //   0, 0, 0,
        //   0, 0, 0,
        //   0, 0, 0
        // ]
        std::cout << mat1 << std::endl;

        cv::Mat mat3 = cv::Mat::zeros(3, 3, CV_8UC3);

        // [
        //   0, 0, 0, 0, 0, 0, 0, 0, 0,
        //   0, 0, 0, 0, 0, 0, 0, 0, 0,
        //   0, 0, 0, 0, 0, 0, 0, 0, 0
        // ]
        std::cout << mat3 << std::endl;

        cv::Mat matOnes1 = cv::Mat::ones(3, 3, CV_8U) * 1;

        // [
        //   1, 1, 1,
        //   1, 1, 1,
        //   1, 1, 1
        // ]
        std::cout << matOnes1 << std::endl;

        cv::Mat matOnes3 = cv::Mat::ones(3, 3, CV_8UC3) * 1;

        // [
        //   1, 0, 0, 1, 0, 0, 1, 0, 0,
        //   1, 0, 0, 1, 0, 0, 1, 0, 0,
        //   1, 0, 0, 1, 0, 0, 1, 0, 0
        // ]
        std::cout << matOnes3 << std::endl;

        cv::Mat matInfo = cv::Mat::zeros(3, 6, CV_8U);

        std::cout << "rows: " << matInfo.rows <<std::endl;
        std::cout << "cols: " << matInfo.cols <<std::endl;
        std::cout << "dims: " << matInfo.dims <<std::endl;
        std::cout << "size: " << matInfo.size().width << ", " << matInfo.size().height << std::endl;
        std::cout << "channels :" << matInfo.channels() << std::endl;
        std::cout << "empty: " << (matInfo.empty() ? "true" : "false") << std::endl;
    }

    return EXIT_SUCCESS;
}
