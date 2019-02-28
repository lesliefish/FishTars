#pragma once

#include "../../tars/util/include/tc_mysql.h"
#include <iostream>

using namespace tars;
using namespace std;

namespace lesliefishtest
{
    class MySqlTest
    {
    public:
        void testQuery()
        {
            TC_Mysql::MysqlData data{};
            string strSql("select * from tarsMysql");
            data = m_mysql.queryRecord(strSql);
        }


    private:
        TC_Mysql m_mysql;

    };
}
