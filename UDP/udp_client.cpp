
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<unistd.h>
#include<strings.h>
#include<cerrno>
#include<string>
#include<unordered_map>
#include<memory>
#include<iostream>
using std::cout;
using std::cin;
const int MAX_SIZE = 1024;
int main()
{
     char buffer[MAX_SIZE];
     int sock_fd = socket(AF_INET,SOCK_DGRAM,0);
     if(sock_fd==0){
         perror("socket");
         exit(-1);
     }

     struct sockaddr_in UDPaddr;
     memset(&UDPaddr,0,sizeof(UDPaddr)); // 全部清 0
     UDPaddr.sin_family = AF_INET;
     UDPaddr.sin_port = htons(1234); // 端口设置
     UDPaddr.sin_addr.s_addr = htonl(INADDR_ANY);

     int ret = bind(sock_fd,(struct sockaddr*)&UDPaddr,sizeof(UDPaddr));
     if(ret==-1){
         perror("bind");
         exit(-1);
     }

     // 读取用户的输入
     printf("UDP user is \n");
     fgets(buffer,MAX_SIZE,stdin);
    
    // 发送数据报到服务器
    sendto(sock_fd,buffer,strlen(buffer),0,(struct sockaddr*)&UDPaddr,sizeof(UDPaddr));
    return 0;
}
