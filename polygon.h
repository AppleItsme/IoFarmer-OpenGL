#pragma once
#include <stddef.h>
#include "Graphics.h"

typedef struct {
	GLInstance instance;
	size_t vertex_len, ebo_len;
	float *vertices;
	uint32_t *ebo;
	Vec2 position;
	Vec2 scale;
} Polygon;


void generate_polygon(Polygon *restrict polygon, size_t n);
void draw_polygon(Polygon *restrict polygon);
