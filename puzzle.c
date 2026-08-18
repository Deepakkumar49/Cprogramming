#include <stdio.h>

#define N 9

// Check whether a number can be placed
int isSafe(int sudoku[N][N], int row, int col, int num)
{
    // Check row
    for (int x = 0; x < N; x++)
    {
        if (sudoku[row][x] == num)
            return 0;
    }

    // Check column
    for (int x = 0; x < N; x++)
    {
        if (sudoku[x][col] == num)
            return 0;
    }

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[startRow + i][startCol + j] == num)
                return 0;
        }
    }

    return 1;
}

// Find an empty cell
int findEmptyCell(int sudoku[N][N], int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
    {
        for (*col = 0; *col < N; (*col)++)
        {
            if (sudoku[*row][*col] == 0)
                return 1;
        }
    }

    return 0;
}

// Sudoku solving function
int solveSudoku(int sudoku[N][N])
{
    int row, col;

    // No empty cell means Sudoku is solved
    if (!findEmptyCell(sudoku, &row, &col))
        return 1;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(sudoku, row, col, num))
        {
            sudoku[row][col] = num;

            // Recursively solve remaining Sudoku
            if (solveSudoku(sudoku))
                return 1;

            // Backtrack
            sudoku[row][col] = 0;
        }
    }

    return 0;
}

// Print Sudoku
void printSudoku(int sudoku[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int sudoku[N][N] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},

        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},

        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Original Sudoku:\n");
    printSudoku(sudoku);

    if (solveSudoku(sudoku))
    {
        printf("\nSolved Sudoku:\n");
        printSudoku(sudoku);
    }
    else
    {
        printf("\nNo solution exists.\n");
    }

    return 0;
}