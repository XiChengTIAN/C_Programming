/* Name: pun.c */
/* Purpose: Practice */
// Author: Xicheng TIAN

#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("homework.c", "r");
    char c = getchar();
    putchar(c);
    fclose(fp);
    return 0;
}