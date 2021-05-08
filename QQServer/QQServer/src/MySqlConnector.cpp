#include "MySqlConnector.h"

MySqlConnector::MySqlConnector() : m_mysql_(nullptr), m_is_init_(false)
{
    std::cout << "MySqlConnector ctor." << std::endl;
}

MySqlConnector::~MySqlConnector()
{
    if(nullptr != m_mysql_)
    {
        if (m_is_init_)
            mysql_close(m_mysql_);
    }
    std::cout << "MySqlConnector dtor." << std::endl;
}

MySqlConnector &MySqlConnector::instance()
{
    static MySqlConnector instance;
    return instance;
}

bool MySqlConnector::initialize(const string &host, const string &username, const string &password,const string &dbname)
{
    if (m_is_init_)
        mysql_close(m_mysql_);

    m_mysql_ = mysql_init(m_mysql_);
    m_mysql_ = mysql_real_connect(m_mysql_, host.c_str(), username.c_str(), password.c_str(), dbname.c_str(), 0, nullptr, 0);
    if(m_mysql_)
    {
        mysql_query(m_mysql_, "set names utf8");
        m_is_init_ = true;
        return true;
    }
    else
    {
        spdlog::error("Connect MySQL database at {0} failed:{1}", host.c_str(), mysql_error(m_mysql_));
        mysql_close(m_mysql_);
        return false;
    }
}

bool MySqlConnector::verify_user(const string &account, const string &password)
{
    if(!m_is_init_)
    {
        spdlog::error("Please initialize database first.");
        return false;
    }

    string querySql = "select account, password from user where account = \"" + account + "\" and password = \"" + password + "\"";

    if(!mysql_query(m_mysql_, querySql.data()))
    {
        MYSQL_RES* result = mysql_store_result(m_mysql_);
        if(result && mysql_num_rows(result))
        {
            MYSQL_ROW row = mysql_fetch_row(result);
            if (string(row[0]) == account && string(row[1]) == password)
                return  true;
        }
    }

    return false;
}

bool MySqlConnector::insert_user(const string &account, const string &nickname, const string &password)
{
    if(!m_is_init_)
    {
        spdlog::error("Please initialize database first.");
        return false;
    }

    string insertSql = "insert into user(account, nickname, password, register_time) values(\"" + account + "\"," + "\"" + nickname + "\"," + "\"" + password + "\", NOW())";
      if(mysql_query(m_mysql_, insertSql.data()))
    {
        spdlog::error("Insert user failed: {}", mysql_error(m_mysql_));
        return false;
    }

    return true;
}
