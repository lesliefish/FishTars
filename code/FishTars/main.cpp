#include <cstdio>
#include <thread>
#include <iostream>
#include "test/utiltest/test_mmap.h"

using namespace std;
using namespace tars;

int main(int argc, char* argv[])
{
    lesliefishtest::TestMMap::test(argc, argv);

    return 0;
}