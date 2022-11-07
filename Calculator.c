#include <stdio.h>

int main(){
printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
int choice;
printf("Enter your choice: ");
scanf("%d",&choice);

if (choice == 1){
int a;
int b;
printf("You chose addition.\n");
printf("Enter two numbers ");
scanf("%d %d",&a,&b);
int sum;
sum=a+b;
printf("Sum is %d: ",sum);
}

else if (choice == 2){
int a1;
int b1;
printf("You chose subtraction.\n");
printf("Enter two numbers: ");
scanf("%d %d",&a1,&b1);
int difference;
difference=a1-b1;
printf("Difference is %d: ",difference);
}

else if (choice == 3){
int a2;
int b2;
printf("You chose multiplication.\n");
printf("Enter two numbers: ");
scanf("%d %d",&a2,&b2);
int product;
product=a2*b2;
printf("Product is %d ",product);
}

else if (choice == 4){
int a3;
int b3;
printf("You chose division.\n");
printf("Enter two numbers: ");
scanf("%d %d",&a3,&b3);
int division;
division=a3/b3;
printf("Qoutient is %d",division);
}
else{
    printf("Wrong input.");
}
return 0;
}
