#include<iostream>

#include <mysql.h>

#include "spdlog/spdlog.h"
#include "MySqlConnector.h"

#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "libmysql.lib")

void test()
{
	std::cout << "test begin." << std::endl;
	MySqlConnector::instance().initialize("localhost", "root", "cr1921189869", "haroldqq");
	MySqlConnector::instance().insert_user("admin","Administrator","admin");
	std::cout << "test end." << std::endl;
}

int main(int argc, char* argv[])
{
	test();

	return 0;
}   
