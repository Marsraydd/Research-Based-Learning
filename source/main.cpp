#include <iostream>
#include <format>

#include "gl.h"
#include "input.h"
#include "render.h"
#include "misc.h"

Camera cam;

int main() {
	// 一些准备工作
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(width, height, "Game", NULL, NULL);
	if (window == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// 设置窗口大小
	setInputCallbacks(window);
	glEnable(GL_DEPTH_TEST);

	//initTriangle(window);
	TestCube cube(window);
	// 开启渲染循环
	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glDepthMask(GL_FALSE);
		// 在这里做一些渲染工作
		//testTriangle(window, cam);
		cube.render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// 清理内存

	glfwTerminate();
	return 0;
}