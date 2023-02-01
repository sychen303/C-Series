#include<stdio.h>
#include<math.h>

int main(){
    int num,sum=0,rev=0,rem;//Defining Variables
    scanf("%d",&num);       //Taking input
    while(num!=0){          //Num should not be equal to Zero.
        rem = num%10;       //Calculating Remainer(As it will always give the value of last integer)
        sum = sum + rem;    //Adding the values of remainders(Last digits)
        rev = rev*10 + rem; //Calculating the reverse(Previous Remainder*10+New Remainder)
        num = num/10;       //Dividing Number by 10.
    }
printf("%d \n",sum);
printf("%d \n",rev);
return 0;
}