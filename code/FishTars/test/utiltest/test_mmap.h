/** @file    test_mmap.h 
 *  @date    2019/02/24 22:05
 *
 *  @brief   内存映射测试
 *  		 
 *  @author  yu
 *  @contact ylesliefish@gmail.com 
 */ 

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
        
        /************************************!
         * @brief  // 创建
         * @param  size_t n 文件长度
         * @return void
         ************************************/
        void create(size_t n)
        {
            TC_Mmap mmap;
            cout << "create mmap" << endl;
            mmap.mmap("mmap.dat", n);
            mmap.munmap();
            cout << "create mmap OK" << endl;
        }

        /************************************!
         * @brief  向这块内存写数据
         * @param  const string & s 写入的字符串
         * @return void
         ************************************/
        void write(const string &s)
        {
            TC_Mmap mmap;
            cout << "write mmap" << endl;
            mmap.mmap("mmap.dat", 1000);
            memcpy(mmap.getPointer(), s.c_str(), s.length());

            sleep(100); // 多等会便于比较测试结果

            mmap.munmap();
        }
        
        /************************************!
         * @brief  // 读取文件中内容
         * @return void
         ************************************/
        void read()
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
                TC_Option option; //命令行解析对象
                TestMMap testMMap{};
                // 解析命令输入
                option.decode(argc, argv); 

                int pagesize = sysconf(_SC_PAGESIZE);

                cout << "pagesize:" << pagesize << endl;

                // 命令行输入--test=create 表示创建这么个文件
                if (option.getValue("test") == "create") 
                {
                    size_t n = 50;
                    testMMap.create(n);
                }
                // 命令行输入--test=write --c=2019年2月24日20:26:52 表示写入c对应数据 即"2019年2月24日20:26:52"
                else if (option.getValue("test") == "write")
                {
                    testMMap.write(option.getValue("c"));
                }
                // 命令行输入--test=read 表示读取共享内存中的数据
                else if (option.getValue("test") == "read") 
                {
                    testMMap.read();
                }
            }
            catch (exception &ex)
            {
                cout << ex.what() << endl;
            }
        }
    };
}