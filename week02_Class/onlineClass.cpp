//
// Created by MiaKim on 31/07/2025.
//

#include <iostream>
using namespace std;

class Rectangle {
private:
    //declaration of the private members
    double width;
    double length;

public:
    //declaration of the public members
    void setWidth(double); //mutator
    void setLength(double);
    double getWidth() const; //accessors
    double getLength() const;
    double getArea() const;
};

int main() {
    //int x;
    Rectangle r;

    r.setWidth(5.2);
    r.setLength(3.1);


    cout << r.getLength() << " , " << r.getWidth() << endl;
    cout << r.getArea() << endl;

    Rectangle* p = &r;
    cout << p ->getArea() << endl;
    Rectangle* s = new Rectangle;

    s->setLength(3);
    s->setWidth(2);
    cout << s->getArea() << endl;

    //pause the program
    cin.ignore();
    cin.get();
}

//declare our functions here
// scope resolution operator
void Rectangle::setWidth(double d)
{
    width = d;
}

void Rectangle::setLength(double l)
{
    length = l;
}

double Rectangle::getLength()const
{
    return length;
}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getArea() const {
    return length * width;
}