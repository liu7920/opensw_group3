#include "common.h"
#include "dbconn.h"

void admit_menu(){

	int i;
	char str[20],_str[200];

	while(1){
		printf("1.공지사항 수정 2.회원 데이터 초기화 3.관리자 비밀번호 변경 4.로그아웃\n");
		printf("입력 : ");
		scanf("%d",&i);
		if(i==1){
			while(1){
				printf(">>공지사항 수정<<\n");
				// 보여주기 예시
				// 1 ~~~~~~~~~~~
				// 2 ***********
				printf("1.추가 2.삭제 3.취소\n");
				scanf("%d",&i);
				if(i==1){
					printf("공지사항 추가 할 내용 입력 : ");
					scanf("%s",_str);
					// _str을 게시판에 추가 추가할때 넘버를 따로 줘야됨
				}
				else if(i==2){
					printf("삭제할 공지사항 번호 입력 : ");
					scanf("%d",&i);
					//번호에 해당하는 게시판 삭제
				}
				else if(i==3){
					printf("취소\n");
					break;
				}
				else{
					printf("잘못된 입력\n");
				}
			}
		}
		else if(i==2){
			printf(">>회원 데이터 초기화<<\n");
			//랭킹 초기화
		}
		else if(i==3){
			printf(">>관리자 비밀번호 변경<<\n");
			printf("비밀번호 입력 : ");
			scanf("%s",str);
			if(/*str == pw(db)*/){
				printf("새로운 비밀번호 입력 : ");
				scanf("%s",str);
				//str을 새로운 비밀번호로 db에 넣기
				printf("비밀번호 변경 완료\n");
			}
			else{ //틀리다면
				printf("입력 비밀번호가 틀립니다.\n");
			}
		}
		else if(i==4){
			printf(">>로그아웃<<\n");
			break;
		}
	}
}
