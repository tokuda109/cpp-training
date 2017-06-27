
cmake_minimum_required(VERSION 3.7.1 FATAL_ERROR)

include(Boost)
include(GTest)

prepare_boost()
prepare_gtest("boost")

include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

link_directories(${GTEST_LIBRARIES})

add_executable(boost ${SOURCES})

if (Boost_FOUND)
    target_link_libraries(
        boost
        ${Boost_LIBRARIES}
    )
endif()

if (GTest_FOUND)
    target_link_libraries(
        boost
        gtest
        gtest_main
        gmock
        gmock_main
    )
endif()

add_test(
    NAME unittest
    COMMAND boost
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
