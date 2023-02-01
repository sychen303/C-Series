#include<stdio.h>

int main(){
    int n,min,max;
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    min=max=array[0];
    for(int i=0;i<n;i++)
    {
        if(array[i]<min)
        {
            min = array[i];
        }   
    }
    printf("Min is %d \n",min);
    for(int i=0;i<n;i++)
    {
        if(array[i]<min)
        {
            max = array[i];
        }
    }
    printf("Max is %d \n",max);
    return 0;
}