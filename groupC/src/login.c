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

void join()
{
	char Id[100]="";
	char Pw[100]="";
	//id, pw
	system("clear"); //화면 clear

	printf("아이디 입력 : ");
	scanf("%s", Id);
	if(str_check(Id)){
		printf("비밀번호 입력 : ");
		scanf("%s", Pw);
		insert_Id_Pw(Id, Pw);
		printf("%s님 회원가입 완료", Id);
	}
	else printf("ID가 중복입니다.\n");

}
