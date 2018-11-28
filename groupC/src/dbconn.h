#ifndef __DBCONN_H__
#define __DBCONN_H__

#include <mysql.h>

MYSQL *conn;

//DB 초기설정 및 연결, 해제 함
void initDB();
MYSQL *connectDB();
void disconnectDB();

//회원가입, 로그인 DB연동 함수
int login_check(char *, char *); // 로그인시 관리자, 일반회원 구분 함수
int str_check(char *); // 아이디 중복체크 함수
void insert_Id_Pw(char *, char *);

//공지사항 관련 함수
void print_Notice();
void print_Notice_admin();
void insert_Notice(char *);
void delete_Notice(char *);

//어드민, 유저 정보 수정 및 탈퇴 함수
void modifiy_admin(char *);
void modifiy_user(char *);
void leave_user(char *);

MYSQL *conn;


#endif
