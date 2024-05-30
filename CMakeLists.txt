cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(cyclic_visitor)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Cyclic_Visitor)
add_library(drawAllShapes STATIC ${CMAKE_CURRENT_SOURCE_DIR}/Cyclic_Visitor/DrawAllShapes.cpp)

add_executable(mt ${CMAKE_CURRENT_SOURCE_DIR}/Cyclic_Visitor/Main.cpp)
add_executable(mt2 ${CMAKE_CURRENT_SOURCE_DIR}/Cyclic_Visitor/G16_Cyclic_Visitor.cpp)

target_link_libraries(mt drawAllShapes)

install(TARGETS mt RUNTIME DESTINATION bin)

add_subdirectory(third-party/gtest)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

file(GLOB TEST_SOURCES test.cpp)
add_executable(testt ${TEST_SOURCES})

target_link_libraries(testt gtest_main gtest gmock drawAllShapes)
add_test(NAME testt COMMAND testt)
