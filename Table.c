#include<stdio.h>
#include<math.h>

int main(){

int i,n1,n2;
printf("Enter the number for multiplication: ");
scanf("%d",&n1);
printf("Enter the max value of table: ");
scanf("%d",&n2);

for(i=1; i<=n2; i++)
{
    printf("%d * %d = %d\n",n1,i,(n1*i));
}
return 0;

}