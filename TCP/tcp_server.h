#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <cstring>

using std::cin;
using std::cout;
class TCP
{
  public:
  TCP(uint16_t port)
        :_port(port)
        ,_ip("")
        ,listen_sock(-1)
    {}

   void init()
   {
      listen_sock = socket(AF_INET, SOCK_STREAM, 0);
      struct sockaddr_in addr;
      addr.sin_addr.s_addr = INADDR_ANY;
      addr.sin_family = AF_INET;
      addr.sin_port = htons(_port);

      bind(listen_sock, (struct sockaddr *)&addr, sizeof addr);

      listen(listen_sock, 20);
   }

   void start()
   {
      struct sockaddr_in peer;
      bzero(&peer, sizeof peer);
      socklen_t len = sizeof peer;
      int sock = accept(listen_sock, (struct sockaddr *)&peer, &len);
      char buffer[1024];
      while (true)
      {
         ssize_t s = recv(sock, buffer, sizeof buffer - 1, 0);

         if(s>0){
            buffer[s] = 0;
          printf("say client = %s \n",buffer);

         }
      }
   }

   ~TCP(){
       if(listen_sock<0) close(listen_sock);
   }

private:
   int listen_sock;
   std::string _ip;
   int _port;
};
