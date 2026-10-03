#ifndef   STRNG_H
#define   STRNG_H

#include <stdlib.h>

typedef struct {
	char* data;
	size_t count, capacity;
} strng;

void strng_append(strng* str, char ch);
void strng_append_cstr(strng* str, char* c_str);
void strng_append_file(strng* str, char* file_path);
char* strng_cstr(strng* str);

#ifdef    STRNG_IMPLEMENTATION

#include <stdio.h>

void strng_append(strng* str, char ch) {
	if (str->count >= str->capacity) {
		str->capacity = str->capacity ? str->capacity * 2 : 1;
		str->data = realloc(str->data, str->capacity);
	}
	str->data[str->count++] = ch;
}

void strng_append_cstr(strng* str, char* c_str) {
	size_t c_str_len = strlen(c_str);
	if (str->count + c_str_len >= str->capacity) {
		str->capacity += c_str_len;
		str->data = realloc(str->data, str->capacity);
	}
	while(*c_str != 0)
		str->data[str->count++] = *(c_str++);
}

void strng_append_file(strng* str, char* file_path) {
	FILE* file = fopen(file_path, "r");
	int ch = fgetc(file);
	while (ch != EOF) {
		strng_append(str, ch);
		ch = fgetc(file);
	}
	fclose(file);
}

char* strng_cstr(strng* str) {
	strng_append(str, 0);
	str->count--;
	return str->data;
}

#endif // STRNG_IMPLEMENTATION

#endif // STRNG_H
