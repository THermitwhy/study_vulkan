//#include <GLFW/glfw3.h>
//#include <unordered_map>
//#include <glm/glm.hpp>
//#include "stb_image.h"
//#include "tiny_obj_loader.h"
//#include <glm/gtc/matrix_transform.hpp>
//#include <chrono>
//#include <iostream>
//#include <fstream>
//#include <stdexcept>
//#include <algorithm>
//#include <vector>
//#include <cstring>
//#include <set>
//#include <array>
#include "vengin_applic.hpp"

//stl
#include <stdexcept>
#include <iostream>

int main() {
	vengin::applic app;
	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return 1;
}