cmake_minimum_required(VERSION 3.10.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
project(rcToui VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(CMAKE_CXX_STANDARD 17)
file(GLOB INC ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

find_package(Qt5 REQUIRED COMPONENTS Gui Widgets Core)

add_executable(rcToui ${INC} ${SRC})

target_link_libraries(rcToui
Qt5::Core
Qt5::Widgets
Qt5::Gui
)