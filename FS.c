#include<stdio.h>
#include<math.h>

int main(){
    int n1=1;        //initial element of fibonacci sequence
    int n2=2;        //second element of fibonacci sequence
    int n3,i,number; //declaration

    printf("Enter the limit of fibonacci sequence: ");
    scanf("%d",&number);
    printf("%d\n",n1);
    printf("%d\n",n2);
    for(i=2;i<=number;i++){
        n3 = n1 + n2; //the basis of fs, next term is sum of previous ones, here n1=1,n2=2 so, n3=3
        n1 = n2;      //replacing 1 with 2 and so on (then 2 with 3 then 5 then 8 and so on)
        n2 = n3;      //replacing 2 with 3 and so on (then 3 with 5 then 8 then 13 and so on)

        printf("%d \n",n3);
        
    }
return 0;





}