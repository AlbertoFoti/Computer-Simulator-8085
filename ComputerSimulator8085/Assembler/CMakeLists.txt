add_library(
        Assembler
        Assembler.hpp Assembler.cpp
)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(Assembler PRIVATE imgui::imgui)

#find_package(glfw3 CONFIG REQUIRED)
#target_link_libraries(Assembler PRIVATE glfw)

#find_package(glad CONFIG REQUIRED)
#target_link_libraries(Assembler PRIVATE glad::glad)