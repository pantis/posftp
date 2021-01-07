//
// Created by patom on 7. 1. 2021.
//

#include "ftpclient.h"

void ftpclient::socket_create(int &sock, const char *server_ip_add, const unsigned int server_port) {
    struct sockaddr_in serv_addr;
    struct hostent *server;
    server = gethostbyname(server_ip_add);
    if (server == NULL) {
        cerr << "Error, no such host" << endl;
        return;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(
            (char *) server->h_addr,
            (char *) &serv_addr.sin_addr.s_addr,
            server->h_length
    );
    serv_addr.sin_port = htons(server_port);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cerr << "Error creating socket" << endl;
        return;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        cerr << "Error connecting to socket" << endl;
        return;
    }
}



void ftpclient::get_reply(int sock) {
    int rep_length;
    rep_length = recv(sock, reply_msg, 1024, 0);
    if( rep_length < 0 ) {
        cout << "Receive failed" << endl;
    }
    cout << reply_msg << endl;
    bzero(reply_msg, SIZEOFBUFFER);
}

void ftpclient::login(const char *server_ip_add, const unsigned int server_port) {

    char usrCmd[SIZEOFBUFFER];
    char passCmd[SIZEOFBUFFER];
    char username[1024] = "";
    char password[1024] = "";

    socket_create(sock_conn, server_ip_add, server_port);

    get_reply(sock_conn);

    cout << "Enter your username: ";
    cin >> username;
    strcpy(usrCmd, "USER ");
    strcat(usrCmd, username);
    strcat(usrCmd, "\r\n");

    send_request(sock_conn, usrCmd);

    get_reply(sock_conn);

    if (strcmp(username, "anonymous") != 0) {
        cout << "Enter your password: ";
        cin >> password;
        strcpy(passCmd, "PASS ");
        strcat(passCmd, password);
        strcat(passCmd, "\r\n");

        send_request(sock_conn, passCmd);

        get_reply(sock_conn);
    }
}

void ftpclient::quit() {
    send_request(sock_conn, "QUIT\r\n");
    get_reply(sock_conn);
    close(sock_conn);
}

void ftpclient::pwd() {
    send_request(sock_conn, "PWD\r\n");
    get_reply(sock_conn);
}


void ftpclient::send_request(int sock, const char* command) {
    int req_length;
    strcpy(buffer, command);
    req_length = send(sock, buffer, strlen(command), 0);
    if( req_length < 0 ) {
        cout << "Send failed" << endl;
    }
    bzero(buffer, SIZEOFBUFFER);
}

ftpclient::ftpclient() {
    sock_conn = 0;
    sock_data = 0;
}

ftpclient::~ftpclient() {
}

