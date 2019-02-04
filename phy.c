// practice

#include <stdio.h>
#include <math.h>

#define pi 3.141592
#define e 2.71828

int main()
{
    printf("2\n");
    int i;
    for(i=3;i<30;i=i+2)
    {
        int m=2;
        while(m<i)
        {
            m++;
            int n=i%m;
            
            if(m==i)
            {
                printf("%d\n",i);
            }
            else if(n==0)
            {
                m=i+1;
            }
        }

    }

    return 0;
}