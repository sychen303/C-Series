#include<stdio.h>

int main()
{
    int x;
    int count = 0;
    printf("Enter the number to check collatz on: ");
    scanf("%d",&x);
    while(x>1)
    {
        if(x%2==0){        //checks for even numbers
            x=x/2;         //divides even number by 2
            printf("%d\n",x);
        }
        else{              //checks for odd numbers
            x=(3*x)+1;     //multiplies the odd number by 3 and adds 1
            printf("%d\n",x);
        }
        count = count + 1; //Till the value reaches one, add 1 to the count.
    }
    printf("The number of iterations for %d the 421 loop is: %d",x,count);
}