//just for a simple 3d vector space

#include <stdio.h>
#include <math.h>
#define ROW 3
#define COL 1

void input_array(double A[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        scanf("%lf",&A[i][0]);
    }
}

void print_array(double A[ROW][COL],double B[ROW][COL],double C[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
            printf("%lf %lf %lf\n", A[i][0],B[i][0],C[i][0]);
    }
}

double inner(double A[ROW][COL],double B[ROW][COL])
    {
        double a=0;
        for (int i = 0; i < ROW;i++)
        {
            a = a + A[i][0] * B[i][0];
        }
        return a;
    }

void GS(double A[ROW][COL],double B[ROW][COL],double C[ROW][COL])
{

    for (int i = 0; i < ROW; i++)
    {
        B[i][0] = B[i][0] - (inner(B, A) / inner(A, A)) * A[i][0];
        C[i][0] = C[i][0] - (inner(C, A) / inner(A, A)) * A[i][0] - (inner(C, B) / inner(B, B)) * B[i][0];

        double a = sqrt(inner(A,A));
        double b = sqrt(inner(B,B));
        double c = sqrt(inner(C,C));

        A[i][0] = A[i][0] / a;
        B[i][0] = B[i][0] / b;
        C[i][0] = C[i][0] / c;
    }
}

int main()
{
    double r1[3][1];
    double r2[3][1];
    double r3[3][1];


    input_array(r1);
    input_array(r2);
    input_array(r3);

    printf("Input:\n");
    print_array(r1, r2, r3);

    GS(r1, r2, r3);

    double a1 = sqrt(inner(r1, r1));
    double a2 = sqrt(inner(r2, r2));
    double a3 = sqrt(inner(r3, r3));

    double a12 = (inner(r1, r2));
    double a13 = (inner(r1, r3));
    double a23 = (inner(r2, r3));
    
    printf("Output:\n");
    print_array(r1, r2, r3);

    printf("Length:\n");
    printf("%lf %lf %lf\n", a1, a2, a3);

    printf("Orthogonality:\n");
    printf("%lf %lf %lf\n", a12, a13, a23);

    return 0;
}