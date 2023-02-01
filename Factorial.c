#include<stdio.h>
#include<math.h>

int main(){
    int i,n,f=1;
    printf("Enter the number: "); 
    scanf("%d",&n);
    for(i=n;i>=1;i--){ //Decreasing the value of i (3,2,1)
        f = f*i;       //Multiplying the factorial (1*3 then 1*3*2 then 1*3*2*1)
    }
    printf("Factorial is %d",f);
    return 0;

}