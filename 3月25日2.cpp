方法一：
#include <iostream>

using namespace std;
void swap(char*& x, char*& y)//这里是x和y作为gm,ga的引用
{
    char *t = x;
    x = y;
    y = t;
}

int main()
{
    char *gm="good morning";
    char *ga="good afternoon";
    cout<<"½»»»Ç°"<<"gm="<<gm<<" "<<"ga="<<ga<<endl;
    swap(gm, ga);//字符串可以赋值给变量//
    cout <<"½»»»ºó"<<"gm="<< gm<<" "<<"ga="<<ga << endl;
    system("pause");
    return 0;
} 


方法二：
#include<iostream>
#include<string.h>
using namespace std;
void SwapPointer(char *p,char*q)
{
   char temp;
   int n1=strlen(p);
   int n2=strlen(q);
 
   if(n1>n2)
   {
	   for(int i=0;i<n2;i++)
	   {
		   temp=p[i];
		   p[i]=q[i];
		   q[i]=temp;
	   }
	   for(int i=n2;i<n1;i++)
	   {
		   q[i]=p[i];
	       p[i]='\0';
	   }
   }
   else
   {
	    for(int i=0;i<n1;i++)
	   {
		   temp=p[i];
		   p[i]=q[i];
		   q[i]=temp;
	   }
	   for(int i=n1;i<n2;i++)
	   {
		   p[i]=q[i];
	       q[i]='\0';
	   }
   }
}
int main(){
	char *gm="good morning";
	char *gf="good afternoon";
	cout<<"修改前"<<"gm="<<gm<<" "<<"gf="<<gf<<endl;
	swap(gm,gf);
	cout<<"修改前"<<"gm="<<gm<<" "<<"gf="<<gf<<endl;
}
