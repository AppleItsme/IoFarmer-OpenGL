#include "polygon.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include "files.h"

void generate_polygon(Polygon *restrict polygon, size_t n)  {
	if(polygon->vertex_len != n * 2 + 2) {
		polygon->vertex_len = n * 2 + 2;
		polygon->ebo_len = 3 * n;
		return;
	}
	float angle = 0;
	polygon->vertices[0] = polygon->position.x;
	polygon->vertices[1] = polygon->position.y;
	for(int i = 2; i < polygon->vertex_len; i += 2) {
		polygon->vertices[i] = polygon->position.x + cos(angle) * polygon->scale.x;
		polygon->vertices[i+1] = polygon->position.y + sin(angle) * polygon->scale.y;
		angle += 12.56/((float)polygon->vertex_len-2);
	} 
	uint32_t current_index = 0;
	for(int i = 0; i < polygon->ebo_len; i += 3) {
		polygon->ebo[i] = 0;
		polygon->ebo[i+1] = current_index+1;
		polygon->ebo[i+2] = current_index+2 < polygon->vertex_len/2 ? current_index+2 : 1;
		current_index++;
	}
	generate_GLInstance(&polygon->instance);
	size_t v_size, f_size;
	read_from("Shaders/basic_vert.glsl", NULL,  &v_size);
	char vertex_source[v_size];
	read_from("Shaders/basic_vert.glsl", vertex_source,  &v_size);
	read_from("Shaders/basic_vert.glsl", NULL,  &f_size);
	char frag_source[f_size];
	read_from("Shaders/basic_vert.glsl", frag_source,  &f_size);
	
	uint32_t vertex_shader = glCreateShader(GL_VERTEX_SHADER), 
			 fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_source, NULL);
	glCompileShader(vertex_shader);
	GLint status;
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &status);
	if(!status){
		char buffer[512];
		glGetShaderInfoLog(vertex_shader, 512, NULL, buffer);
		printf("%s\n", buffer);
	}
	glShaderSource(fragment_shader, 1, &frag_source, NULL);
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &status);
	if(!status){
		char buffer[512];
		glGetShaderInfoLog(fragment_shader, 512, NULL, buffer);
		printf("%s\n", buffer);
	}
	glAttachShader(polygon->instance.ID, vertex_shader);
	glAttachShader(polygon->instance.ID, fragment_shader);

	glLinkProgram(polygon->instance.ID);
	
	glGetProgramiv(polygon->instance.ID, GL_LINK_STATUS, &status);
	if(!status){
		char buffer[512];
		glGetProgramInfoLog(polygon->instance.ID, 512, NULL, buffer);
		printf("%s\n", buffer);
	}
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	uint32_t vertex_attrib = glGetAttribLocation(polygon->instance.ID, "vert");
	glEnableVertexAttribArray(vertex_attrib);
	glVertexAttribPointer(vertex_attrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
}

void draw_polygon(Polygon *restrict polygon) {
	glUseProgram(polygon->instance.ID);
	glBindVertexArray(polygon->instance.vao);
	glDrawElements(GL_TRIANGLES, polygon->ebo_len, GL_UNSIGNED_INT, polygon->ebo); 
}
