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
    cout<<"����ǰ"<<"gm="<<gm<<" "<<"ga="<<ga<<endl;
    swap(gm, ga);
    cout <<"������"<<"gm="<< gm<<" "<<"ga="<<ga << endl;
    system("pause");
    return 0;
} 