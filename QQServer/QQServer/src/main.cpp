#include<iostream>

#include <mysql.h>

#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "libmysql.lib")

int main(int argc, char* argv[])
{
	MYSQL* mysql = new MYSQL();
	//初始化mysql  
	mysql_init(mysql);
	//返回false则连接失败，返回true则连接成功  
	if (!(mysql_real_connect(mysql, "localhost", "root", "cr1921189869", "haroldqq", 0, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去  
	{
		printf("Error connecting to database:%s\n", mysql_error(mysql));
		}
	else
	{
		printf("Connected...\n");
			}

	delete mysql;
	return 0;
}   
