#include<iostream>
#include <cstring>
using namespace std;
class Tank{
    protected:
    char*color;
    char*armor;
    char *speed;
    int shoot;
    public:
    Tank(){};
    Tank(char*col,char*arm,char*sp,int sh){
      color=new char[10];
      armor=new char[10];
      speed=new char[10];
      shoot=sh;
      strcpy(color,col);
      strcpy(armor,arm);
      strcpy(speed,sp);
    }
    ~Tank(){
        delete[] color;
        delete[] armor;
        delete[] speed;
    }
    char* get_color(){return color;}
    char* get_speed(){return speed;}
    char* get_armor(){return armor;}
    int get_bullet(){return shoot;}
};
class light_Tank:public Tank{
    public:
    light_Tank(char*col=(char*)"green",char*arm=(char*)"light",char*sp=(char*)"fast",int sh=1):Tank(col,arm,sp,sh){
    }
};
class male_Tank:public Tank{
    public:
    male_Tank(char*col=(char*)"gray",char*arm=(char*)"heavy",char*sp=(char*)"slow",int sh=2):Tank(col,arm,sp,sh){}
};
int main(){
    light_Tank lightank;
    male_Tank maletank;
    cout<<"lighttank'color:"<<lightank.get_color()<<endl;
    cout<<"lighttank'armor:"<<lightank.get_armor()<<endl;
    cout<<"lighttank'speed:"<<lightank.get_speed()<<endl;
    cout<<"lighttank'bullet:"<<lightank.get_bullet()<<endl;
    cout<<"maletank'bullet:"<<maletank.get_color()<<endl;
    cout<<"maletank'bullet:"<<maletank.get_armor()<<endl;
    cout<<"maletank'bullet:"<<maletank.get_speed()<<endl;
    cout<<"maletank'bullet:"<<maletank.get_bullet()<<endl;
    return 0;
}