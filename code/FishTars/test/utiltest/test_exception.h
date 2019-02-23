#pragma once
#include "../../tars/util/include/tc_ex.h"

namespace lesliefishtest
{
    using namespace tars;
    class ExceptionTest
    {
    public:
        explicit ExceptionTest() {};

    public:
        // 直接抛出异常
        static void test()
        {
            throw TC_Exception("can't be called in the same thread");
        }
    };
}