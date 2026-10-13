cmake_minimum_required(VERSION 3.16)
project(GottfriedAPI VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Crow CONFIG REQUIRED)

add_executable(GottfriedAPI
  src/main.cpp
)

target_link_libraries(GottfriedAPI
  PRIVATE
  Crow::Crow
)

