//옷장관리
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c006.h"
//#include <time.h>
//랜덤 코디 기능 추가시

char TNAME[8][30] = {"아우터","레이어드 아우터","긴팔","반팔","나시","바지","치마","원피스"};
//char SNAME[5][3] = {"봄","여름","가을","겨울","사계절"};

int loadData(struct clothes* c[]){
    int no = 0;
    FILE* file;

    file = fopen("closet.txt", "r");
    while(!feof(file)){
        struct clothes* t = (struct clothes*)malloc(sizeof(struct clothes));
        fscanf(file, "%d %s %s",&t->type,t->color,t->name);
        c[no] = t;
        no++;
    }
    fclose(file);

    printf("현재 %d개의 옷이 옷장에 있어요!\n",no);
    return no;
}

//[1]옷장 보기
void callClothes(struct clothes* c[], int num){
    printf("\n>> 세아님의 옷장 속 옷들을 불러올게요!\n");
    for(int i = 0; i<num; i++){
        if(i == 0){
            printf("[%s]\n",TNAME[0]);
        }
        else if(c[i-1]->type != c[i]->type){
            printf("[%s]\n",TNAME[c[i]->type]);}
        printf("%s %s\n",c[i]->color, c[i]->name);
    }
}


//[2]검색
void searchClothes(struct clothes*c[],char search[], int num){
    for(int i = 0; i<num; i++){
        if(strstr(c[i]->name, search) != NULL){
            printf("%s %s\n",c[i]->color, c[i]->name);
        }
        else if(strstr(c[i]->color, search) != NULL){
            printf("%s %s\n",c[i]->color, c[i]->name);
        }
    }
}

void findClothes(struct clothes*c[], int num){
    char search[100];
    int count = 0;
    printf("\n>> 옷장 속에 어떤 옷이 있는지 찾아드릴게요!\n");
    printf(">>> 검색어를 입력해주세요: ");
    scanf("%s",search);

    for(int i = 0; i<num; i++){
        if(strstr(c[i]->name, search) != NULL){count++;}
        else if(strstr(c[i]->color, search) != NULL){count++;}
    }

    if(count == 0){
        printf("검색어와 일치하는 옷을 찾지 못했어요.\n");
    }
    else {printf("%d개의 옷을 찾았어요!\n",count);}

    searchClothes(c,search,num);
}

//[3]추가
int addCloth(struct clothes*c[], struct clothes*t, int index, int num){
    if(index == num){
        c[index] = t;
        return num+1;
    }

    struct clothes*s;
    s = (struct clothes*)malloc(sizeof(struct clothes));
    s = c[index];
    c[index] = t;
    t = s;
    index++;
    return addCloth(c,t,index,num);
}

int createClothes(struct clothes* c[], int num){
    struct clothes* t;
    t = (struct clothes*)malloc(sizeof(struct clothes));
    printf("\n>> 옷장에 새 옷을 추가할게요!\n>>> 새 옷의 종류를 골라주세요.\n");
    printf("   1.아우터/2.레이어드 아우터/3.긴팔/4.반팔/5.나시/6.바지/7.치마/8.원피스\n");
    printf("새 옷의 종류: ");
    scanf("%d",&t->type);
    while(t->type > 8 || t->type == 0){
        printf("!!숫자가 올바르지 않아요.\n새 옷의 종류: ");
        scanf("%d",&t->type);
    }
    t->type -= 1;
    printf(">>> 색과 이름을 입력해주세요(ex 검정 후드): ");
    scanf("%s %s",t->color,t->name);

    for(int i = 0; i<num; i++){
        if(c[i]->type == t->type && c[i+1]->type != t->type){
            addCloth(c,t,i+1,num);
            break;
        }
    }
    printf("%s %s이(가) 추가되었어요!\n",t->color,t->name);
    
    return num+1;
}

//[4]수정
void listClothes(struct clothes* c[], int num){
    for(int i = 0; i<num; i++){
        printf("%d. %s/ %s %s\n",i+1,TNAME[c[i]->type],c[i]->color, c[i]->name);
    }
}

int minusClothes(struct clothes*c[],int num, int delete){
    if(delete == num){
        return num-1;
    }
    else{
        c[delete] = c[delete+1];
        return minusClothes(c,num,delete+1);
    }
}

void updateClothes(struct clothes*c[], int num){
    struct clothes* t;
    t = (struct clothes*)malloc(sizeof(struct clothes));
    int update;
    printf("\n>> 옷의 정보를 수정할게요!\n");
    listClothes(c,num);
    printf(">>> 수정하고 싶은 옷의 번호를 입력해주세요: ");
    scanf("%d",&update);
    while(update>num){
        printf("!!숫자가 올바르지 않아요.\n수정하고 싶은 옷의 번호를 입력해주세요: ");
        scanf("%d",&update);
    }
    update -= 1;
    t = c[update];

    printf("%d. %s/ %s %s\n",update+1,TNAME[c[update]->type],c[update]->color, c[update]->name);

    int what;
    printf("   1.종류/2.색상/3.이름\n무엇을 수정할까요? ");
    scanf("%d",&what);

    while(what>3 || what == 0){
        printf("!!숫자가 올바르지 않아요.\n무엇을 수정할까요? ");
        scanf("%d",&what);
    }

    if(what == 1){
        printf("   1.아우터/2.레이어드 아우터/3.긴팔/4.반팔/5.나시/6.바지/7.치마/8.원피스\n");
        printf("새로운 종류를 입력해주세요: ");
        scanf("%d",&t->type);
        t->type -= 1;
        num = minusClothes(c, num, update);
        for(int i = 0; i<num; i++){
            if(c[i]->type == t->type && c[i+1]->type != t->type){
                addCloth(c,t,i+1,num);
                break;
            }
        }
    }
    else if(what == 2){
        printf("새로운 색상을 입력해주세요: ");
        scanf("%s",t->color);
        c[update] = t;
    }
    else if(what == 3){
        printf("새로운 이름을 입력해주세요: ");
        scanf("%s",t->name);
        c[update] = t;
    }

    printf("수정되었어요!\n");
}

//[5]삭제
int deleteClothes(struct clothes*c[],int num){
    int delete;
    printf("\n>> 옷의 정보를 삭제할게요!\n");
    listClothes(c,num);
    printf(">>> 삭제하고 싶은 옷의 번호를 입력해주세요: ");
    scanf("%d", &delete);
    while(delete>num){
        printf("!!숫자가 올바르지 않아요.\n삭제하고 싶은 옷의 번호를 입력해주세요: ");
        scanf("%d",&delete);
    }
    delete -= 1;

    int sure;
    printf("%d. %s/ %s %s\n",delete+1,TNAME[c[delete]->type],c[delete]->color, c[delete]->name);
    printf("정말로 삭제할까요(예:0/아니요:1)? ");
    scanf("%d",&sure);
    if(sure == 1){
        return num;
    }
    else if(sure == 0){
        printf("삭제되었어요!\n");
        return minusClothes(c,num,delete);
    }
    return 0;
}
 
//[6]저장
void saveChannels(struct clothes* c[], int size){
    printf("\n>>지금까지의 변경사항들을 저장할게요! \n");
	FILE* file;
	file = fopen("closet.txt", "w");
	for(int i=0; i<size; i++){
        fprintf(file, "%d %s %s\n",c[i]->type,c[i]->color,c[i]->name);
	}
	fclose(file);	
    printf("저장되었어요! \n");
}

//(#추천)
//날씨별 추천, 계절별 추천, 상황별 추천
//현재 날씨, 계절, 상황 입력
//그 날씨, 계절, 상황에 해당하는 옷 출력