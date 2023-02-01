#include<stdio.h>

int main(){
    int n,m,add;
    printf("Enter the number of rows for the matrices: "); //taking input of rows for both matrices
    scanf("%d %d",&n,&m);
    int arr1[n];                                           //defining first array
    int arr2[m];                                           //defining second array
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);                              //taking input of first array through looping
    }
    for(int i=0;i<m;i++){
        scanf("%d",&arr2[i]);                              //taking input of second array through looping
    }
    printf("Data Stored \n");
    for(int i=0;i<n;i++){
        printf("%d",arr1[i]);                              //printing values of first array through looping
        printf("\t");
    }
    printf("\n");
    for(int i=0;i<m;i++){
        printf("%d",arr2[i]);                              //printing values of second array through looping
        printf("\t");
    }
    printf("\n");
    printf("Added matrix is: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){                              //adding values of matrices using loops
            if(i==j){                                      //checking if the index is same of not
                add = arr1[i]+arr2[j];                     //if index is same then adding the values
                printf("%d \t",add);
            }
        }
    }
    return 0;
    
}