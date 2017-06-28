
cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)

macro(prepare_opencv)
    set(OpenCV_DIR "/usr/local/opt/opencv3/share/OpenCV")

    find_package(OpenCV REQUIRED)

    if (OpenCV_FOUND)
        include_directories(${OpenCV_INCLUDE_DIRS})
        link_directories (${OpenCV_LIBS})
    endif()
endmacro()
