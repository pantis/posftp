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
        } else if (strcmp(command, "rm") == 0) {
            bzero(command, SIZEOFBUFFER);
            cin >> command;
            ftp.dele(command);
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "!rm") == 0) {
            bzero(command, SIZEOFBUFFER);
            cin >> directory;
            strcpy(command, "rm ");
            strcat(command, directory);
            system(command);
            bzero(command, SIZEOFBUFFER);
        }  else if (strcmp(command, "!touch") == 0) {
            bzero(command, SIZEOFBUFFER);
            cin >> directory;
            strcpy(command, "touch ");
            strcat(command, directory);
            system(command);
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "put") == 0) {
            bzero(command, SIZEOFBUFFER);
            cin >> command;
            ftp.put(command);
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "get") == 0) {
            bzero(command, SIZEOFBUFFER);
            cin >> command;
            ftp.get(command);
            bzero(command, SIZEOFBUFFER);
        } else if (strcmp(command, "quit") == 0) {
            ftp.quit();
            exit(0);
        } else if (strcmp(command, "?") == 0) {
            cout << "pwd    zistenie aktualneho praconeho adresara na serveri" << endl;
            cout << "!pwd   zistenie aktualneho praconeho adresara na lokalnom PC" << endl;
            cout << "cd     zmenime aktualny pracovny adresar na serveri" << endl;
            cout << "!cd    zmenime aktualny pracovny adresar na lokalnom PC" << endl;
            cout << "ls     vypise adresarove informacie na serveri" << endl;
            cout << "!ls    vypise adresarove informacie na lokalnom PC" << endl;
            cout << "mkdir  vytvara adresar na serveri" << endl;
            cout << "!mkdir vytvara adresar na serveri na lokalnom PC" << endl;
            cout << "rmdir  vymaze prazdny adresar na serveri" << endl;
            cout << "!rmdir vymaze prazdny adresar na lokalnom PC" << endl;
            cout << "rm     vymaze subor alebo adresar na serveri" << endl;
            cout << "!rm    vymaze subor alebo adresar na lokalnom PC" << endl;
            cout << "!touch vytvori subor na lokalnom PC" << endl;
            cout << "put    upload suboru na server" << endl;
            cout << "get    download suboru zo servera" << endl;
            cout << "quit   zastavi aplikaciu" << endl;
        }
    }

    return 0;
}