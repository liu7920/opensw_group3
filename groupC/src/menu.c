#include <stdio.h>
void menu(){

	int input;
	int log_check;
	char str1[10];
	char str2[20];
	while(1){
		printf("1.로그인 2.회원가입 3.종료\n");
		printf("입력 : ");
		scanf("%d",&input);

		if(input==1){
			printf(">>로그인<<\n");
			printf("아이디 입력 : ");
			scanf("%s",str1);
			printf("비밀번호 입력 : ");
			scanf("%s",str2);
			//관리자 계정 id:admit pw:1234
			//회원계정
			log_check=login(str1,str2);
			if(log_check==1){
				printf(">>로그인 완료<<\n");
			}
			else{
				printf(">>로그인 실패<<\n");
			}

		}
		else if(input==2){
			printf(">>회원가입<<\n");
		}
		else if(input==3){
			printf(">>종료<<\n");
			break;
		}
		else{
			printf(">>잘못된 입력<<");
		}
	}
}
