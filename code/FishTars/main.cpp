#include <cstdio>
#include <thread>
#include <iostream>
#include "tars/util/include/util/tc_thread.h"
#include "test/utiltest/test_thread.h"

using namespace std;
using namespace tars;

int main()
{
    cout << ("hello!") << endl;

    lesliefishtest::TestThread::test();

    return 0;
}