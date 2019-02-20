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
        explicit TestThread();
        
    private:
        // 终止线程
        void terminate();
        // 执行实际任务
        void runTask();

    protected:
        virtual void run();

    private:
        bool m_hasTerminate; // 是否终止

    // test part
    public:
        static void test();
    };
}