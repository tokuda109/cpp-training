
#include <iostream>

#include <boost/program_options.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
    namespace po = boost::program_options;

    po::options_description opt;

    opt.add_options()
        ("help,h", "ヘルプを表示")
        ("image1,i1", po::value<std::string>(), "画像1")
        ("image2,i2", po::value<std::string>(), "画像2");

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
    } else if (vm.count("image1") && vm.count("image2")) {
        std::string image1Path = vm["image1"].as<std::string>();
        std::string image2Path = vm["image2"].as<std::string>();

        cv::Mat img1 = cv::imread(image1Path, cv::IMREAD_COLOR);
        cv::Mat img2 = cv::imread(image2Path, cv::IMREAD_COLOR);

        if (img1.empty() || img2.empty()) {
            return EXIT_FAILURE;
        }

        cv::Ptr<cv::ORB> orb = cv::ORB::create(1000);

        std::vector<cv::KeyPoint> keypoints1, keypoints2;
        cv::Mat descriptor1, descriptor2;

        orb->detectAndCompute(img1, cv::noArray(), keypoints1, descriptor1);
        orb->detectAndCompute(img2, cv::noArray(), keypoints2, descriptor2);

        std::vector<cv::DMatch> matches;
        cv::BFMatcher matcher(cv::NORM_HAMMING, true);
        matcher.match(descriptor1, descriptor2, matches);

        cv::Mat resultImage;
        cv::drawMatches(
            img1,
            keypoints1,
            img2,
            keypoints2,
            matches,
            resultImage,
            cv::Scalar::all(-1),
            cv::Scalar::all(-1),
            std::vector<char>(),
            cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS
        );

        cv::namedWindow("Brute-force descriptor matcher", cv::WINDOW_AUTOSIZE);
        cv::imshow("Brute-force descriptor matcher", resultImage);
        cv::waitKey();
    }

    return EXIT_SUCCESS;
}
