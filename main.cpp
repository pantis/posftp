#include "ftpclient.h"
#include "ftpclient.cpp"

int main(int argc, char *argv[]) {
    ftpclient ftp;
    char command[SIZEOFBUFFER];
    cout << "Welcome!" << endl;
    cout << "Type help for help :)" << endl;
    ftp.login(argv[1], atoi(argv[2]));

    while (1) {
        cout << "> ";
        cin >> command;
        if (strcmp(command, "pwd") == 0) {
            ftp.pwd();
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "cd") == 0) {
            bzero(command, SIZEOFBUFFER);
            cout << "Enter directory: ";
            cin >> command;
            ftp.cd(command);
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "ls") == 0) {
            ftp.ls();
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "quit") == 0) {
            ftp.quit();
            exit(0);
        }
    }

    return 0;
}