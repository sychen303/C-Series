#include<stdio.h>
#include<math.h>
 
int main(){
int a,b,c;
printf("Enter the coefficients of your quadratic equation:  ");
scanf("%d",&a);
printf("Enter the coefficients of your quadratic equation:  ");
scanf("%d",&b);
printf("Enter the coefficients of your quadratic equation:  ");
scanf("%d",&c);
float d;
d=b*b-4.*a*c;
if(d>0){
    printf("Roots are real: ");
    float root1,root2;
    root1=(-b+sqrt(d))/2*a;
    root2=(-b-sqrt(d))/2*a;
    printf("%f %f",root1, root2);
} else if(d==0){
    printf("Roots are same \n");
    float root;
    root=(-b+sqrt(d))/2*a;
    printf("Root is %f",root);
} else {
    printf("Roots are imaginary");
    float root1, root2;
    root1 = (-b+sqrt(d*-1))/2*a;
    root2 = (-b+sqrt(d*-1))/2*a;
    printf("%.2f i",root1);
    printf("%.2f i",root2);
}
return 0;
}
 
