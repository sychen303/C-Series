#include<stdio.h>
#include<math.h>
 
int main(){
float a,b,c,sp,temp,area;
printf("Enter the first side: ");
scanf("%f",&a);
printf("Enter the second side: ");
scanf("%f",&b);
printf("Enter the third side: ");
scanf("%f",&c);
sp = (a+b+c)/2;
temp=sp*(sp-a)*(sp-b)*(sp-c);
area=sqrt(temp);
printf("Area: %f", area);
return 0;
}