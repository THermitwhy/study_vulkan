#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>
#include <stdexcept>
namespace vengin {
	class veWindow
	{
	public:
		//veWindow();
		veWindow(int width, int height, const char* title) ;
		~veWindow();
		veWindow(const veWindow&) = delete;
		veWindow& operator=(veWindow&) = delete;
		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);;
		bool shouldClose() { return glfwWindowShouldClose(window); }
		void initWindow();
	private:
		//create function
		


		//obj|handle
		GLFWwindow* window;


		int width;
		int height;
		const char* title;
	};
}
