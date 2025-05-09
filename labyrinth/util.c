#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "util.h"
#include <stdbool.h>
void joinPath(char *dst, size_t size, const char *dir, const char *filenames[], size_t count) {
    if (dir == NULL || filenames == NULL || dst == NULL) return;
    dst[0] = '\0';
    strncat(dst, dir, size-1);
    for (size_t i = 0; i < count; i++) {
        if (filenames[i] == NULL) continue;
        size_t dst_len = strlen(dst);
        // 判断斜杠很重要
        if (dst_len > 0 && dst[dst_len-1] != '/' && filenames[i][0] != '/')
            strncat(dst, "/", size - strlen(dst) - 1);
        else if (dst_len > 0 && dst[dst_len-1] == '/' && filenames[i][0] == '/')
            filenames[i]++; // 避免 "/a//b" 的情况
        strncat(dst, filenames[i], size - strlen(dst) - 1);
    }
}

bool file_exists(const char *filename) {
    return access(filename, F_OK) != -1;
}