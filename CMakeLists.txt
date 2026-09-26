cmake_minimum_required(VERSION 3.21)

project(
    DriverGuard
    DESCRIPTION "Camera-based driver monitoring application"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV CONFIG REQUIRED COMPONENTS
    core
    highgui
    videoio
    objdetect
)

add_executable(driverguard src/main.cpp)

target_include_directories(driverguard SYSTEM PRIVATE
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(driverguard PRIVATE
    ${OpenCV_LIBS}
)
