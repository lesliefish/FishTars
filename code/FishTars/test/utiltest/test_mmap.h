#pragma once

#include "../../tars/util/include/tc_mmap.h"
#include "../../tars/util/include/tc_option.h"
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

namespace lesliefishtest
{
    using namespace tars;

    class TestMMap
    {
    public:
        // 创建
        void testCreate(size_t n)
        {
            TC_Mmap mmap;
            cout << "create mmap" << endl;
            mmap.mmap("mmap.dat", n);
            mmap.munmap();
            cout << "create mmap OK" << endl;
        }

        // 写入内存
        void testWrite(const string &s)
        {
            TC_Mmap mmap;
            cout << "write mmap" << endl;
            mmap.mmap("mmap.dat", 1000);
            memcpy(mmap.getPointer(), s.c_str(), s.length());

            sleep(100);

            mmap.munmap();
        }

        // 读取内存
        void testRead()
        {
            TC_Mmap mmap;
            cout << "read mmap" << endl;
            mmap.mmap("mmap.dat", 1000);

            string s;
            s.assign((char*)mmap.getPointer(), mmap.getSize());
            mmap.munmap();

            cout << s << endl;
        }


        // 静态测试函数
        static void test(int argc, char *argv[])
        {
            try
            {
                TC_Option option;
                TestMMap testMMap{};
                // 解析命令输入
                option.decode(argc, argv); 

                int pagesize = sysconf(_SC_PAGESIZE);

                cout << "pagesize:" << pagesize << endl;

                // 命令行输入--test=create 表示创建这么个区
                if (option.getValue("test") == "create") 
                {
                    size_t n = 50;
                    testMMap.testCreate(n);
                }
                // 命令行输入--test=write --c=2019年2月24日20:26:52 表示写入c对应数据 即"2019年2月24日20:26:52"
                else if (option.getValue("test") == "write")
                {
                    testMMap.testWrite(option.getValue("c"));
                }
                // 命令行输入--test=read 表示读取共享内存中的数据
                else if (option.getValue("test") == "read") 
                {
                    testMMap.testRead();
                }
            }
            catch (exception &ex)
            {
                cout << ex.what() << endl;
            }
        }
    };
}