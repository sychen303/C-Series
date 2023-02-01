#include<stdio.h>

int main(){
    int flag,temp=0,n,pos;
    scanf("%d",&flag);
    scanf("%d",&n);
    int a[n];
    printf("Enter Array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==flag)
        {
            temp = 1;
            pos = i;
        }
    }
    if(temp==1)
    {
        printf("Element found \n ");
        printf("Pos is %d",pos);
    }
    else if(temp==0){
        printf("Not found");
    }
}