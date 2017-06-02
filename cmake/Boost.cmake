
cmake_minimum_required(VERSION 3.7.1 FATAL_ERROR)

macro(prepare_boost)
    if(NOT WIN32)
        set(CMAKE_CXX_FLAGS "-pthread")
    endif()

    if(USE_STATIC_BOOST)
        set(Boost_USE_STATIC_LIBS ON)
    endif()

    set(Boost_MULTITHREADED ON)
    set(Boost_USE_MULTITHREADED ON)
    set(Boost_USE_STATIC_RUNTIME OFF)

    find_package(Boost REQUIRED COMPONENTS program_options)

    if (Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
        link_directories (${Boost_LIBRARY_DIRS})
    endif()
endmacro()
