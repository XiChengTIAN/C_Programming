// To do homework

#include <stdio.h>
#include <math.h>

int judge(int a)
{
    if(a%6==0 && a%7!=0)
    {
        return 1;
    }
    else if(a%7==0 && a%6!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    for(int i=1;i<=100;i++)
    {
        if(judge(i)==1)
        {
            printf("%d\n",i);
        }
    }

    return 0;
}