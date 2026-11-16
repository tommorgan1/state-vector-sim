cmake_minimum_required(VERSION 3.16)
project(state_vector_sim CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(statevector src/lib/statevector.cpp)
target_include_directories(statevector PUBLIC inc/lib)

add_executable(test_circuit src/circuits/test_circuit.cpp)
target_link_libraries(test_circuit PRIVATE statevector)
