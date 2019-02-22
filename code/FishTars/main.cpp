#include <cstdio>
#include <thread>
#include <iostream>
#include "test/utiltest/test_thread.h"
#include "test/utiltest/test_singleton.h"
#include "test/utiltest/test_thread_pool.h"

using namespace std;
using namespace tars;

int main()
{
    lesliefishtest::TestThreadPool::test();

    return 0;
}