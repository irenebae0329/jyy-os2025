#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "util.h"
#include <stdbool.h>
void joinPath(char *dst, size_t size, const char *dir, const char *filenames[]) {
    if (dir == NULL || filenames == NULL || dst == NULL) return;
    size_t len = strlen(dir);
    for(int i = 0; i < sizeof(filenames); i++) {
        char *filename = filenames[i];
        if (len > 0 && dir[len-1] == '/')
            snprintf(dst, size, "%s%s", dir, filename);
        else
            snprintf(dst, size, "%s/%s", dir, filename);
    }
}

bool file_exists(const char *filename) {
    return access(filename, F_OK) != -1;
}