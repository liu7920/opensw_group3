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
	MYSQL_ROW row;
	MYSQL_RES *res_set;

	if(strcmp(id, "admin") == 0) chk = 1;

	char sql[100] = "select Pw from Account where Id = '";

	strcat(sql, id);
	strcat(sql, "' and Pw = '");
	strcat(sql, pw);
	strcat(sql, "';");

	printf("%s\n", sql);

	if(mysql_query(conn, sql) != 0) return -1; // SQL Error
	else{
		res_set = mysql_store_result(conn);
		row = mysql_fetch_row(res_set);
		if(row == NULL) return 3; // 로그인 실패
		else if(strcmp(pw, row[0]) == 0){
			if(chk == 1) return 2; // 관리자
			else return 1; // 일반 회원
		}
	}
}

int str_check(char *str)
{ // ID 중복 체
	char sql[100] = "select Id from Account where Id = '";
	MYSQL_ROW row;
	MYSQL_RES *res_set;

	strcat(sql, str);
	strcat(sql, "';");

	if(mysql_query(conn, sql) != 0) return -1; // SQL Error
	else{
		res_set=mysql_store_result(conn);
		row=mysql_fetch_row(res_set);
		if(row == NULL) return 1;
		else return 0; // 중복 없
	}
}

void insert_Id_Pw(char *Id, char *Pw)
{
	char sql[100] = "insert into Account values('";
	strcat(sql, Id);
	strcat(sql, "','");
	strcat(sql, Pw);
	strcat(sql, "','0');");
	printf("%s\n", sql);

	mysql_query(conn, sql); // 회원가입 ID, PW를 DB에 Insert
}

void inesrt_Notice(char *str)
{
	char sql[100] = "inesrt into Notice(Text) values('";

	strcat(sql, str);
	strcat(sql, "');"
	printf("%s\n", sql);

	mysql_query(conn, sql); // 공지사항 추가
}

void delete_Notice(char *num)
{
	char sql[100] = "delete from Notice where Num = ";

	strcat(sql, num);
	strcat(sql, ";");

	mysql_query(conn, sql); // 공지사항 삭제
}

void modifiy_admin(char *str)
{
	char sql[100] = "select Pw from Account where Id = 'admin';"
	MYSQL_ROW row;
	MYSQL_RES *res_set;

	if(mysql_query(conn, sql) != 0) return -1; // SQL Error
	else{
		res_set=mysql_store_result(conn);
		row=mysql_fetch_row(res_set);
		if(row == NULL) return 1;
		else{
			if(strcmp(row[0], str) == 0){
				char temp[100]="";
				char sql2[100] = "update Account set Pw = '";

				printf("새로운 비밀번호 입력 : ");
				scanf("%s", temp);

				strcat(sql2, temp);
				strcat(sql2, "' where Pw = '");
				strcat(sql2, str);
				strcat(sql2, "';");

				mysql_query(conn,sql);
				printf("Admin 비밀번호 변경 완료\n");
			}
			else printf("기존 비밀번호 불일치\n");
		}
	}

}
