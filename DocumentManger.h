#ifndef CIRCLE_H
#define CIRCLE_H

#include<stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include<sstream>
#include<iostream>
#include <dirent.h>
#include <fstream>
using namespace std;

class DocumentManager {                         //DocumentManger 文件管理类

private:
    char *path;
    char *newpath;
public:
    DocumentManager();                         //构造函数1
    DocumentManager( char *path);              //构造函数2

    void setNewpath( char* newpath);
    void setPath( char* path);
    void displayTips();                            //命令提示行

    int make_dir(const char *path, mode_t mode);   //创建文件夹
    int change_dir(const char *path);              //改变路径
    int remove_dir(const char* path);              //移除文件夹
    int get_file_size_time(const char *filename);  //获取文件的信息
    DIR * open_dir(const char *path);              //打开文件夹
    void read_dir(const char *path, bool ListAllFiles);    //读取文件夹
    int copy_dir(const char *filename, const char *newfilename);   //拷贝文件夹

};

#endif
