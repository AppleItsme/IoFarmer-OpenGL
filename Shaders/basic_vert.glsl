#version 460

in vec2 vert;

void main() {
	gl_Position = vec4(vert, 0, 1);
}
