/* A class Circle, and derived class Cylinder
 * Gladstone, Keegan
 * Assignment 23
 * 04/14/16
 */

#include <iostream>
#include <math.h>
using namespace std;



class Circle{
    
public:
    
    static const double PI = 3.1415926;
    
    
    //default constructor
    Circle(){
        setRadius(0);

    }
    
    //constructor
    Circle(double radius2){
        setRadius(radius2);
    }
    
    //return name of class
    char * name() const{
        return "Circle";
    }
    
    void setRadius(double radius2) {
        radius = radius2;
    
    }
    
    double getRadius() const {
        return radius;
    }
    
    double area() const {
        return pow(radius,2)*PI;
    }
    
    friend ostream &operator<<(ostream &output, const Circle & circle) {
        output<<circle.name()<<" with radius = "<<circle.radius;
        return output;
    }
    
    
protected:
    double radius;

};//end of Circle class

class Cylinder: public Circle{
public:
    
    //overloaded default constructor
    Cylinder(): Circle(0) {
        setHeight(0);
    }
    
    //constructor for Cylinder class
    Cylinder(double radius2, double height2): Circle(radius2) {
        setHeight(height2);
    }
    
    //return name of class
    char * name() const{
        return "Cylinder";
    }
    
    //set function
    void setHeight(double height2){
        height = height2;
    }
    
    //get function
    double getHeight() const{
        return height;
    }
    
    //override circle area function
    double area() const {
        return (2*PI*radius*height) + (2*PI*pow(radius, 2));
    }
    
    
    //calculate volume
    double volume() const {
        return PI*pow(radius, 2)*height;
    }
    
    friend ostream &operator<<(ostream &output, const Cylinder & cyl) {
        output<<cyl.name()<<" with radius = "<<cyl.radius<<" with height = "<<cyl.height;
        return output;
    }
    
    
protected:
    double height;//new data member in addition to radius
    
};//end of Cylinder class


//program driver
int main() {
    
    //Circle test
    cout<<"Test Circle class constructor and area() function:"<<endl;
    Circle circle1(10);
    cout<<circle1<<endl;
    cout<<"area of cir1 = "<<circle1.area()<<endl<<endl;
    
    //test set and get methods for class circle
    cout<<"Test set and get methods for class Circle:"<<endl;
    Circle cir2;
    cir2.setRadius(12);
    cout<<cir2<<endl;
    cout<<"get data members for cir2: "<<cir2.getRadius()<<endl<<endl;
    
    //test Cylinder class constructor, area(), and volume(), functions:
    cout<<"Test Cylinder class constructor, area(), and volume(), functions: "<<endl;
    Cylinder cyl1(20, 30);
    cout<<cyl1<<endl;
    cout<<"area of cyl1 = "<<cyl1.area()<<endl;
    cout<<"volume of cyl2 = "<<cyl1.volume()<<endl<<endl;
    
    //test set and get methods of class Cylinder:
    cout<<"Test set() and get() methods for class Cylinder:"<<endl;
    Cylinder cyl2;
    cyl2.setRadius(40);
    cyl2.setHeight(50);
    cout<<cyl2<<endl;
    cout<<"get data members for cyl2: "<<cyl2.getRadius()<<", "<<cyl2.getHeight()<<endl<<endl;
}