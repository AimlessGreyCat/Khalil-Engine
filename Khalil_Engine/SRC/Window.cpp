#include "Window.h"
#include <iostream>


Khalil::Window::Window()
{
	try
	{
		if (InstanceCount != 0)
			throw std::runtime_error("Instance of window already exists.");
	}
	catch (const std::exception& E)
	{
		std::cout << "ERROR - " << E.what() << std::endl;
		exit(-1);
	}

	++InstanceCount;
}

void Khalil::Window::Run()
{
	Initialize();
	Loop();

	glfwTerminate();
}

void Khalil::Window::Initialize()
{
	// Initialize GLFW
	if (!glfwInit())
	{
		std::cout << "ERROR - glfwInit failed." << std::endl;
		exit(-1);
	}

	// Pre-Configure GLFW Window
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);
   
	// Create GLFW Window
	GLFW_Window = glfwCreateWindow(Width, Height, Title, NULL, NULL);

	if (!GLFW_Window)
	{
		std::cout << "ERROR - Could not create window." << std::endl;
		exit(-1);
	}

	// Make it the current context
	glfwMakeContextCurrent(GLFW_Window);

	// V-Sync on
	glfwSwapInterval(1);

	// Make window visible
	glfwShowWindow(GLFW_Window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR - glewInit failed." << std::endl;
		exit(-1);
	}
}

void Khalil::Window::Loop()
{
	while (!glfwWindowShouldClose(GLFW_Window))
	{
		glfwPollEvents();

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(GLFW_Window);
	}
}
