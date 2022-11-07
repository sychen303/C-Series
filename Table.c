#include<stdio.h>
#include<math.h>

int main(){

int a,b,c;
printf("Enter the number for multiplication: ");
scanf("%d",&a);
printf("Enter the max value of table: ");
scanf("%d",&b);

for(c=1; c<=b; c++)
{
    printf("%d * %d = %d\n",a,c,(a*c));
}
return 0;

}