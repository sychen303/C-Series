#include<stdio.h>
int main(){
    int x;
    scanf("%d",&x);
    int i = 0;
    while(x!=1){
        if(x%2==0){
            x = x/2;
            printf("%d\n",x);
        }
        else{
            x = (3*x)+1;
            printf("%d\n",x);
        }
    i = i + 1;
    }
    printf("%d\n",i);
    return 0;
}