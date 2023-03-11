#include <stdio.h>
#include <alloca.h>

#include "polygon.h"

//A function declaration that will handle all the GLFW-related errors
void error_callback(int error, const char* description);
//A function declaration that will handle all the keyboard-based input
void input_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main() {
	glfwSetErrorCallback(error_callback);
	if(!glfwInit()) {
		printf("There was some problem with glfw launching.");
		return 0;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	GLFWwindow* window = glfwCreateWindow(800, 800, "my glfw window", NULL, NULL);
	if(!window) {
		glfwTerminate();
		return 0;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, input_callback);
	
	Polygon my_poly;
	generate_polygon(&my_poly, 4);
	my_poly.ebo = alloca(my_poly.ebo_len * sizeof(my_poly.ebo));
	my_poly.vertices = alloca(my_poly.vertex_len * sizeof(my_poly.vertices));
	generate_polygon(&my_poly, 4);

	while(!glfwWindowShouldClose(window)) {
		draw_polygon(&my_poly);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void input_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

}
