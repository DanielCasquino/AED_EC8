cmake_minimum_required(VERSION 3.5.0)
project(AED_EC8 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

include(CTest)
enable_testing()

add_executable(AED_EC8 numIslands.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
