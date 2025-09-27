cmake_minimum_required(VERSION 3.10)
project(kernellens)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

find_package(nlohmann_json 3.2.0 REQUIRED)
add_executable(kernellens src/main.cpp src/json_rpc_server.cpp src/syscall_tracer.cpp src/network_monitor.cpp)
target_link_libraries(kernellens PRIVATE nlohmann_json::nlohmann_json)
