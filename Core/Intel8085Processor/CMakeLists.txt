add_library(
	Intel8085Processor
	intel8085.hpp intel8085.cpp
)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(Intel8085Processor PRIVATE imgui::imgui)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Intel8085Processor PRIVATE glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(Intel8085Processor PRIVATE glad::glad)
