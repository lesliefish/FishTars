/** @file    test_thread.h 
 *  @date    2019/02/19 21:41
 *
 *  @brief   tars线程测试
 *  		 
 *  @author  yu
 *  @contact ylesliefish@gmail.com 
 */ 

#pragma once
#include "../../tars/util/include/util/tc_thread.h"

using namespace tars;

namespace lesliefishtest
{
    class TestThread : public TC_Thread, public TC_ThreadLock
    {
    public:
        explicit TestThread()
        {
            m_hasTerminate = false;
        }

        void terminate()
        {
            m_hasTerminate = true;
            {
                TC_ThreadLock::Lock sync(*this);
                notifyAll();
            }
        }

        /************************************!
         * @brief  实际执行的任务
         * @return void
         ************************************/
        void runTask()
        {
			std::cout << "run the task" << endl;
        }

    protected:
        /************************************!
         * @brief  实现基类的纯虚函数
         * @return void
         ************************************/
        virtual void run()
        {
            while (!m_hasTerminate)
            {
                runTask(); // 执行任务

                {
                    TC_ThreadLock::Lock sync(*this);
                    timedWait(1000);
                }
            }
        }

    protected:
        bool m_hasTerminate; // 是否终止



	public:
		/************************************!
		 * @brief  静态测试函数
		 * @return void
		 ************************************/
		static void test()
		{
			try
			{
				TestThread testThread;
				testThread.start();		// 启动线程

				std::this_thread::sleep_for(std::chrono::seconds(5)); // 睡眠5秒

				testThread.terminate(); // 终止
				testThread.getThreadControl().join(); // 并入主线程
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
			}
		}
    };
}