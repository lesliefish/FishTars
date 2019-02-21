#include <cstdio>
#include <thread>
#include <iostream>
#include "test/utiltest/test_thread.h"
#include "test/utiltest/test_singleton.h"

using namespace std;
using namespace tars;

int main()
{
    //lesliefishtest::TestThread::test();
    lesliefishtest::TestSinglton::test();

    return 0;
}