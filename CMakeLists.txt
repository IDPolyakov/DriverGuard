cmake_minimum_required(VERSION 3.21)

project(
    DriverGuard
    DESCRIPTION "Camera-based driver monitoring application"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(ftxui CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED COMPONENTS
    core
    highgui
    videoio
    imgproc
    objdetect
    dnn
    calib3d
)

add_executable(driverguard src/main.cpp)

target_include_directories(driverguard SYSTEM PRIVATE
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(driverguard PRIVATE
    ${OpenCV_LIBS}
    ftxui::ftxui
    SDL3::SDL3
)

add_custom_command(
    TARGET driverguard POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/resources"
            "$<TARGET_FILE_DIR:driverguard>/resources"
    COMMENT "Copying resources folder..."
)