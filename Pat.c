#include<stdio.h>

int main()
{
    int x;
    printf("Enter");
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<(x-i);j++)
        {
        printf("*");
        }
    printf("\n");
    }
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("*");
        }
    printf("\n");
    }
return 0;
}
