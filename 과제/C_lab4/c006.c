//옷장관리
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <time.h>
//랜덤 코디 기능 추가시

struct clothes{
    char name[100];
    char color[100];
    int type;
    //int season;
};

char TNAME[8][30] = {"아우터","레이어드 아우터","긴팔","반팔","나시","바지","치마","원피스"};
//(신발), (악세사리)
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

void listClothes(struct clothes* c[], int num){
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

//#create
//type 물어보고 그 타입에 추가
//if(i.type == 0 && i+1.type == 1){
//    new cloth.no == i+1
//    for(j = i+1~end){j.no +=1}
//}
//end+=1
int addCloth(struct clothes*c[], struct clothes*t, int index, int num){
    if(index == num){
        c[index] = t;
        return 0;
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
    printf("\n>>옷장에 새 옷을 추가할게요!\n>>>새 옷의 종류를 골라주세요.\n");
    printf("   1.아우터/2.레이어드 아우터/3.긴팔/4.반팔/5.나시/6.바지/7.치마/8.원피스\n");
    printf("새 옷의 종류: ");
    scanf("%d",&t->type);
    while(t->type > 8){
        printf("!!숫자가 올바르지 않아요.\n새 옷의 종류: ");
        scanf("%d",&t->type);
    }
    t->type -= 1;
    printf(">>>색과 이름을 입력해주세요(ex 검정 후드): ");
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

//#update
//no 선택
//수정할 부분 선택(1. 이름 2. 상태 3. 입은횟수 4.color)
//수정할 내용 입력
//udated.

//#delete
//no 선택
//error check (no가 없는 경우)
//더블 체크 (진짜 지울건지- yes/no)
//for(i = no+1~end){i.no += 1}
//end -= 1;

//#search
//어떤 변수로 search할건지 물어보기(이름, 색, 계절, 입은횟수 등)
//그 변수별 search 함수
//n clothes are found.
 
//#save
//옷장.txt에 변경사항 저장

//(#추천)
//날씨별 추천, 계절별 추천, 상황별 추천
//현재 날씨, 계절, 상황 입력
//그 날씨, 계절, 상황에 해당하는 옷 출력

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
            listClothes(clist,no);
        }
        else if(menu==3){
            no = createClothes(clist,no);
        }
        else {
            break;
        }
    }
}