
cmake_minimum_required(VERSION 3.7.1 FATAL_ERROR)

include(Boost)

prepare_boost()

add_executable(boost_date_time date_time.cpp)
add_executable(boost_function function.cpp)
add_executable(boost_program_options program_options.cpp)

if (Boost_FOUND)
    target_link_libraries(boost_date_time ${Boost_LIBRARIES})
    target_link_libraries(boost_function ${Boost_LIBRARIES})
    target_link_libraries(boost_program_options ${Boost_LIBRARIES})
endif()
