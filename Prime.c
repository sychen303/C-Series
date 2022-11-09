#include<stdio.h>
#include<math.h>

int main(){
    int i,j,n,count;
    printf("Enter the number upto which you want to check: ");
    scanf("%d",&n);
    printf("The prime numbers are: ");
    for ( i = 1; i < n; i++)
    {
        count = 0;
        for (j = 1; j < n; j++)
        {
            if (i%j == 0)
            count = count + 1;
        }
        if (count==2)
        printf("%d \t",i);
    }
return 0;
    
}