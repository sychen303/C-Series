// Online C compiler to run C program online
#include <stdio.h>
int main(){
    int n;
    int i=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int fact=0;
        for(int j=1;j<=n;j++){
            if(i%j==0){
                fact = fact + 1;
            }
        }
        if(fact==2){
        printf("%d\n",i);
        }
    }
} 
