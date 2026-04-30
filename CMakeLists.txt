cmake_minimum_required(VERSION 3.14.0)
project(cpp-dev VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Library with testable code ----
add_library(math_utils src/math_utils.cpp)
target_include_directories(math_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# ---- Main executable ----
add_executable(cpp-dev main.cpp)
target_link_libraries(cpp-dev PRIVATE math_utils)

# ---- Unit Testing with Google Test ----
include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)
# Prevent GoogleTest from overriding compiler/linker options on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests tests/test_math_utils.cpp)
target_link_libraries(unit_tests PRIVATE math_utils GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)

# ---- CPack ----
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)