/* Name: pun.c */
/* Purpose: Practice */
// Author: Xicheng TIAN

#include <stdio.h>
#define DROW 3
#define DCOL 3

void row(int A[DROW][DCOL],int m)
{
    int B[DROW][DCOL];

    for (int j = 0; j < DROW;j++)
    {
        for (int i = 0; i < DCOL; i++)
        {
        B[j][i] = A[j][(i + m) % DCOL];
        }

        for (int i = 0; i < DCOL; i++)
        {
            A[j][i] = B[j][i];
        }
    }
}

void print_array(int A[DROW][DCOL])
{
    for (int i = 0; i < DROW; i++)
    {
        for (int j = 0; j < DCOL;j++)
            printf("%d%c", A[i][j],(j==DCOL-1)?'\n':' ');
    }
}


int main()
{
    int A[3][3] = {{1, 2,3}, {3, 4,3}, {5, 6,3}};

    print_array(A);
    row(A, 1);
    printf("\n");
    print_array(A);
    return 0;
}