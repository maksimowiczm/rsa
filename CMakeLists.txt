cmake_minimum_required(VERSION 3.25)
project(bsk_rsa)

set(CMAKE_CXX_STANDARD 23)

add_executable(bsk_rsa main.cpp generator/NumberGenerator.cpp generator/NumberGenerator.hpp rsa/Rsa.cpp rsa/Rsa.hpp)
include_directories(include)

#boost
find_package(Boost 1.74.0 REQUIRED COMPONENTS program_options)
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})