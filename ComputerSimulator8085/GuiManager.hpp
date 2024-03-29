﻿#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"
#include "implot_internal.h"
#include "Core/Computer.hpp"
#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <memory>
#include <vector>

/**
 * @brief Entry Point Example : Main component managing views update and rendering
 * 
 */
class GuiManager
{
private:
    std::shared_ptr<Computer> computer;

public:
	/**
	 * @brief Sets up ImGui and ImPlot context, loads fonts, assets and themes. 
	 * Initializes graphical components through some rendering API (ex. glfw/opengl3/glad, Vulkan, DirectX)
	 * 
	 * @param window self-explanatory
	 * @param glsl_version self-explanatory
	 */
	void Init(GLFWwindow *window, const char* glsl_version);

	/**
	 * @brief Update
	 * 
	 */
	virtual void Update();

	/**
	 * @brief Docking Space Setup, Views loading. Rendering.
	 * 
	 */
	void Render();

	/**
	 * @brief Shuts down ImGui and ImPlot context, rendering API cleanup.
	 * 
	 */
	void Shutdown();

	/**
	 * @brief Creates a New Frame
	 * 
	 */
	void NewFrame();

private:
    /**
     * @brief Show Memory Layout
     */
    void ShowMemory();

    /**
     * @brief Show Bus Data
     */
    void ShowBus();

    /**
     * @brief Show CPU internal state
     */
    void ShowCPU();

    /**
     * @brief Show CPU connection status to system bus
     */
    void ShowSystemBusStatus();

    /**
     * @brief Show Simulation Control Panel (start, stop, step the simulation)
     */
    void ShowSimulationControlPanel();

    /**
     * @brief Show Program Loading Panel
     */
    void ShowProgramEditorPanel();

    /**
     * @brief Show Error Log Panel
     */
     void ShowErrorLogsPanel();

	/**
	 * @brief Central View Rendering
	 * 
	 */
	void ShowMainView();

	/**
	 * @brief Demo View : ImGui Demo panel
	 * 
	 */
	void ShowDemoWindow();

	/**
	 * @brief Demo View : ImPlot Demo panel
	 * 
	 */
	void ShowDemoPlot();

	/**
	 * @brief Demo View : Fonts Testing panel
	 * 
	 */
	void ShowFontTesting();

	/**
	 * @brief Utility : ImGui Configuration Options/Settings
	 * 
	 * @param label 
	 * @return ignore 
	 * @return ignore 
	 */
	bool ShowStyleSelectorGUI(const char* label);

	/**
	 * @brief Utility : ImPlot Configuration Options/Settings
	 * 
	 * @param label 
	 * @return ignore 
	 * @return ignore 
	 */
	bool ShowStyleSelectorPLOT(const char* label);

	/**
	 * @brief Set Custom "Dark" Theme Colors
	 * 
	 */
	void SetDarkThemeColors();

	/**
	 * @brief Utility : shows Helper Marker
	 * 
	 * @param desc 
	 */
	void HelpMarker(const char* desc);

	/**
	 * @brief Load Fonts
	 * 
	 */
	void loadFonts();

	/**
	 * @brief Set the Theme
	 * 
	 */
	void setTheme();

	/**
	 * @brief Set the Minimum Size of a Window 
	 * 
	 */
	float setMinimumSizeWindow();
};
