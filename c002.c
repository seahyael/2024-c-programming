#include <stdio.h>

int main(){

    int person[4][3]; // 4 3 개 층별 개 호실의 점호 인원 수 
    int sum[3]; // ( , , ) 점호 인원 수 합계 남 여 전체
    float ratio[3]; // ( , , ) 점호 인원 수 비율 남 여 전체
    int i, j; // 반복문을 위한 변수

    printf("Check room (Men)\n");
    for(i=1; i<3; i++){
        for(j=1;j<4;j++){
            printf("Room #%d0%d > ",i,j);
            scanf("%d",&person[i][j]);
            sum[0] += person[i][j];
        }
    }
    ratio[0] = sum[0]*100/24.00;

    sum[1] = 0;
    printf("Check room (Women)\n");
    for(i=3; i<5; i++){
        for(j=1;j<4;j++){
            printf("Room #%d0%d > ",i,j);
            scanf("%d",&person[i][j]);
            sum[1] += person[i][j];
        }
    }
    ratio[1] = sum[1]*100/24.00;

    sum[2] = sum[0] + sum[1];
    ratio[2] = sum[2]*100/48.00;

    printf("Check Result\n");
    printf("Men: %d/24 (%.1f\%)\n",sum[0],ratio[0]);
    printf("Women: %d/24 (%.1f\%)\n",sum[1],ratio[1]);
    printf("Total: %d/48 (%.1f\%)",sum[2],ratio[2]);

    return 0;
}