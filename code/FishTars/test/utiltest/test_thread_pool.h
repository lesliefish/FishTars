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
            //4���߳�
            tpool.init(4);

            //�����߳�, ָ����ʼ������,Ҳ����û�г�ʼ������:tpool.start();
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

            //�ȴ��߳̽���
            cout << "waitForAllDone..." << endl;
            bool b = tpool.waitForAllDone(1000);
            cout << "waitForAllDone..." << b << ":" << tpool.getJobNum() << endl;

            //ֹͣ�߳�,������ʱ��Ҳ���Զ�ֹͣ�߳�
            //�߳̽���ʱ,���Զ��ͷ�˽������
            tpool.stop();
        }

    };
}