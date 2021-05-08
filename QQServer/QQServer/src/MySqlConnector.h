#pragma once

#include "includes.h"

using std::string;
class MySqlConnector
{
private:
	MySqlConnector();
	~MySqlConnector();

public:
	MySqlConnector(const MySqlConnector &) = delete;
	MySqlConnector &operator=(const MySqlConnector &) = delete;

	static MySqlConnector &instance();

	bool initialize(const string& host, const string& username, const string& password, const string& dbname);

	bool verify_user(const string &account, const string &password);

	bool insert_user(const string &account, const string & nickname, const string &password);

private:
	MYSQL *m_mysql_;
	bool m_is_init_;
};
