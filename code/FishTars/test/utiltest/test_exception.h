#pragma once
#include "util/tc_ex.h"

namespace lesliefishtest
{
    using namespace tars;
    class ExceptionTest
    {
        explicit ExceptionTest() {};

    public:
        // ֱ���׳��쳣
        static void test()
        {
            throw TC_Exception("can't be called in the same thread");
        }
    };
}