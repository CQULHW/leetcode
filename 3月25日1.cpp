#include<iostream>
#include<ctime>
using namespace std;

int top_Three(int nums[]){
    cout<<"最大三个整数"<<endl;
    int hold;
    for(int pass=1;pass<50;pass++)
        for(int m=0;m<=49-pass;m++)
            if(nums[m]>nums[m+1]){
                hold=nums[m];
                nums[m]=nums[m+1];
                nums[m+1]=hold;
            }
    cout<<nums[49]<<" "<<nums[48]<<" "<<nums[47]<<endl;
    return 0;
}
int main(){
    srand((unsigned)time(NULL));
    int a[50]={0};
    for(int i=0;i<50;i++){
        a[i]=rand();
    }
    top_Three(a);
    return 0;
}