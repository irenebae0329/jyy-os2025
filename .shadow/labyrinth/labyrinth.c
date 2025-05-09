#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <getopt.h>
#include <testkit.h>
#include "labyrinth.h"
#include "util.h"

#define BASE_DIR __FILE__
int main(int argc, char *argv[]) {
    // TODO: Implement this function
    int opt;
    int option_index = 0;
    const char *map_base_path = NULL;
    printf("BASE_DIR: %s\n", BASE_DIR);
    // static struct option long_options[] = {
    //     {"map", required_argument, 0, 'm'},
    //     {"player", required_argument, 0, 'p'},
    //     {"move", required_argument, 0, 'd'},
    //     {"version", no_argument, 0, 'v'},
    //     {0, 0, 0, 0}
    // };
    
    // while ((opt = getopt_long(argc, argv, "m:p:", long_options, &option_index)) != -1) {
    //     switch (opt) {
    //         case 'm':
    //             char *map_file = optarg;
    //             break;
    //         case 'p':
    //             char *player_id = optarg;
    //             break;
    //         case 'd':
    //             char *direction = optarg;
    //             break;
    //         case 'v':
    //             printUsage();
    //             return 0;
    //     }
    // }

    
    return 0;
}

void printUsage() {
    printf("Usage:\n");
    printf("  labyrinth --map map.txt --player id\n");
    printf("  labyrinth -m map.txt -p id\n");
    printf("  labyrinth --map map.txt --player id --move direction\n");
    printf("  labyrinth --version\n");
    printf("Note: --move and --version only accept long form options\n");
}

bool isValidPlayer(char playerId) {
    // TODO: Implement this function
    return false;
}

bool loadMap(Labyrinth *labyrinth, const char *filename) {
    // TODO: Implement this function
    // const char *map_base_path = ;
    return false;
}

Position findPlayer(Labyrinth *labyrinth, char playerId) {
    // TODO: Implement this function
    Position pos = {-1, -1};
    return pos;
}

Position findFirstEmptySpace(Labyrinth *labyrinth) {
    // TODO: Implement this function
    Position pos = {-1, -1};
    return pos;
}

bool isEmptySpace(Labyrinth *labyrinth, int row, int col) {
    // TODO: Implement this function
    return false;
}

bool movePlayer(Labyrinth *labyrinth, char playerId, const char *direction) {
    // TODO: Implement this function
    return false;
}

bool saveMap(Labyrinth *labyrinth, const char *filename) {
    // TODO: Implement this function
    return false;
}

// Check if all empty spaces are connected using DFS
void dfs(Labyrinth *labyrinth, int row, int col, bool visited[MAX_ROWS][MAX_COLS]) {
    // TODO: Implement this function
}

bool isConnected(Labyrinth *labyrinth) {
    // TODO: Implement this function
    return false;
}
