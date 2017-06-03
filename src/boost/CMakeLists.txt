
cmake_minimum_required(VERSION 3.7.1 FATAL_ERROR)

include(Boost)

prepare_boost()

add_executable(date_time date_time.cpp)
add_executable(program_options program_options.cpp)

if (Boost_FOUND)
    target_link_libraries(date_time ${Boost_LIBRARIES})
    target_link_libraries(program_options ${Boost_LIBRARIES})
endif()
