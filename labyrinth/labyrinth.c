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

#define COMMAND_TYPE_MAP 10
#define COMMAND_TYPE_MOVE 11
#define COMMAND_TYPE_VERSION 12
#define OPERATION_SUCCESS 1
#define OPERATION_FAILED 0
#define INVALID_PLAYER_ID 'X'
typedef struct {
    char playerId;
    char *mapFile;
    char *direction;
    int collectedParamsNum;
} CmdArgs;

typedef struct {
    int firstEmptyPlace[2];
    int emptyPlacesNum;
} LabyrinthInfo;

int main(int argc, char *argv[]) {
    // TODO: Implement this function
    int opt;
    int option_index = 0;
    CmdArgs cmdArgs = {0};
    char mapfilePath[PATH_MAX];
    Labyrinth labyrinth = {0};
    LabyrinthInfo labyrinthInfo = {0};

    int commandType = COMMAND_TYPE_MAP;
    static struct option long_options[] = {
        {"map", required_argument, 0, 'm'},
        {"player", required_argument, 0, 'p'},
        {"move", required_argument, 0, 'd'},
        {"version", no_argument, 0, 'v'},
        {0, 0, 0, 0}
    };

    
    while ((opt = getopt_long(argc, argv, "m:p:", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'm':
                joinPath(mapfilePath, sizeof(mapfilePath), PROJECT_ROOT, (const char *[]){"maps", optarg},2);
                if (!file_exists(mapfilePath)) {
                    printf("Map file does not exist: %s\n", mapfilePath);
                    return OPERATION_FAILED;
                }
                cmdArgs.mapFile = mapfilePath;
                commandType = COMMAND_TYPE_MAP;
                break;
            case 'p':
                if (strlen(optarg) != 1 || !isValidPlayer(optarg[0])) {
                    cmdArgs.playerId = INVALID_PLAYER_ID;
                } else {
                    cmdArgs.playerId = optarg[0];
                }
                commandType = COMMAND_TYPE_MAP;
                break;
            case 'd':
                cmdArgs.direction = optarg;
                commandType = COMMAND_TYPE_MOVE;
                break;
            case 'v':
                commandType = COMMAND_TYPE_VERSION;
                break;
            default:
                printUsage();
                return OPERATION_FAILED;
        }
    }

    switch(commandType) {
        case COMMAND_TYPE_VERSION:
            if(cmdArgs.collectedParamsNum != 0) {
                printUsage();
                return OPERATION_FAILED;
            }
            printVersion();
            return OPERATION_SUCCESS;
        case COMMAND_TYPE_MAP:
            if(cmdArgs.collectedParamsNum != 2) {
                printUsage();
                return OPERATION_FAILED;
            }
            break;
        case COMMAND_TYPE_MOVE:
            if(cmdArgs.collectedParamsNum != 3) {
                printUsage();
                return OPERATION_FAILED;
            }
            break;
    }


        

    
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
    FILE *file = fopen(filename, "r");
    if(!file) {
        printf("Failed to open map file: %s\n", filename);
        return false;
    }
    char line[MAX_COLS];
    int row = 0;
    int col = 0;
    while(fgets(line, sizeof(line), file)) {
        if(line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        if(row == 0) {
            col = strlen(line);
        }
        for(int i = 0; i < col; i++) {
            labyrinth->map[row][i] = line[i];
        }
        row++;
    }
    labyrinth->rows = row;
    labyrinth->cols = col;
    fclose(file);
    
    return true;
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
