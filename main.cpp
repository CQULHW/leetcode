#include "DocumentManager.cpp"
#include<stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include<sstream>
#include<iostream>
#include <dirent.h>
#include <fstream>
using namespace std;

int main(){

    DocumentManager documentmanger;              //创建对象

    documentmanger.displayTips();                //打出tips

    string input, command, path, newPath;
    int i;
    while (getline(cin, input)) {
        istringstream is(input);
        string s;                                //deal this inputs
        for (i = 0; is >> s; i++) {
            if (s.compare("exit") == 0) {        //退出
                exit(0);
            }
        }
        if (i != 2 & i != 3) {
            cerr << "your input is Illegal" << endl;
            continue;
        }
        istringstream temp(input);
        temp >> command >> path >> newPath;

        if (command.compare("mkdir") == 0) {     //command is mkdir
            const char* pa = path.c_str();
            documentmanger.make_dir(pa, 0755);
        }
        else if (command.compare("chdir") == 0) {//command is chdir
            const char* pa = path.c_str();
            documentmanger.change_dir(pa);

        }
        else if (command.compare("rmdir") == 0) {//command is rmdir
            const char* pa = path.c_str();
            documentmanger.remove_dir((char* )pa);
        }
        else if (command.compare("opendir") == 0) {//command is opendir
            const char* pa = path.c_str();
            documentmanger.open_dir((pa));
        }
        else if (command.compare("readdir") == 0) {//command is readdir
            const char* pa = path.c_str();
            documentmanger.read_dir(pa,1);
        }
        else if (command.compare("lldir") == 0) {//command is lldir
            const char* pa = path.c_str();
            documentmanger.read_dir(pa,0);
        }
        else if (command.compare("copy") == 0) { //command is copy
            const char* pa = path.c_str();
            const char* npa = newPath.c_str();
            documentmanger.copy_dir(pa, npa);
        }
    }
    return 0;
}