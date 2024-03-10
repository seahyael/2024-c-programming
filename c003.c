#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
	char mnames[10][20]; // 남학생명단(최대 10명)
	int mroom[10];		// 남학생명단별 호실 배정 목록
	char wnames[10][20]; // 여학생명단(최대 10명)
	int wroom[10];		// 여학생명단별 호실 배정 목록
	int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
	int mcount=0, wcount=0; // 인원 합계 (남, 여)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("생활관 호실 배정 프로그램\n");
	printf("===========================================\n");
	while(1){
		printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}

int findRoom(int persons[5]){
// 이 곳에 생각 정리와 코드 구현
    while(1){
        //random 값 받기
        int ran = rand()%5+1;
        //빈방인지 확인
        if(persons[ran]==0||persons[ran]==1){
            persons[ran] += 1;
            return ran;
        }
        
        //if 빈방 return
        //else 다시
    }
   
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
// 이 곳에 생각 정리와 코드 구현

    printf("남학생 명단 (%d명)\n",mc);
    for(int i = 0; i<mc; i++){
        printf("%d. %s [%d호]\n",i+1,mn[i],mr[i]);
    }
    printf("여학생 명단 %d명\n",wc);
    for(int i = 0; i<wc; i++){
        printf("%d. %s [%d호]\n",i+1,wn[i],wr[i]);
    }
    printf("호실별 배정 명단\n");
        for(int j =0; j<5; j++){
            for(int k = 0; k<10; k++){
                if(100+(j+1) == mr[k]){
                    printf("10%d호 : %s\n",j+1,mn[k]);}
            }
        }

        for(int j =0; j<5; j++){
            for(int k = 0; k<10; k++){
                if(200+(j+1) == wr[k]){
                    printf("20%d호 : %s\n",j+1,wn[k]);}
            }
        }
}

