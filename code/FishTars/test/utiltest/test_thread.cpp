#include "test_thread.h"
#include <thread>

namespace lesliefishtest
{
    TestThread::TestThread()
        : m_hasTerminate(false)
    {

    }

    void TestThread::terminate()
    {
        m_hasTerminate = true;
        {
            TC_ThreadLock::Lock sync(*this);
            notifyAll();
        }
    }

    /****************************************!
     * @brief  实际执行的任务
     * @return void  
     ****************************************/ 
    void TestThread::runTask()
    {
        std::cout << "run the task" << endl;

        // 休眠三秒后结束线程
        std::this_thread::sleep_for(std::chrono::seconds(3));

        // 执调用终止结束线程执行
        std::cout << "end the task" << endl;
        terminate();
    }

    /****************************************!
     * @brief  实现run纯虚函数
     * @return void  
     ****************************************/ 
    void TestThread::run()
    {
        while (!m_hasTerminate)
        {
            runTask(); // 执行任务

            {
                TC_ThreadLock::Lock sync(*this);
                timedWait(500);
            }
        }
    }

    /****************************************!
     * @brief  静态测试函数
     * @return void  
     ****************************************/ 
    void TestThread::test()
    {
        try
        {
            TestThread testThread;
            testThread.start();		// 启动线程

            cout << "thread id : " << testThread.getThreadControl().id() << endl; // 线程id

            testThread.getThreadControl().join(); // 并入主线程
        }
        catch (const std::exception& ex)
        {
            cout << ex.what() << endl;
        }
    }

}
