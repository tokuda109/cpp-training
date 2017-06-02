
cmake_minimum_required(VERSION 3.7.1 FATAL_ERROR)

include(Boost)

prepare_boost()

add_executable(program_options sample_program_options.cpp)

if (Boost_FOUND)
    target_link_libraries(program_options ${Boost_LIBRARIES})
endif()
