#pragma once

#include"Log.hpp"
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<unistd.h>
#include<strings.h>
#include<cerrno>
#include<string>
#include<unordered_map>
#include<memory>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
using std::cout;
using std::endl;

#define SIZE 1024

class UdpServer
{
public:
    UdpServer(uint16_t port, std::string ip = "")
        :_port(port)
        ,_ip(ip)
        ,_sock(-1)
    {}
    bool initServer()
    {
        //  1. 创建套接字
        _sock = socket(AF_INET, SOCK_DGRAM, 0);
        if(_sock < 0)
        {
            logMessage(FATAL, "%d:%s\n", errno, strerror(errno));
            exit(2);
        }
        // 2. bind: 将用户设置的ip和port在内核中和我们当前的进程强关联
        struct sockaddr_in local;
        bzero(&local, sizeof local);
        local.sin_family = AF_INET;
        local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str());
        local.sin_port = htons(_port);

        if(bind(_sock, (struct sockaddr*)&local, sizeof local) < 0)
        {
            logMessage(FATAL, "%d:%s\n", errno, strerror(errno));
            exit(2);
        }
        logMessage(NORMAL, "init udp server done...%s\n", strerror(errno));
        return true;
    }
    void start()
    {
        char buffer[SIZE];
        while(true)
        {
            struct sockaddr_in peer;
            bzero(&peer, sizeof peer);
            socklen_t len = sizeof peer;
            ssize_t s = recvfrom(_sock, buffer, sizeof buffer - 1, 0, (struct sockaddr*)&peer, &len);
            if(s > 0)
            {
                buffer[s] = 0;
                uint16_t cli_port = ntohs(peer.sin_port);
                std::string cli_ip = inet_ntoa(peer.sin_addr);
                cout << "client say# " << buffer << endl; 
            }
        }
    }
    ~UdpServer()
    {
        if(_sock >= 0) close(_sock);
    }
private:
    std::string _ip;
    uint16_t _port;
    int _sock;
};
