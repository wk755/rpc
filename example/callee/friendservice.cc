#include <iostream>
#include <string>
#include "friend.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include <vector>
#include "logger.h"


class FriendService : public fixbug::FriendServiceRpc //protobuf生成的FriendServiceRpc，继承自FriendService::继承Service
//实现RPC远程调用逻辑
{
public:
    //本地调用
    std::vector<std::string> GetFriendsList(uint32_t userid)
    {
        std::cout <<"do GetFriendsList service! userid:" << userid << std::endl;
        std::vector<std::string> vec;
        vec.push_back("gao yang");
        vec.push_back("liu hong");
        vec.push_back("wang shuo");
        return vec;
    }

    // 重写基类方法, 实现远程RPC调用
    void GetFriendsList(::google::protobuf::RpcController* controller,
                       const ::fixbug::GetFriendsListRequest* request,
                       ::fixbug::GetFriendsListResponse* response,
                       ::google::protobuf::Closure* done)
    {
        uint32_t userid = request->user_id();
        std::vector<std::string> friendsList = GetFriendsList(userid);
        response->mutable_result()->set_errcode(0); //填写result的值，mutable可修改的
        response->mutable_result()->set_errmsg(""); 
        //将name添加给response里的friendlist
        for (std::string &name : friendsList)
        {
            std::string *p = response->add_friends();
            *p = name;
        }
        done->Run(); //执行回调操作，返回响应
    }
};

int main(int argc, char **argv)
{
    LOG_INFO("first log message!");
    LOG_ERR("%s:%s:%d", __FILE__, __FUNCTION__, __LINE__);
    // 调用框架的初始化操作
    MprpcApplication::Init(argc, argv);

    // provider是一个rpc网络服务对象。把UserService对象发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new FriendService());

    // 启动一个rpc服务发布节点   Run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();

    return 0;
}