cmake_minimum_required (VERSION 3.15.0)
project (mata-test)
set (CMAKE_CXX_STANDARD 20)

find_library(LIBMATA mata REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC ${LIBMATA})
