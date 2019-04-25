#include "DocumentManger.h"

DocumentManager::DocumentManager() {
    this->path = NULL;
}
DocumentManager::DocumentManager(char *path) {
    this->path = path;
}


void DocumentManager::setNewpath(char* newpath) {
    this->newpath = newpath;
}

void DocumentManager::setPath(char* path) {           //储存现有路径
    this->path = path;
}

void DocumentManager::displayTips() {                 //展示tip
    cout << "please input commands as the following: " << endl;
    cout << "0.mkdir [path]创建目录" << endl;
    cout << "1.chdir [path]改变当前目录" << endl;
    cout << "2.rmdir [path]删除当前目录" << endl;
    cout << "3.opendir [path]打开目录" << endl;
    cout << "4.readdir [path]仅仅读文件" << endl;
    cout << "5.lldir [path]得到文件信息" << endl;
    cout << "5.copy [path] [newPath]拷贝" << endl;
    cout << "7.exit退出" << endl;
}

int DocumentManager::make_dir(const char *path, mode_t mode){
    if (mkdir(path,mode) != 0) {                       //创建文件
        cerr << "make dir fail" << endl;
    } else {
        cout << "make dir success" << endl;
    }
    return 0;
}

int DocumentManager::get_file_size_time(const char *filename)
{
    struct stat statbuf;                               //得到文件相关信息
    if (stat(filename, &statbuf) == -1) {
        cerr << "Get stat on" << filename << "  Error: " << endl;
        cerr << strerror(errno) << endl;//打出错误信息
    }
    if (S_ISDIR(statbuf.st_mode)) {
    }//是否是一个目录
    if (S_ISREG(statbuf.st_mode)) {
        cout << filename << " size:" << statbuf.st_size << " bytes"
                << " modified at " << ctime(&statbuf.st_mtime) << endl;
    }//判断是否是一个常规文件，并打出文件大小，最后一次更改时间

    return 0;
}

int DocumentManager::change_dir(const char *path ){   //change the dir
    this->path=(char*)path;
    if (chdir(path) != 0) {
        cout << "change dir fail" << endl;
    } else {
        cout << "change dir success" << endl;
    }
    return 0;
}

int DocumentManager::remove_dir(const char* path){    //移除文件夹
    DIR *dirp=opendir(path);
    if(dirp==NULL){                                   //打开文件夹失败
        perror(path);                                 //输出错误的原因
        return 0;
    }
    struct dirent *entry;
    int ret;
    while (1) {
        entry = readdir(dirp);
        if (entry == NULL) {                          //若父目录为空，直接退出循环
            break;
        }
        if(strcmp(".",entry->d_name)==0||strcmp("..",entry->d_name)==0){
            continue;
        }
        char buf[80];
        snprintf(buf,80,"%s/%s",path,entry->d_name);  //重构子目录
        ret=remove(buf);                              //delete these files
        if(ret==-1){
            if(errno==ENOTEMPTY){                     //删除失败
                remove_dir(buf);
                continue;
            }
            perror(buf);                              //输出失败的原因
            return 0;
        }

    }

    closedir(dirp);
    ret=rmdir(path);                                  //删除空文件
    if(ret==-1){
        perror(path);
    }
    else{
        cout<<"remove dir success!"<<endl;
    }
    return 0;
}

DIR * DocumentManager::open_dir(const char *path) {
    DIR *dirp=opendir(path);                          //打开文件
    if (dirp!= NULL) {
        cout << "open dir success" << endl;
    }
    else{
        cerr<<"Open Directory"<<path<<"  Error: "<<endl;
        cerr<<strerror(errno)<<endl;
    }
    closedir(dirp);                                    //关闭文件
    return dirp;
}

void DocumentManager::read_dir(const char *path,bool JustListFileName)
{
    DIR *dirp=opendir(path);
    struct dirent *direntp;
    static char dot[] = ".", dotdot[] = "..";
    char buf[80];
    while ((direntp = readdir(dirp)) != NULL) {
        if (strcmp(direntp->d_name, dot) && strcmp(direntp->d_name, dotdot)) {
            if (JustListFileName) {                  //仅仅阅读文件
                cout << direntp->d_name << endl;
            } else {
                sprintf(buf, "%s/%s", path, direntp->d_name);
                if (get_file_size_time(buf) == -1)          //得到文件信息
                    break;
            }
        }
    }
    closedir(dirp);                                 //关闭文件
}

int DocumentManager::copy_dir(const char *filename, const char *newfilename) {
    struct stat cur_file;
    stat(filename, &cur_file);

    if (S_ISDIR(cur_file.st_mode)) {               //路径是文件夹
        DIR *cur_dir;
        dirent *cur_ent;
        int errnum = 0;

        if ((cur_dir = opendir(filename)) == NULL){
            return 1;
        }
        if (access(newfilename, F_OK)){          //文件夹不存在，创建这个目标文件夹
            errnum |= mkdir(newfilename, S_IRWXU);
        }
        while ((cur_ent = readdir(cur_dir)) != NULL)    //递归，复制子目录
            if (strcmp(cur_ent->d_name, ".") && strcmp(cur_ent->d_name, "..")) {
                errnum |= copy_dir(((string)filename + "/" + cur_ent->d_name).c_str(),
                        ((string)newfilename + "/" + cur_ent->d_name).c_str());
            }
        closedir(cur_dir);                       //关闭文件
        return errnum;
    } 
    else {                                    //路径是文件名
        if (filename == newfilename){           //若两个路径相同则视为无效，退出
            return 0;
        }
        fstream fsin, fsout;                   //拷贝文件
        fsin.open(filename,ios::in | ios::binary);
        fsout.open(newfilename, ios::out |ios::binary);
        fsout << fsin.rdbuf();
        return 1;
    }
}
