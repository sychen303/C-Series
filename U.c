#include<stdio.h>
#include<math.h>

int main(){
    int order, stock;
    int credit;
    printf("Enter Stock: ");
    scanf("%d",&stock);
    printf("Enter Order: ");
    scanf("%d",&order);
    printf("Enter Credit: ");
    scanf("%d",&credit);

    if (stock>=order && credit == 0){
        printf("Okay");
    }
    if (stock>=order && credit == 1){
        printf("Nope");
    }






    return 0;
}