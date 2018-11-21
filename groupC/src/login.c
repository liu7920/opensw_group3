#include "common.h"

int login(char *str1, char *str2){

	//str1 = 아이디
	//str2 = 비밀번호

	if(strcmp(str1,)==0){//관리자 비교
		if(strcmp(str2,)==0){
			return 1;
		}
	}
	else if(strcmp(str2,)==0){//회원 비교
		if(strcmp(str2,)==0){
			return 2;
		}
	}

	return 0;
}
