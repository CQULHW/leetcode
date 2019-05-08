#include<iostream>
using namespace std;
class Shape
{
private:
    float x;
    float y;
public:
    virtual float getArea()const=0;
};
class Rectangle:public Shape
{
private:
    float length;
    float width;
public:
    Rectangle(float l,float w):length(l),width(w){};
    virtual float getArea()const;
};

float Rectangle::getArea()const
{   return length*width;
}
class Circle:public Shape
{
private:
    float radius;
public:
    Circle(float r):radius(r){};
    virtual float getArea()const;
};
float Circle::getArea()const{
    return 3.14*radius*radius;
}
int main(){
    Shape *s;
    Circle circle(1.0);
    Rectangle rectangle(1.5,2.0);
    s=&circle;
    s->getArea();
    cout<<"Circle:";
    cout<<s->getArea()<<endl;
    s=&rectangle;
    s->getArea();
    cout<<"Rectangle:";
    cout<<s->getArea()<<endl;
}




