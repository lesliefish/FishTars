#pragma once

#include "../../tars/util/include/util/tc_thread_pool.h"
#include "../../tars/util/include/util/tc_common.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace tars;

namespace lesliefishtest
{
    class TestThreadPool
    {
    public:
        static void test()
        {
            TC_ThreadPool tpool;
            //4个线程
            tpool.init(4);

            //启动线程, 指定初始化对象,也可以没有初始化对象:tpool.start();
            tpool.start();

            string bid;
            for (int i = 0; i < 10000; i++)
            {
                bid = TC_Common::tostr(i);
                cout << bid << endl;


                tpool.exec([&] 
                {
                    cout << "index = " << i << ",bid = " << bid << endl;
                });
            }

            //等待线程结束
            cout << "waitForAllDone..." << endl;
            bool b = tpool.waitForAllDone(1000);
            cout << "waitForAllDone..." << b << ":" << tpool.getJobNum() << endl;

            //停止线程,析够的时候也会自动停止线程
            //线程结束时,会自动释放私有数据
            tpool.stop();
        }

    };
}