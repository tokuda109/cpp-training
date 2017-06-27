
cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)

macro(prepare_gtest name)
    enable_testing()

    include(ExternalProject)

    set(GTEST_VERSION 1.8.0)

    ExternalProject_Add(
        GTest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-${GTEST_VERSION}
        PREFIX googletest-release-${GTEST_VERSION}
        LOG_DOWNLOAD ON
        LOG_CONFIGURE ON
        LOG_BUILD ON
    )

    ExternalProject_Get_Property(GTest SOURCE_DIR)
    ExternalProject_Get_Property(GTest BINARY_DIR)

    set(GTEST_LIBRARY gtest)
    set(GTEST_SOURCE_DIR ${SOURCE_DIR})
    set(GTEST_BINARY_DIR ${BINARY_DIR})
    set(GTEST_MAIN_LIBRARY ${GTEST_LIBRARY}_main)
    set(GTEST_INCLUDE_DIR ${GTEST_SOURCE_DIR}/googletest/include)

    set(GMOCK_LIBRARY gmock)
    set(GMOCK_MAIN_LIBRARY ${GMOCK_LIBRARY}_main)

    find_package(GTest REQUIRED)

    # gtest
    add_library(${GTEST_LIBRARY} STATIC IMPORTED)
    set_property(TARGET ${GTEST_LIBRARY} PROPERTY IMPORTED_LOCATION ${GTEST_BINARY_DIR}/googlemock/gtest/libgtest.a)
    add_dependencies(${GTEST_LIBRARY} GTest)

    # gtest_main
    add_library(${GTEST_MAIN_LIBRARY} STATIC IMPORTED)
    set_property(TARGET ${GTEST_MAIN_LIBRARY} PROPERTY IMPORTED_LOCATION ${GTEST_BINARY_DIR}/googlemock/gtest/libgtest_main.a)
    add_dependencies(${GTEST_MAIN_LIBRARY} GTest)

    # gmock
    add_library(${GMOCK_LIBRARY} STATIC IMPORTED)
    set_property(TARGET ${GMOCK_LIBRARY} PROPERTY IMPORTED_LOCATION ${GTEST_BINARY_DIR}/googlemock/libgmock.a)
    add_dependencies(${GMOCK_LIBRARY} GTest)

    # gmock_main
    add_library(${GMOCK_MAIN_LIBRARY} STATIC IMPORTED)
    set_property(TARGET ${GMOCK_MAIN_LIBRARY} PROPERTY IMPORTED_LOCATION ${GTEST_BINARY_DIR}/googlemock/libgmock_main.a)
    add_dependencies(${GMOCK_MAIN_LIBRARY} GTest)

    set(GTest_FOUND ON)
endmacro()
