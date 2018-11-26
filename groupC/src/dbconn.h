#ifndef __DBCONN_H__
#define __DBCONN_H__

#include <mysql.h>

MYSQL *conn;

void initDB();
MYSQL *connectDB();
void disconnectDB()
int login_check(char *, char *);
int str_check(char *);
void insert_Id_Pw(char *, char *);

MYSQL *conn;


#endif
