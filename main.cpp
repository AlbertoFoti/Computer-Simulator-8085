#include "gui_main.hpp"

// OpenGL glad, GLFW  (Window, Renderer)
#include "windows.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

/***
*  ============
*    MAIN
* 
*  ============ 
*/
int WinMain(
	HINSTANCE hInsstance,
	HINSTANCE hPrevInstance,
	LPSTR lcCmdLine,
	int nShowCmd
)
{
	// Setup Window
	if (!glfwInit())
		return 1;

	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	// Create window with graphics context
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Computer Emulator - MIPS", NULL, NULL);
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
	GuiManager myGuiManager;

	// Financial Planner core (Init(), Update(), Render(), Shutdown())
	myGuiManager.Init(window, glsl_version);
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
		glClear(GL_COLOR_BUFFER_BIT);

		myGuiManager.NewFrame();
		myGuiManager.Update();
		myGuiManager.Render();
		glfwSwapBuffers(window);
	}
	myGuiManager.Shutdown();

	return 0;
}