cmake_minimum_required(VERSION 3.24)
Project(
	IoFarmer-OpenGL
	VERSION 1.0
	LANGUAGES C
	)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(files STATIC files.c files.h)
add_library(polygon STATIC polygon.c polygon.h)
add_library(Graphics STATIC Graphics.c Graphics.h)
add_library(glad STATIC glad/src/glad.c)

target_include_directories(glad PUBLIC glad/include/glad)
target_link_libraries(Graphics PUBLIC glad)

add_executable(IoFarmer.out main.c)
target_link_libraries(IoFarmer.out PRIVATE 
	OpenGL::GL 
	glfw 
	m
	files
	polygon
	Graphics)

