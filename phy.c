// practice

#include <stdio.h>

int main()
{
    double T0=0.0,T2=32.8,T3=15.8;
    double m=3.101e-4,ms=1.2613e-5,M=2.123e-4;
    double delta=2.17,c0=4180,cs=900;
    double L=(1/M)*(m*c0+ms*cs+delta)*(T2-T3)-c0*(T3-T0);
    printf("%f",L);
    return 0;
}