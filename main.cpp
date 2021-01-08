#include "ftpclient.h"
#include "ftpclient.cpp"

int main(int argc, char *argv[]) {
    ftpclient ftp;
    char command[SIZEOFBUFFER], directory[SIZEOFBUFFER];
    cout << "Welcome!" << endl;
    cout << "Type help for help :)" << endl;
    ftp.login(argv[1], atoi(argv[2]));

    while (1) {
        cout << "> ";
        cin >> command;
        if (strcmp(command, "pwd") == 0) {
            ftp.pwd();
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "!pwd") == 0) {
            system("pwd");
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "cd") == 0) {
            bzero(command, SIZEOFBUFFER);
            cin >> command;
            ftp.cd(command);
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "!cd") == 0) {
            bzero(command, SIZEOFBUFFER);
            cin >> command;
            chdir(command);
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "ls") == 0) {
            ftp.ls();
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "!ls") == 0) {
            system("ls");
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "mkdir") == 0) {
            bzero(command, SIZEOFBUFFER);
            cin >> command;
            ftp.mkdir(command);
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "!mkdir") == 0) {
            bzero(command, SIZEOFBUFFER);
            cin >> directory;
            strcpy(command, "mkdir ");
            strcat(command, directory);
            system(command);
            bzero(command, SIZEOFBUFFER);

        } else if (strcmp(command, "rmdir") == 0) {
            bzero(command, SIZEOFBUFFER);
            cin >> command;
            ftp.rmdir(command);
            bzero(command, SIZEOFBUFFER);

        } else if (strcmp(command, "!rmdir") == 0) {
            bzero(command, SIZEOFBUFFER);
            cin >> command;
            rmdir(command);
            bzero(command, SIZEOFBUFFER);

        } else if (strcmp(command, "quit") == 0) {
            ftp.quit();
            exit(0);
        }
    }

    return 0;
}