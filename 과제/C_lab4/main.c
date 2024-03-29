#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c006.h"
#include "c006.c"

int main() {
    int no = 0;
    struct clothes* clist[100];
    int menu = 0;

    no = loadData(clist);

    while(1)
	{
		printf("\n[1]옷장 보기 [2]검색 [3]추가 [4]수정 [5]삭제 [6]저장 [0]프로그램 종료\n> 무엇을 도와드릴까요? ");
		scanf("%d",&menu);

        if(menu==1){
            callClothes(clist,no);
        }
        else if(menu==2){
            findClothes(clist,no);
        }
        else if(menu==3){
            no = createClothes(clist,no);
        }
        else if(menu==4){
            updateClothes(clist,no);
        }
        else if(menu==5){
            no = deleteClothes(clist,no);
        }
        else if(menu==6){
            saveChannels(clist,no);
        }
        else {
            break;
        }
    }
    return 0;
}