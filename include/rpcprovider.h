#pragma once
#include "google/protobuf/service.h"
#include <memory>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <unordered_map>
#include "logger.h"
#include "rpcheader.pb.h"

//框架提供的专门服务发布rpc服务的网络对象类
class RpcProvider
{
public:
    //框架提供外部使用，可以发布rpc方法的函数接口
    void NotifyService(google::protobuf::Service *service);

    //启动rpc服务节点，开始提供rpc远程网络调用服务；
    void Run();


private:
    //组合了TcpServer；
    std::unique_ptr<muduo::net::TcpServer> m_tcpserverPtr;
    //组合EventLoop
    muduo::net::EventLoop m_eventloop;
    //服务类型信息
    struct ServiceInfo
    {
        google::protobuf::Service *m_service; //保存服务对象
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor*> m_methodMap; //
    };
    //存储注册成功的服务对象和其服务方法的所有信息
    std::unordered_map<std::string, ServiceInfo> m_serviceMap;

    //新的socket连接回调
    void OnConnection(const muduo::net::TcpConnectionPtr&);
    //读写事件回调
    void OnMessage(const muduo::net::TcpConnectionPtr&,muduo::net::Buffer*, muduo::Timestamp);
    //Closure的回调操作，用于序列化rpc的响应和网络发送
    void SendRpcResponse(const muduo::net::TcpConnectionPtr&, google::protobuf::Message*);
};