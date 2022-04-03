add_library(
	Bus
	bus.hpp bus.cpp
)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(Bus PRIVATE imgui::imgui)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Bus PRIVATE glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(Bus PRIVATE glad::glad)
