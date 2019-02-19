#pragma once
#include "../../tars/util/include/util/tc_thread.h"

using namespace tars;

namespace lesliefishtest
{
    class TestThread : public TC_Thread, public TC_ThreadLock
    {
    public:
        static void test()
        {
            try
            {
                TestThread testThread;
                testThread.start();
                testThread.terminate();
                testThread.getThreadControl().join();
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << endl;
            }
        }

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

        void runTask()
        {
            for (size_t i = 0; i < 5; i++)
            {
                std::cout << "run the task" << endl;
            }
        }

    protected:
        virtual void run()
        {
            while (!m_hasTerminate)
            {
                runTask();

                {
                    TC_ThreadLock::Lock sync(*this);
                    timedWait(1000);
                }
            }
        }

    protected:
        bool m_hasTerminate;
    };
}