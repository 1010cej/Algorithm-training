在Linux中，通过socke文件描述符上的recvfrom函数和sendto函数可以实现UDP通信。

recvfrom函数用于接收UDP数据报，其原型如下：
```c++
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);

Copy code

- sockfd：socket文件描述符，用于标识一个套接字。
- buf：用于接收数据的缓冲区。
- len：缓冲区的大小。
- flags：接收操作的标志，默认为0。
- src_addr：用于存放数据报发送端的地址信息。
- addrlen：传入src_addr的长度，返回实际接收的地址长度。

sendto函数用于将数据报发送到指定的目的地，其原型如下：


ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen);

Copy code

- sockfd：socket文件描述符，用于标识一个套接字。
- buf：待发送的数据。
- len：数据的长度。
- flags：发送操作的标志，默认为0。
- dest_addr：数据报的目的地址。
- addrlen：目的地址的长度。

下面是一个简单的UDP通信案例，其中一个程序发送数据报，另一个程序接收数据报：

发送端代码（send.c）：


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[BUF_SIZE];

    // 创建socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址信息
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345);   // 设置服务器端口号
    serverAddr.sin_addr.s_addr = INADDR_ANY;   // 设置服务器IP地址

    // 读取用户输入的数据
    printf("Enter a message: ");
    fgets(buffer, BUF_SIZE, stdin);

    // 发送数据报到服务器
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    return 0;
}
```


接收端代码（recv.c）：
```c++

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen;
    char buffer[BUF_SIZE];

    // 创建socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址信息
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345);   // 设置服务器端口号
    serverAddr.sin_addr.s_addr = INADDR_ANY;   // 设置服务器IP地址

    // 绑定socket到服务器地址
    if (bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // 接收来自客户端的数据
    clientAddrLen = sizeof(clientAddr);
    recvfrom(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr*)&clientAddr, &clientAddrLen);

    // 打印接收到的数据
    printf("Received message: %s", buffer);

    return 0;
}
```



编译和运行程序：

```
$ gcc send.c -o send
$ gcc recv.c -o recv
$ ./recv   // 在一个终端中运行接收程序
$ ./send   // 在另一个终端中运行发送程序
```



在发送程序中输入一条消息后，该消息将通过UDP协议发送到接收程序。接收程序将打印出接收到的消息。注意，发送和接收程序所使用的端口号必须一致。
