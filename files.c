#include "files.h"

void read_from(char *path, char *to, size_t *size) {
	FILE *file = fopen(path, "r");
	if(*size == 0) {
		fseek(file, 0, SEEK_END);	
		*size = ftell(file);
		return;
	}
	fseek(file, 0, SEEK_SET);
	fread(to, sizeof(char), *size, file);
	fclose(file);
}
