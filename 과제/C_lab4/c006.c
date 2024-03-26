//옷장관리

//#structure clothes
//no
//name
//color
//type  
//상태
//입은 횟수
//(추천 계절)
//(char 추천계절 = 봄 , 여름, 가을, 겨울, 사계절)
//(추천 날씨)
//맑은날, 비, 눈, 흐린날
//(tpo)
//블루데이, 수업, 동아리, 교회, 수요일, 벚꽃사진

//char cloth type = 아우터, 치마, 원피스, 바지, 긴팔, 반팔, (신발), (악세사리)
//char 상태 = 낡음, 얼룩짐, good, best

//옷장.txt
//type no, color + name (ex 청자켓, 핑크 셔츠), 상태 no, 입은 횟수

//#load data
//파일 읽고, 변수에 각각 선언
//cloth 개수 파악, main에 return

//#create
//type 물어보고 그 타입에 추가
//if(i.type == 0 && i+1.type == 1){
//    new cloth.no == i+1
//    for(j = i+1~end){j.no +=1}
//}
//end+=1

//#read
//type 별로 정리
//color + name (ex 청자켓, 핑크 셔츠), 상태, 입은 횟수
//0.아우터
//0-1.청자켓, 상태 : 좋음, 입은 횟수 : 20회, 추천계절 : 봄, 가을
//0-2.바막, 좋음, 40회, 추천계절 : 겨울

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