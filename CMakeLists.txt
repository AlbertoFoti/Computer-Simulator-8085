cmake_minimum_required(VERSION 3.0.0)
project(COMPUTER-SIMULATOR-MIPS VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(COMPUTER-SIMULATOR-MIPS WIN32 main.cpp gui_main.hpp gui_main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory("Core")

target_link_libraries(${PROJECT_NAME} PRIVATE Computer)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)
