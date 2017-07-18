
cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)

include(Boost)
include(OpenCV)

prepare_boost()
prepare_opencv()

add_executable(opencv_matrix matrix.cpp)
add_executable(opencv_orb orb.cpp)

if (Boost_FOUND)
    target_link_libraries(opencv_matrix ${Boost_LIBRARIES})
    target_link_libraries(opencv_orb ${Boost_LIBRARIES})
endif()

if (OpenCV_FOUND)
    target_link_libraries(opencv_matrix ${OpenCV_LIBS})
    target_link_libraries(opencv_orb ${OpenCV_LIBS})
endif()
