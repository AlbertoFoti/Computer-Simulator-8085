add_library(
	MipsProcessor
	mips32.hpp mips32.cpp
)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(MipsProcessor PRIVATE imgui::imgui)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(MipsProcessor PRIVATE glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(MipsProcessor PRIVATE glad::glad)
