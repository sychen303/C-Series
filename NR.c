#include<stdio.h>
#include<math.h>

int main()
{
    float a,root;
    scanf("%f",&a);
    if(a<0){
    root = sqrt((a*-1));
    printf("%.2f i",root);
    }
    else{
        root = sqrt(a);
        printf("%f",root);
    }
    
    

    return 0;
}