#include<iostream>

#include <mysql.h>

#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "libmysql.lib")

int main(int argc, char* argv[])
{
	MYSQL* mysql = new MYSQL();
	//��ʼ��mysql  
	mysql_init(mysql);
	//����false������ʧ�ܣ�����true�����ӳɹ�  
	if (!(mysql_real_connect(mysql, "localhost", "root", "cr1921189869", "haroldqq", 0, NULL, 0))) //�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ  
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
