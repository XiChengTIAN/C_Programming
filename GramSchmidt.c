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
        double AT[ROW][COL];
        double BT[ROW][COL];

        for (int j = 0; j < ROW; j++)
        {
            AT[j][0]=A[j][0];
            BT[j][0]=B[j][0];
        }
        
        double a=0;
        for (int i = 0; i < ROW;i++)
        {
            a = a + AT[i][0] * BT[i][0];
        }

        return a;
    }

void GS(double A[ROW][COL],double B[ROW][COL],double C[ROW][COL])
{

    double ba2 = inner(B, A);
    double aa2 = inner(A, A);

    double AT[ROW][COL];
    double BT[ROW][COL];

    for (int j = 0; j < ROW; j++)
        {
            AT[j][0]=A[j][0];
        }

    for (int i = 0; i < ROW; i++)
        {
            B[i][0] = B[i][0] - (ba2 / aa2) * AT[i][0];
        }

    for (int j = 0; j < ROW;j++)
        {
            AT[j][0]=A[j][0];
            BT[j][0]=B[j][0];
        }

    double ca3 = inner(C, A);
    double aa3 = inner(A, A);
    double cb3 = inner(C, B);
    double bb3 = inner(B, B);
    
    for (int i = 0; i < ROW; i++)
    {
        C[i][0] = C[i][0] - (ca3 / aa3) * AT[i][0] - (cb3 / bb3) * BT[i][0];

    }    

    double a = sqrt(inner(A,A));
    double b = sqrt(inner(B,B));
    double c = sqrt(inner(C,C));

    for (int i = 0; i < ROW; i++)
    {
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
    printf("\n");

    GS(r1, r2, r3);

    double a1 = sqrt(inner(r1, r1));
    double a2 = sqrt(inner(r2, r2));
    double a3 = sqrt(inner(r3, r3));

    double a12 = (inner(r1, r2));
    double a13 = (inner(r1, r3));
    double a23 = (inner(r2, r3));
    
    printf("Output:\n");
    print_array(r1, r2, r3);
    printf("\n");

    printf("Length:\n");
    printf("%lf %lf %lf\n", a1, a2, a3);
    printf("\n");

    printf("Orthogonality:\n");
    printf("%lf %lf %lf\n", a12, a13, a23);

    return 0;
}