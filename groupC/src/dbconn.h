#ifndef __DBCONN_H__
#define __DBCONN_H__

#include <mysql.h>

void initDB();
MYSQL *connectDB();

MYSQL *conn;

#endif
