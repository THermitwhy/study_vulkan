#include "vengin_applic.hpp"

namespace vengin {
	applic::applic()
	{
		vWindow.initWindow();
		veDevice device(vWindow);
		
	}

	applic::~applic()
	{
	}

	void applic::run()
	{
		while (!vWindow.shouldClose()) {
			glfwPollEvents();
		}
	}
}