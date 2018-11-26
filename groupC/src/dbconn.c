#include "common.h"
#include "dbconn.h"

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
	return mysql_real_connect(conn, "localhost", "user", "test", "game", 3306, NULL, 0);
}

void disconnectDB()
{
	mysql_close(conn);
	printf("DB Disconnect Succes\n");
}

int login_check(char *id, char *pw)
{
	int chk = 0;

	if(strcmp(id, "admin") == 0) chk = 1;

	char sql[100] = "select * from Account where Id = '";

	strcat(sql, id);
	strcat(sql, "' and Pw = '");
	strcat(sql, pw);
	strcat(sql, "';");

	printf("%s\n", sql);

	if(mysql_query(conn, sql) != 0){
		printf(" 여기\n");
		return 0; // 로그인 실패
	}
	else if(chk == 1) return 2; // 관리자 계정 체크
	else return 1; // 일반 회원 계정 체크
}

int str_check(char *str)
{ // ID 중복 체
	char sql[100] = "select * from Account where Id = '";

	strcat(sql, str);
	strcat(sql, ";");

	if(mysql_query(conn, sql) != 0) return 1; // 중복 없음
	else return 0; //중복
}

void insert_Id_Pw(char *Id, char *Pw)
{
	char sql[100] = "insert into Account values('";
	strcat(sql, Id);
	strcat(sql, "','");
	strcat(sql, Pw);
	strcat(sql, "',0);");
	printf("%s\n", sql);

	mysql_query(conn, sql);
}
