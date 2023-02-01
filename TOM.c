#include<stdio.h>

int main(){
    int n,m;
    printf("Enter n:");
    scanf("%d",&n);
    printf("Enter m:");
    scanf("%d",&m);
    int a[n][m];
    int b[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Entered Matrix is: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Transpose is: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b[i][j]=a[j][i];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",b[i][j]); 
       }
       printf("\n");  
    }
    return 0;
}   