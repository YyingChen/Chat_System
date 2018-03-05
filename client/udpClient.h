#ifndef _UDP_SERVER_
#define _UDP_SERVER_

#include<iostream>
#include<vector>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string>
#include<map>
#include<stdlib.h>
#include<algorithm>
#include<unistd.h>

#include"log.h"

class udpClient
{
    public:
        udpClient(const std::string _srv_ip,const int &_srv_port);
        void initClient();
         int recvData(std::string &outString);
         int sendData(const std::string &inString);
         void addUser(std::string &_friend);
         void delUser(std::string &_friend);
         ~udpClient();
         std::vector<std::string> flist;
    private:
        udpClient(const udpClient&);//防拷贝，不加引用会发生死循环
    private:
         int sock;
         std::string server_ip;
         int server_port;

};
#endif
