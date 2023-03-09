#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

//A function declaration that will handle all the GLFW-related errors
void error_callback(int error, const char* description);
//A function declaration that will handle all the keyboard-based input
void input_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main() {
	glfwSetErrorCallback(error_callback);
	if(!glfwInit()) {
		printf("There was some problem with glfw launching.");
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	GLFWwindow* window = glfwCreateWindow(800, 800, "my glfw window", NULL, NULL);
	if(!window) {
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, input_callback);

	glewInit();

	glfwDestroyWindow(window);
	glfwTerminate();
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void input_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

}
