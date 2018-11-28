#include "common.h"
#include "menu.h"

void menu(){

	int input;
	int log_check;
	char str1[10];
	char str2[20];
	while(1){
		system("clear");
		printf("1.로그인 2.회원가입 3.종료\n");
		printf("입력 : ");
		scanf("%d",&input);

		if(input==1){
			system("clear");
			printf(">>로그인<<\n");
			printf("아이디 입력 : ");
			scanf("%s",str1);
			printf("비밀번호 입력 : ");
			scanf("%s",str2);

			//관리자 및 회원 로그인 
			log_check=login(str1,str2);
			if(log_check==1){
				printf(">>관리자 로그인 완료<<\n");
				admit_menu();
			}
			else if(log_check==2){
				printf(">>회원 로그인 완료<<\n");
				member_menu();
			}
			else{
				printf(">>로그인 실패<<\n");
				sleep(2);
			}

		}
		else if(input==2){
			system("clear");
			printf(">>회원가입<<\n");
			join();
			sleep(2);
		}
		else if(input==3){
			system("clear");
			printf(">>종료<<\n");
			break;
		}
		else{
			printf(">>잘못된 입력<<");
			
			system("clear");
		}
	}
}
