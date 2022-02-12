#pragma once
#include <gl/glew.h>
#include <GLFW/glfw3.h>

namespace Khalil 
{
	class Window
	{
	public:
		Window();

		void Run();

	private:
		void Initialize();
		void Loop();

	private:
		GLFWwindow* GLFW_Window = nullptr;
		static constexpr int Width = 1920, Height = 1080;
		static constexpr char const* Title = "Khalil-Engine";

		inline static int InstanceCount = 0;
	};
}

