#include "GuiManager.hpp"

// OpenGL glad, GLFW  (Renderer)
#include "glad/glad.h"
#include "GLFW/glfw3.h"

/**
 * @brief Main : Entry point for program control (update and render loop)
 * Prepares window and other graphical components through some rendering API (ex. glfw/opengl3/glad, Vulkan, DirectX)
 * 
 * @param hInsstance 
 * @param hPrevInstance 
 * @param lcCmdLine 
 * @param nShowCmd 
 * @return int 
 */
int main()
{
	// Setup Window
	if (!glfwInit())
		return 1;

	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	// Create window with graphics context
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Intel 8085 Emulator", NULL, NULL);
	if (window == NULL) {
		return 1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	// glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw("Unable to context to OpenGL");

	// Screen setup
	int screen_width, screen_height;
	glfwGetFramebufferSize(window, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);

	// Financial Planner Instantiation
	GuiManager myGUImanager;

	// Financial Planner core (Init(), Update(), Render(), Shutdown())
    myGUImanager.Init(window, glsl_version);
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
		glClear(GL_COLOR_BUFFER_BIT);

        myGUImanager.NewFrame();
        myGUImanager.Update();
        myGUImanager.Render();
		glfwSwapBuffers(window);
	}
    myGUImanager.Shutdown();

	return 0;
}