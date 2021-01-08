//
// Created by patom on 7. 1. 2021.
//

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#ifndef POSFTP_FTPCLIENT_H
#define POSFTP_FTPCLIENT_H
#define SIZEOFBUFFER 1024

using namespace std;

class ftpclient {
public:
    ftpclient();
    ~ftpclient();
    void socket_create(int &sock, const char* server_ip_add, const unsigned int server_port);
    void send_request(int sock, const char* command);
    void get_reply(int sock);
    void login(const char *server_ip_add, const unsigned int server_port);
    void quit();
    void pwd();
    void pasvMode(char* ip_add, int* port);
    void ls();
    void cd(char* command);
    void mkdir(char* directory);
private:
    int sock_conn;
    int sock_data;
    char buffer[1024];
    char reply_msg[1024];
};


#endif //POSFTP_FTPCLIENT_H