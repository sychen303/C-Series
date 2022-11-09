#include<stdio.h>
#include<math.h>
 
int main(){
float a,b,c,a1;
printf("Enter the coefficients of your quadratic equation:  ");
scanf("%f",&a);
printf("Enter the coefficients of your quadratic equation:  ");
scanf("%f",&b);
printf("Enter the coefficients of your quadratic equation:  ");
scanf("%f",&c);
a1 = a*2;
float d;
d=b*b-4.*a*c;
if(d>0){
    printf("Roots are real: ");
    float root1,root2;
    root1=(-b+sqrt(d))/a1;
    root2=(-b-sqrt(d))/a1;
    printf("%f %f",root1, root2);
} else if(d==0){
    printf("Roots are same \n");
    float root;
    root=(-b+sqrt(d))/a1;
    printf("Root is %f",root);
} else {
    printf("Roots are imaginary: ");
    float r, i1, i2;
    r = ((-b)/a1);
    i1 = sqrt(d*-1)/a1;
    i2 = -(sqrt(d*-1))/a1;
    printf("%f+%fi ",r,i1);
    printf("%f%fi",r,i2);
}
return 0;
}
 
