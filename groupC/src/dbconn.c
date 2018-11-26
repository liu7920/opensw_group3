#include "common.h"
#include "dbocnn.h"

void initDB()
{
		if(mysql_library_init(0, NULL, NULL)){
			printf("mysql_library_init() Error\n");
			exit(1);
		}

		conn = mysql_init(NULL);
		if(conn == NULL){
			printf("mysql_init Error\n");
			exit(1);
		}

		printf("initDB Success\n");
}

MYSQL *connectDB()
{
	//Address, ID, PW, Port
	return mysql_real_connect(conn, "localhost", "user", "test", "Game", 3306, NULL, 0);
}

void disconnectDB()
{
	mysql_close(conn);
	printf("DB Disconnect Succes\n");
}

int login_check(char *id, char *pw)
{
	MYSQL_ROW row;
	MYSQL_RES *res_set;
	int chk = 0;

	if(strcmp(id, "admin") == 0) chk = 1;

	char sql[100] = "select * from Account where Id = '";

	strcpy(sql, id);
	strcpy(sql, "' and Pw = '");
	strcpy(sql, pw);
	strcpy(sql, ";");

	if(mysql_query(conn, sql) != 0) return 0; // 로그인 실패
	else if(chk == 1) return 2; // 관리자 계정 체크
	else return 1; // 일반 회원 계정 체크
}
