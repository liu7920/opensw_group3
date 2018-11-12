#include <stdio.h>
#include <stdlib.h>

int login(char *str1, char *str2){

	char str_id[20];
	char str_pw[20];

	strcpy(str_id,"admit");
	strcpy(str_pw,"1234");

	if(strcmp(str1,str_id)==0){
		if(strcmp(str2,str_pw)==0){
			printf("관리자 로그인 성공\n");
			return 1;
		}
		else{
			printf("비밀번호 입력 실패\n");
			return 0;
		}
	}
	else{
		printf("아이디 입력 실패\n");
		return 0;
	}
}
