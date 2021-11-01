#include <iostream>
#include <string>
#include <glog/logging.h>
#include <direct.h>

// ref: https://zhuanlan.zhihu.com/p/99552958



static void MakeDir(const char* dir_path)
{
    // if this folder not exist, create a new one.
    if (access(dir_path, 0) != 0)
    {
        printf("[INFO] directory %s will be created.", dir_path);
        std::cout << std::endl;
        mkdir(dir_path);
    }
    else
    {
        printf("[WARNING] directory %s existed.", dir_path);
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[])
{
    const char* LOG_DIR = "logs";
    MakeDir(LOG_DIR);

    FLAGS_log_dir    = LOG_DIR;
    FLAGS_logbufsecs = 0;

    google::InitGoogleLogging(argv[0]);

    LOG(INFO) << "info test";       //输出一个Info日志
    LOG(WARNING) << "warning test"; //输出一个Warning日志
    LOG(ERROR) << "error test";     //输出一个Error日志

    // conditional log => if(condition){LOG(...)...}
    int num_cookies = 20;
    LOG_IF(INFO, num_cookies > 10) << "Got lots of cookies";

    LOG_EVERY_N(INFO, 10) << "Got the " << google::COUNTER << "th cookie"; // google::COUNTER 记录该语句被执行次数，从1开始，在第一次运行输出日志之后，每隔 10 次再输出一次日志信息

    int size = 2048;
    LOG_IF_EVERY_N(INFO, (size > 1024), 10) << "Got the " << google::COUNTER
                                            << "th big cookie"; //上述两者的结合，不过要注意，是先每隔 10 次去判断条件是否满足，如果滞则输出日志；而不是当满足某条件的情况下，每隔 10 次输出一次日志信息

    LOG_FIRST_N(INFO, 20) << "Got the " << google::COUNTER << "th cookie"; //当此语句执行的前 20 次都输出日志，然后不再输出


    google::ShutdownGoogleLogging();

    return 0;
}
