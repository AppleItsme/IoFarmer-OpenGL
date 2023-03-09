cmake_minimum_required(VERSION 3.24)
Project(
	IoFarmer-OpenGL
	VERSION 1.0
	LANGUAGES C
	)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(IoFarmer main.c)
target_link_libraries(IoFarmer PUBLIC OpenGL::GL glfw GLEW)

