#include<iostream>
using namespace std;
class fee
{
private:
    float weight;
public:
    virtual float calculate()const=0;
};
class Car:public fee
{
    private:
    int passengers;
    public:
    Car(float p):passengers(p){};
    virtual float calculate()const;
};
float Car::calculate()const{
    return passengers*3;
}
class Truck:public fee
{
    private:
    float weight;
    public:
    Truck(float w):weight(w){};
    virtual float calculate()const;
};
float Truck::calculate()const{
    return weight*5;
};
int main(){
    fee *f;
    Car car(5);
    Truck truck(1.8);
    f=&car;
    cout<<"Car fee:";
    cout<<f->calculate()<<endl;
    f=&truck;
    cout<<"Truck fee:";
    cout<<f->calculate()<<endl;
}
