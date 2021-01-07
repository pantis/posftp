#include "ftpclient.h"
#include "ftpclient.cpp"

int main(int argc, char *argv[]) {
    ftpclient ftp;
    cout << "Welcome!" << endl;
    cout << "Type help for help :)" << endl;
    ftp.login("","", argv[1], atoi(argv[2]));
    ftp.pwd();
    ftp.quit();

    return 0;
}



