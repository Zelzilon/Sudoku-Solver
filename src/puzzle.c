#include "sudoku.h"

Square *** setUpPuzzle(int ** puzzle)
{
    Square *** sudoku;
    int i, j, k;

    sudoku = (Square***)malloc(sizeof(Square**)*9);
    
    /*Loop through rows*/
    for (i = 0; i < SIZE_ROWS; i++)
    {
        /*malloc space for each row*/
        sudoku[i] = (Square**)malloc(sizeof(Square*)*9);
        
        /*Loop through columns*/
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            /*malloc space for each square*/
            sudoku[i][j] = (Square*)malloc(sizeof(Square));
            /*assign number to sudoku*/
            sudoku[i][j]->number = puzzle[i][j];
            /*assign row and column numbers to each square*/
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;
            sudoku[i][j]->solvable = 9;

            for (k = 0; k < SIZE_ROWS; k++)
            {
                sudoku[i][j]->possible[k] = 0;
            }
        }
    }

    for (i = 0; i < SIZE_ROWS; i++)
    {

        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            if (sudoku[i][j]->number != 0)
            {
                /*solvable set to 0 as the square has a number 1-9 and is no longer solvable*/
                sudoku[i][j]->solvable = 0;
                updateSudoku(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }

    return sudoku;
}

int updateSudoku(Square *** sudoku, int row, int column)
{
    int x;
    int number = sudoku[row][column]->number;
    /*Search down the column for a number that equals 0, if it does, decrement the solvable
    number. If solvable = 1, that means there's only 1 number that can go in the square,
    thus making it solvable. Then it sets the possible array of that number to 1 meaning
    it cannot be a particular number.*/
    for (x = 0; x < SIZE_ROWS; x++)
    {
        if (sudoku[x][column]->possible[number - 1] == 0)
        {
            sudoku[x][column]->solvable--;
        }
        sudoku[x][column]->possible[number - 1] = 1;
    }
    /*Same thing as above, but this is going across the row instead*/
    for (x = 0; x < SIZE_COLUMNS; x++)
    {
        if (sudoku[row][x]->possible[number - 1] == 0)
        {
            sudoku[row][x]->solvable--;
        }
        sudoku[row][x]->possible[number - 1] = 1;
    }

    return 1;
}

int checkPuzzle(Square *** sudoku)
{
    int i, j;
    for (i = 0; i < SIZE_ROWS; i++)
    {
        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            if (sudoku[i][j]->solvable == 1)
            {
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
            }
        }
    }
    return 1;
}

int ** createPuzzle()
{
    int ** puzzle;
    int i, j;
    int array[9][9]=  {0, 1, 9,    7, 0, 2,    0, 0, 0,
                       4, 7, 0,    6, 9, 0,    0, 0, 1,
                       0, 0, 0,    4, 0, 0,    0, 9, 0,
                    
                       8, 9, 4,    5, 0, 7,    1, 2, 6,
                       0, 0, 0,    0, 0, 0,    0, 0, 0,
                       0, 0, 0,    2, 0, 1,    9, 5, 8,                    
                       
                       0, 5, 0,    9, 0, 6,    0, 0, 0,
                       6, 0, 0,    3, 2, 8,    0, 7, 9,
                       0, 0, 0,    1, 0, 0,    8, 6, 0};

    puzzle = (int**)malloc(sizeof(int*)*9);

    for (i = 0; i < SIZE_ROWS; i++)
    {
        puzzle[i] = (int*)malloc(sizeof(int)*9);

        for (j = 0; j < SIZE_COLUMNS; j++)
        {
            puzzle[i][j] = array[i][j];
        }
    }
    return puzzle;
}

void printPuzzle(Square *** puzzle)
{
    int i, j;

    printf("------------------------------\n");
    for (i = 0; i < 9; i++)
    {
        /*print each row*/
        printf("|");
        for(j = 0; j < 9; j++) 
        {
            printf(" %d ", puzzle[i][j]->number);

            if (((j+1) % 3) == 0)
            {
                printf("|");
            }
        }
        printf("\n");
        if (((i + 1) % 3) == 0)
        {
            printf("------------------------------\n");
        }
    }
}