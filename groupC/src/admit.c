#include "common.h"

void admit_menu(){

	int i;

	while(1){
		printf("1.공지사항 수정 2.메시지 보내기 3.회원 데이터 초기화 4.회원 삭제 5.관리자 비밀번호 변경 6.로그아웃\n");
		printf("입력 : ");
		scanf("%d",&i);
		if(i==1){
			printf(">>공지사항 수정<<\n");
		}
		else if(i==2){
			printf(">>메시지 보내기<<\n");
		}
		else if(i==3){
			printf(">>회원 데이터 초기화<<\n");
		}
		else if(i==4){
			printf(">>회원 삭제<<\n");
		}
		else if(i==5){
			printf(">>관리자 비밀번호 변경<<\n");
		}
		else if(i==6){
			printf(">>로그아웃<<\n");
			break;
		}
		//관지라 비밀번호 변경
		//회원 삭제
		//공지사항 수정
		//메시지
		//회원 데이터 초기화
		//로그아웃
	}
}
