#pragma once
#include <glad.h>
#include <GLFW/glfw3.h>
#include <stdint.h>

typedef struct {
	float x;
	float y;
} Vec2;
#define VEC2(X, Y) (Vec2){ .x = X, .y = Y }

typedef struct {
	uint32_t vao, vbo, ebo, ID;
} GLInstance;

void generate_GLInstance(GLInstance *restrict instance);


