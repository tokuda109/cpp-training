
cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)

include(Boost)
include(OpenCV)

prepare_boost()
prepare_opencv()

add_executable(opencv_orb orb.cpp)

if (Boost_FOUND)
    target_link_libraries(opencv_orb ${Boost_LIBRARIES})
endif()

if (OpenCV_FOUND)
    target_link_libraries(opencv_orb ${OpenCV_LIBS})
endif()
