#include "common.h"
#include "dbconn.h"

int login(char *str1, char *str2){

	if(login_check(str1, str2) == 2){
		return 1; // 관리자
	}

	if(login_check(str1, str2) == 1){
		return 1; // 일반 회원
	}

	return 0;
}
