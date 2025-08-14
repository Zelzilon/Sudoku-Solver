#include "sudoku.h"

Box ** createBoxes()
{
    int x, y;
    Box ** boxes;
    boxes = malloc(sizeof(Box*)*9);

    for(x = 0; x < 9; x++)
    {
        boxes[x] = malloc(sizeof(Box));
        boxes[x]->squares = malloc(sizeof(Square*)*9);
        boxes[x]->numbers = 0;
        boxes[x]->solvable = 9;

        for (y = 0; y < 9; y++)
        {
            boxes[x]->possible[y] = 0;
        }
    }

    return boxes;
}

int updateBoxes(Square *** sudoku, int row, int column)
{
    int i;
    int number = sudoku[row][column]->number;
    Box * box = sudoku[row][column]->box;

    /* Update the possible numbers in the box */
    for (i = 0; i < 9; i++)
    {
        if (box->squares[i]->possible[number - 1] == 0)
        {
            box->squares[i]->solvable--;
            box->squares[i]->possible[number - 1] = 1;
        }
    }

    /* Update solvable count in the box
    box->solvable = 0;
    for (int i = 0; i < 9; i++)
    {
        if (box->possible[i] == 0)
        {
            box->solvable++;
        }
    }

    return 1;*/
}