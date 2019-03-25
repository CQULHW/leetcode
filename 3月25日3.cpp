#include<iostream>
#include<cstring>
using namespace std;

char *reverse(char const *list,const int size){
    char *result=new char[size];
    for(int i=0,j=size-1;i<size;i++,j--){
        result[j]=list[i];
    }
    return result;
}
int printArray(char const *list,const int size){
    for(int i=0;i<size;i++)
        cout<<list[i]<<" ";
}
int main(){
    int size;
    char list[]={'h','e','l','l','o'};
    size=sizeof(list)/sizeof(list[0]);
    printArray(list,size);
    cout<<endl;
    char *pList=reverse(list,size);
    printArray(pList,size);
    delete[]pList;
}