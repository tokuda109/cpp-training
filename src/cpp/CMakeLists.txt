
cmake_minimum_required(VERSION 3.7.1 FATAL_ERROR)

include(Boost)

prepare_boost()

add_executable(cpp main.cpp)

if (Boost_FOUND)
    target_link_libraries(cpp ${Boost_LIBRARIES})
endif()
