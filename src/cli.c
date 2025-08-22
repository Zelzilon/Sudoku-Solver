#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sudoku.h"

int **cli_get_puzzle_input() {
    int **puzzle = malloc(sizeof(int*) * 9);
    char line[128];
    int i, j;

    printf("Enter your Sudoku puzzle row by row.\n");
    printf("Use 0 or . for blanks. Separate numbers with spaces.\n\n");

    for (i = 0; i < 9; i++) {
        puzzle[i] = malloc(sizeof(int) * 9);
        printf("Row %d: ", i + 1);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            fprintf(stderr, "Input error.\n");
            exit(1);
        }
        char *token = strtok(line, " \t\n");
        for (j = 0; j < 9; j++) {
            if (token == NULL) {
                puzzle[i][j] = 0;
            } else if (token[0] == '.' || token[0] == '0') {
                puzzle[i][j] = 0;
                token = strtok(NULL, " \t\n");
            } else {
                puzzle[i][j] = atoi(token);
                token = strtok(NULL, " \t\n");
            }
        }
    }
    return puzzle;
}