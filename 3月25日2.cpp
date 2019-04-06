#include <iostream>

using namespace std;
void swap(char*& x, char*& y)
{
    char *t = x;
    x = y;
    y = t;
}

int main(int argc, char* argv[])
{
    char *gm="good morning";
    char *ga="good afternoon";
    cout<<"½»»»Ç°"<<"gm="<<gm<<" "<<"ga="<<ga<<endl;
    swap(gm, ga);//字符串可以赋值给变量//
    cout <<"½»»»ºó"<<"gm="<< gm<<" "<<"ga="<<ga << endl;
    system("pause");
    return 0;
} 
