/** @file    test_option.h 
 *  @date    2019/02/23 23:46
 *
 *  @brief   解析程序命令行参数
 *  		 
 *  @author  yu
 *  @contact ylesliefish@gmail.com 
 */ 

#pragma once

#include "../../tars/util/include/tc_option.h"
#include "../../tars/util/include/tc_common.h"
#include <iterator>
#include <iostream>
#include <sys/time.h>

using namespace tars;
using namespace std;

namespace lesliefishtest
{
    class TestOption
    {
    public:
        static void test(int argc, char *argv[])
        {
            try
            {
                // 支持以下形式的参数:  ./main.exe --name=value --with abc def
                TC_Option op;
                // 解析参数
                op.decode(argc, argv);

                // mp中存放标识和其对应参数的对应关系，例如：对于--name=value，存放name和value
                map<string, string> mp = op.getMulti();

                cout << "map:" << endl;
                cout << TC_Common::tostr(mp) << endl;

                // 解析单个的参数，如 abc def
                vector<string> d = op.getSingle();
                cout << "vector:" << endl;
                cout << TC_Common::tostr(d) << endl;

                // 通过key 获取 value
                cout << "key abc's value is : " << op.getValue("abc") << endl;
            }
            catch (exception &ex)
            {
                cout << ex.what() << endl;
            }
        }
    };
}
