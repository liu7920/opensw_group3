#include "common.h"

void member_menu(){

	int i;

	while(1){
		printf("1.게임 시작 2.랭크 보기 3.친구 추가 4.친구 목록 5.친구 삭제 6.회원 정보 수정 7.로그아웃 \n");
		printf("입력 : ");
		scanf("%d",&i);
		if(i==1){
			printf(">>게임 시작<<\n");
		}
		else if(i==2){
			printf(">>랭크 보기<<\n");
		}
		else if(i==3){
			printf(">>친구 추가<<\n");
		}
		else if(i==4){
			printf(">>친구 목록<<\n");
		}
		else if(i==5){
			printf(">>친구 삭제<<\n");
		}
		else if(i==6){
			printf(">>회원 정보 수정<<\n");
		}
		else if(i==7){
			printf(">>로그아웃<<\n");
			break;
		}

	}

	return ;
}
