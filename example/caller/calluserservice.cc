#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"


int main(int argc, char **argv)
{
    //整个程序启动后，使用mrprpc框架使用rpc服务调用，一定要初始化
    MprpcApplication::Init(argc, argv);

    //演示调用远程发布的rpc方法Login
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());

    //rpc方法的请求参数
    fixbug::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");

    //rpc方法的响应
    fixbug::LoginResponse response;


    //发起rpc方法的调用 同步的rpc调用过程  MprpcChannel::callmethod
    MprpcController controller;
    stub.Login(&controller, &request, &response, nullptr); //RpcChannel->RpcChannel::callMethod 集中做
    if(controller.Failed()){
        std::cout << controller.ErrorText() << std::endl;
    }
    else{
        //依次rpc调用完成，读结果
        if(0 == response.result().errcode())
        {
            std::cout << "rpc login success:" << response.sucess() << std::endl;
        }
        else
        {
            std::cout << "rpc login error:" << response.result().errmsg() << std::endl;
        }
    }
    

    // 演示调用远程发布的rpc方法Register
    fixbug::RegisterRequest req;
    req.set_id(2000);
    req.set_name("mprpc");
    req.set_pwd("666666");
    fixbug::RegisterResponse rsp;

    // 以同步的方式发起rpc调用请求，等待返回结果
    stub.Register(nullptr, &req, &rsp, nullptr); 

    // 一次rpc调用完成，读调用的结果
    if (0 == rsp.result().errcode())
    {
        std::cout << "rpc register response success:" << rsp.sucess()<< std::endl;
    }
    else
    {
        std::cout << "rpc register response error : " << rsp.result().errmsg() << std::endl;
    }
    
    return 0;

}