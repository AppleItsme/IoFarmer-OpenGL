#include "Graphics.h"

void generate_GLInstance(GLInstance *restrict instance) {
	glGenVertexArrays(1, &instance->vao);
	glBindVertexArray(instance->vao);	
	glGenBuffers(1, &instance->vbo);
	glGenBuffers(1, &instance->ebo);
	glBindBuffer(GL_ARRAY_BUFFER, instance->vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, instance->ebo);
	instance->ID = glCreateProgram();
}
