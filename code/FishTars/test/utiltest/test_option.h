/** @file    test_option.h 
 *  @date    2019/02/23 23:46
 *
 *  @brief   �������������в���
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
                // ֧��������ʽ�Ĳ���:  ./main.exe --name=value --with abc def
                TC_Option op;
                // ��������
                op.decode(argc, argv);

                // mp�д�ű�ʶ�����Ӧ�����Ķ�Ӧ��ϵ�����磺����--name=value�����name��value
                map<string, string> mp = op.getMulti();

                cout << "map:" << endl;
                cout << TC_Common::tostr(mp) << endl;

                // ���������Ĳ������� abc def
                vector<string> d = op.getSingle();
                cout << "vector:" << endl;
                cout << TC_Common::tostr(d) << endl;

                // ͨ��key ��ȡ value
                cout << "key abc's value is : " << op.getValue("abc") << endl;
            }
            catch (exception &ex)
            {
                cout << ex.what() << endl;
            }
        }
    };
}
