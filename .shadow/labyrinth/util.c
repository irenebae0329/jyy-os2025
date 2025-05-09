#include <stdio.h>
#include <string.h>
#include "util.h"
void joinPath(char *dst, size_t size, const char *dir, const char *filename) {
    if (dir == NULL || filename == NULL || dst == NULL) return;
    size_t len = strlen(dir);
    if (len > 0 && dir[len-1] == '/')
        snprintf(dst, size, "%s%s", dir, filename);
    else
        snprintf(dst, size, "%s/%s", dir, filename);
}

