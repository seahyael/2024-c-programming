#include <stdio.h>

int main(){
    int size; // 크기
    int stars, blank1, blank2; // , 1 , 2 별의 갯수 빈칸 의 갯수 빈칸 의 갯수
    int i, j; // 반복문을 위한 변수

    scanf("%d",&size);

    for(i = 0; i<size; i++){
        for(j = 0; j<i; j++){
            printf(" ");
        }
        printf("*");
        for(j = 0; j<(size-i-1)*2; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
    }

    for(i = 0; i<size; i++){
        for(j = 0; j<size*2; j++){
            printf("*");
        }
        printf("\n");
    }

    for(i = 0; i<size; i++){
        for(j = 0; j<i; j++){
            printf(" ");
        }
        for(j = 0; j<(size-i)*2; j++){
            printf("*");
        }
        printf("\n");
    }

    for(j = 0; j<size*2; j++){
            printf("*");
        }
    return 0;
}