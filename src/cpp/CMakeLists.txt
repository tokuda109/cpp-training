
cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)

include(Boost)
include(GTest)

prepare_boost()
prepare_gtest("cpp")

include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

link_directories(${GTEST_LIBRARIES})

add_executable(cpp ${SOURCES})

if (Boost_FOUND)
    target_link_libraries(
        cpp
        ${Boost_LIBRARIES}
    )
endif()

if (GTest_FOUND)
    target_link_libraries(
        cpp
        gtest
        gtest_main
        gmock
        gmock_main
    )
endif()

add_test(
    NAME unittest
    COMMAND cpp
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
