#ifndef UTIL_H
#define UTIL_H
#include <stdio.h>
#include <string.h>

void joinPath(char *dst, size_t size, const char *dir, const char *filenames[]);
bool file_exists(const char *filename);
#endif


