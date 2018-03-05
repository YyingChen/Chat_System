#ifndef _UDP_SERVER_
#define _UDP_SERVER_

#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string>
#include<map>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include"log.h"
#include"data_pool.h"
#include"dataType.h"

class udpServer
{
    public:
        udpServer(const std::string _ip,const int& _port);
        void initServer();
         int recvData(std::string &outString);
         int sendData(const std::string &inString,struct sockaddr_in &remote,socklen_t &len);
          int brocast();
        ~udpServer();
    private:
        udpServer(const udpServer&);//防拷贝，不加引用会发生死循环
         void addUser(const struct sockaddr_in &remote);
         void delUser(const struct sockaddr_in &remote);
    private:
         int sock;
          std::string ip;
        //ip一般情况下是唯一的(点分十进制)，转化为整形也是唯一的
        int port;
        std::map<in_addr_t,struct sockaddr_in> user_list;
            //k是ip地址(sin_sddr.s_addr)，v是socket上远端的信息

        data_pool pool;//数据池
};
#endif
