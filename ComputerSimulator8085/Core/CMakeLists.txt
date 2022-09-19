add_library(
	Computer
		Computer.hpp Computer.cpp
)

add_subdirectory("Intel8085Processor")
add_subdirectory("Memory")
add_subdirectory("Bus")

target_link_libraries(Computer PRIVATE Intel8085Processor)
target_link_libraries(Computer PRIVATE Memory)
target_link_libraries(Computer PRIVATE Bus)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(Computer PRIVATE imgui::imgui)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Computer PRIVATE glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(Computer PRIVATE glad::glad)
