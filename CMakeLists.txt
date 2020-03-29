cmake_minimum_required(VERSION 2.8.12)
project(example)

list (APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
find_package(ZeroMQ REQUIRED)

add_executable(rep response.cpp)
add_executable(req request.cpp)
add_executable(pub pub.cpp)
add_executable(sub sub.cpp)

target_link_libraries(rep libzmq)
target_link_libraries(req libzmq)
target_link_libraries(pub libzmq)
target_link_libraries(sub libzmq)


