#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "dbconn.h"

int main(void) {

	initDB(); // DB initialize
	if(connectDB(conn) != NULL) printf("DB Connect Success\n");  //DB 연
	mysql_set_character_set(conn, "utf-8"); //C->mysql 질의문 한글깨짐 방지
	menu();

	disconnectDB(); // DB 연결 해제
	return 0;
}
