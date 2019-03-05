#pragma once

#include "../../tars/util/include/tc_mysql.h"
#include <iostream>

using namespace tars;
using namespace std;

namespace lesliefishtest
{
    class TestMySql
    {
    public:
        TestMySql(const string& name)
            : m_tableName(name) 
        {}

        // 初始化 连接数据库
        void init()
        {
            m_mysql.init("127.0.0.1", "root", " ", "tarsMysql");
            m_mysql.connect();
        }

        // 创建表
        void createTable()
        {
            // 若有先drop
            string strDropSql = "DROP TABLE " + m_tableName;
            m_mysql.execute(strDropSql);

            string strSql = "CREATE TABLE " + m_tableName + " (name VARCHAR(20), sex VARCHAR(6), age INTEGER, addr VARCHAR(20))";
            m_mysql.execute(strSql);
        }

        // 插入数据
        void insert()
        {
            map<string, pair<TC_Mysql::FT, string> > m;
            m["name"] = make_pair(TC_Mysql::DB_STR, "lesliefish");
            m["sex"] = make_pair(TC_Mysql::DB_STR, "male");
            m["age"] = make_pair(TC_Mysql::DB_INT, "18");
            m["addr"] = make_pair(TC_Mysql::DB_STR, "hangzhou.");
            m_mysql.insertRecord(m_tableName, m);
        }

        // 查询
        void query()
        {
            TC_Mysql::MysqlData data{};
            {
                string strSql = "select * from " + m_tableName;
                data = m_mysql.queryRecord(strSql);
                for (size_t i = 0; i < data.size(); i++)
                {
                    cout << data[i]["name"] + "\t" << data[i]["sex"] + "\t" << data[i]["age"] + "\t" << data[i]["addr"] + "\t" << endl;
                }
            }
        }

        // 测试
        static void test()
        {
            TestMySql demo("timetogo");
            demo.init();
            demo.createTable();
            demo.insert();
            demo.query();
        }

    private:
        TC_Mysql m_mysql;
        string m_tableName;
    };
}
