#include <stdio.h>

int isprime(int n)
{
    if(n<=1)
    {
        return 0;
    }
    for(int m=2;m*m<=n;m++)
        {
            if(n%m==0)
            {
               return 0;
            }
        }
    return 1;
}

int main()
{
    printf("2\n");
    for(int i=3;i<30;i=i+2)
    {
        if(isprime(i)==1)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}