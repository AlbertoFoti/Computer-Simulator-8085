#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>
#include <string>

#include "Core/computer.hpp"

// GUI manager
class GuiManager {
private:
	std::shared_ptr<Computer> MipsComputer;
		
public:
	void Init(GLFWwindow *window, const char* glsl_version);
	virtual void Update();
	void Render();
	void Shutdown();

	void NewFrame();

private:
	// Views
	void ShowDemoWindow();

	// Helper Functions
	void HelpMarker(const char* desc);
};