#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <getopt.h>
#include <limits.h>
#include <testkit.h>
#include "labyrinth.h"
#include "util.h"

typedef struct {
    char playerId;
    char *mapFile;
    char *direction;
    int collectedParamsNum;
} CmdArgs;

int main(int argc, char *argv[]) {
    // TODO: Implement this function
    int opt;
    int option_index = 0;
    CmdArgs cmdArgs = {0};
    char mapfilePath[PATH_MAX];

    static struct option long_options[] = {
        {"map", required_argument, 0, 'm'},
        {"player", required_argument, 0, 'p'},
        {"move", required_argument, 0, 'd'},
        {"version", no_argument, 0, 'v'},
        {0, 0, 0, 0}
    };

    joinPath(mapfilePath, sizeof(mapfilePath), PROJECT_ROOT, "maps/map1.txt");
    printf("mapfilePath: %s\n", mapfilePath);

    
    // while ((opt = getopt_long(argc, argv, "m:p:", long_options, &option_index)) != -1) {
    //     switch (opt) {
    //         case 'm':
    //             joinPath(mapfilePath, sizeof(mapfilePath), PROJECT_ROOT, (const char *[]){"maps", optarg});
    //             if (!file_exists(mapfilePath)) {
    //                 printf("Map file does not exist: %s\n", mapfilePath);
    //                 return 1;
    //             }
    //             cmdArgs.mapFile = mapfilePath;
    //             cmdArgs.collectedParamsNum++;
    //             break;
    //         case 'p':
    //             if (strlen(optarg) != 1 || !isValidPlayer(optarg[0])) {
    //                 printf("Invalid player ID: %s\n", optarg);
    //                 return 1;
    //             }
    //             cmdArgs.playerId = optarg[0];
    //             cmdArgs.collectedParamsNum++;
    //             break;
    //         case 'd':
    //             cmdArgs.direction = optarg;
    //             cmdArgs.collectedParamsNum++;
    //             break;
    //         case 'v':
    //             printUsage();
    //             return 0;
    //         default:
    //             printUsage();
    //             return 1;
    //     }
    // }
    // if(cmdArgs.collectedParamsNum == 0 || cmdArgs.collectedParamsNum == 1) {
    //     printUsage();
    //     return 1;
    // }else if(cmdArgs.collectedParamsNum == 2) {
    //     if(cmdArgs.direction != NULL) {
    //         printUsage();
    //         return 1;
    //     }
    // }

    
    return 0;
}

void printUsage() {
    printf("Labyrinth Game\n");
    printf("Usage:\n");
    printf("  labyrinth --map map.txt --player id\n");
    printf("  labyrinth -m map.txt -p id\n");
    printf("  labyrinth --map map.txt --player id --move direction\n");
    printf("  labyrinth --version\n");
    printf("Note: --move and --version only accept long form options\n");
}

bool isValidPlayer(char playerId) {
    // TODO: Implement this function
    const char *validPlayers = "0123456789";
    return strchr(validPlayers, playerId) != NULL;
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
