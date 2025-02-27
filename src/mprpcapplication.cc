#include "mprpcapplication.h"
#include <iostream>
#include <unistd.h>

MprpcConfig MprpcApplication::m_config;

void ShowArgsHelp(){
    std::cout<<"format: command -i <configfile>" << std::endl;
}

void MprpcApplication::Init(int argc, char **argv){
    if(argc<2)
    {
        ShowArgsHelp();
        exit(EXIT_FAILURE);
    }

    int c=0;
    std::string config_file;
    while((c = getopt(argc, argv, "i:")) != -1) //c是int类型
    {
        switch(c)
        {
        case 'i': //正常解析 ./example -i config.conf
            config_file = optarg;
            break;
        case '?': //无效参数 ./example -x 
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        case ':': //缺少参数 ./example -i 
            ShowArgsHelp();
            exit(EXIT_FAILURE);
        default:
            break;
        }
    }

    //开始加载配置文件
    m_config.LoadConfigFile(config_file.c_str());

    std::cout <<"rpcserverip:"<<m_config.Load("rpcserverip") << std::endl;
    std::cout<<"rpcserverport:"<<m_config.Load("rpcserverport") << std::endl;
    std::cout<<"zookeeperip:"<<m_config.Load("zookeeperip") << std::endl;
    std::cout <<"zookeeperport:"<<m_config.Load("zookeeperport") << std::endl;
};



MprpcApplication& MprpcApplication::GetInstance(){
    static MprpcApplication instance;  // **静态局部变量**
    //static 局部变量 (static MprpcApplication instance;) 在第一次调用时创建，并在程序生命周期内存在。
    //之后每次调用 GetInstance()，都会返回 同一个实例，不会重新创建。
    return instance;
};

MprpcConfig& MprpcApplication::GetConfig()
{
    return m_config;
}

