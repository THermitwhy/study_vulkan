#include "veWindow.hpp"

namespace vengin {
	
	veWindow::veWindow(int width, int height, const char* title) :width(width), height(height), title(title)
	{
		//initWindow();
	}
	veWindow::~veWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	void veWindow::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		window = glfwCreateWindow(width, height,title, nullptr, nullptr);

	}
	void veWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to craete window surface");
		}
	}
}