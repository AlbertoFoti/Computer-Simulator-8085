add_library(
	Memory
        Memory.hpp Memory.cpp
)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(Memory PRIVATE imgui::imgui)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Memory PRIVATE glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(Memory PRIVATE glad::glad)
