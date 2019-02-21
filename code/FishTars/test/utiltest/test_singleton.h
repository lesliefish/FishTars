#pragma once

#include "../../tars/util/include/util/tc_singleton.h"

using namespace std;
using namespace tars;

namespace lesliefishtest
{
    class TestCreateStaticObj : public TC_Singleton<TestCreateStaticObj, CreateStatic, PhoneixLifetime>
    {
    public:
        TestCreateStaticObj()
        {
            cout << "TestCreateStaticObj()" << endl;
        }

        ~TestCreateStaticObj()
        {
            cout << "~TestCreateStaticObj()" << endl;
        }

    public:
        void test()
        {
            cout << " test TestCreateStaticObj" << endl;
        }
    };

    class TestUsingNewObj : public TC_Singleton<TestUsingNewObj, CreateUsingNew, PhoneixLifetime>
    {
    public:
        TestUsingNewObj()
        {
            cout << "TestUsingNewObj()" << endl;
        }

        ~TestUsingNewObj()
        {
            cout << "~TestUsingNewObj()" << endl;
        }
    public:
        void test()
        {
            cout << " test TestUsingNewObj" << endl;
        }
    };


    class TestSinglton 
    {
    public:
        static void test()
        {
            try
            {
                auto obj1 = TestCreateStaticObj::getInstance();
                obj1->test();
                auto obj11 = TestCreateStaticObj::getInstance();
                obj11->test();

                // 看变量所在区 声明一个static int变量，将变量地址对比粗略确定对象所在区域
                static int staticValue = 0;
                cout << "staticValue address: \t\t" << &staticValue << endl;
                cout << "TestCreateStaticObj address: \t" << obj1 << endl;

                cout << endl;
                auto obj2 = TestUsingNewObj::getInstance();
                obj2->test();
                auto obj22 = TestUsingNewObj::getInstance();
                obj22->test();

                // 看变量所在区 声明一个堆上的变量，将变量地址对比粗略确定对象所在区域
                int* heapValue = new int[1];
                cout << "heapValue address: \t\t" << heapValue << endl;
                cout << "TestUsingNewObj address: \t" << obj2 << endl;
                delete[] heapValue; heapValue = nullptr;
            }
            catch (const std::exception& ex)
            {
                cout << ex.what() << endl;
            }
        }
    };

    /*
    yu@ubuntu:~/projects/FishTars/bin/x64/Debug$ ./FishTars.out
    TestCreateStaticObj()
     test TestCreateStaticObj
     test TestCreateStaticObj
    staticValue address:            0x60a4dc
    TestCreateStaticObj address:    0x60a4e0

    TestUsingNewObj()
     test TestUsingNewObj
     test TestUsingNewObj
    heapValue address:              0x205d030
    TestUsingNewObj address:        0x205d010
    ~TestUsingNewObj()
    ~TestCreateStaticObj()
    */
}