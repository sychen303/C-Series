#include<stdio.h>
int sum()
{
    float a,b,sum;
    printf("Enter First Number: ");
    scanf("%f",&a);
    printf("Enter Second Number: ");
    scanf("%f",&b);
    sum = a + b;
    printf("%f",sum);
}
int diff()
{
    float a,b,diff;
    printf("Enter First Number: ");
    scanf("%f",&a);
    printf("Enter Second Number: ");
    scanf("%f",&b);
    diff = a - b;
    printf("%f",diff);
}
int prod()
{
    float a,b,prod;
    printf("Enter First Number: ");
    scanf("%f",&a);
    printf("Enter Second Number: ");
    scanf("%f",&b);
    prod = a * b;
    printf("%f",prod);
}
int div()
{
    float a,b,div;
    printf("Enter First Number: ");
    scanf("%f",&a);
    printf("Enter Second Number: ");
    scanf("%f",&b);
    div = a / b;
    printf("%f",div);
}
int main()
{
    int choice;
    printf("Enter Your Choice\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d",&choice);
    if (choice==1){
        printf("You've chosen addition\n");
        sum();
    }
    else if (choice == 2){
        printf("You've chosen subtraction.\n");
        diff();
    }
    else if (choice == 3){
        printf("You've chosen multiplication.\n");
        prod();
    }
    else{
        printf("You've chosen division.\n");
        div();
    }
    return 0;
}