//A base class shape used to create other shapes and perform certain functions.
//Gladstone, Keegan; starter code by William Albritton
//Assignment 24
//04/19/16

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual void printSize() const = 0;
    virtual char* name() const = 0;
    virtual void inputData() = 0;
    virtual double area() const = 0;
    virtual double volume() const{
        return 0.0;
    }
};

#define PI 3.14

/*
 *
 *START CIRCLE SHAPE'S
 */
class Circle : public Shape {
public:
    //syntax "datatype variable = value"  will give a default value for the variable
    // this constructor will be called with no arguments or one argument
    // for example: shapeArray[0] = new Circle();
    // for example:  Circle c = new  Circle(10);
    Circle(double r = 0.0){
        if(r<0) r=-r;
        radius = r;
    }
    char* name()const{
        return "Circle";
    }
    void printSize() const{
        cout<<"The "<<name()<<"'s area = "<<area()<<endl;
    }
    void inputData(){
        cout<<"Enter the "<<name()<<"'s radius: ";
        cin>>radius;
    }
    double area() const{
        return PI*radius*radius;
    }
protected:
    double radius;
};


class Sphere : public Circle {
public:
    
    //default constructor
    Sphere(double r = 0.0): Circle(r) {
        radius = r;
    }
    
    virtual char* name() const{
        return "Sphere";
    }
    
    virtual void printSize() const {
        cout<<"The "<<name()<<"'s surface area = "<<setprecision(1)<<fixed<<area()<<endl;
        cout<<"The "<<name()<<"'s volume = "<<setprecision(1)<<fixed<<volume()<<endl;
    }
    
    virtual void inputData() {
        cout<<"Enter the "<<name()<<"'s radius: ";
        cin>>radius;
    }
    
    virtual double area() const{
        return 4*PI*radius*radius;
    }
    
    virtual double volume() const{
        double v = PI*radius*radius*radius;
        return v*4/3;
    }
    
protected:
    
};

class Cylinder : public Circle {
public:
    
    Cylinder(double r = 0.0, double h = 0.0): Circle(r){
        radius = r;
        height = h;
    }
    
    virtual char* name() const{
        return "Cylinder";
    }
    
    virtual void printSize() const {
        cout<<"The "<<name()<<"'s surface area = "<<area()<<endl;
        cout<<"The "<<name()<<"'s volume = "<<volume()<<endl;
    }
    
    virtual void inputData() {
        cout<<"Enter the "<<name()<<"'s radius: ";
        cin>>radius;
        cout<<"Enter the "<<name()<<"'s height: ";
        cin>>height;
    }
    
    virtual double area() const{
        return (2*Circle::area())+(height*2*PI*radius);
    }
    
    virtual double volume() const{
        double v = PI*radius*radius*radius;
        return v*4/3;
    }
    
protected:
    double height;

};

/*
 *START SQUARE SHAPE'S
 *
 */

class Square: public Shape{
public:

    Square(double s = 0.0){
        side = s;
    }
    
    char* name()const{
        return "Square";
    }
    void printSize() const{
        cout<<"The "<<name()<<"'s area = "<<area()<<endl;
    }
    void inputData(){
        cout<<"Enter the "<<name()<<"'s side: ";
        cin>>side;
    }
    double area() const{
        return side*side;
    }
    
    
protected:
    double side;
    
};

class Cube: public Square{
public:
    
    Cube(double s = 0.0): Square(s){
        side = s;
    }
    
    char* name()const{
        return "Cube";
    }
    void printSize() const{
        cout<<"The "<<name()<<"'s surface area = "<<area()<<endl;
        cout<<"The "<<name()<<"'s volume = "<<volume()<<endl;
    }
    void inputData(){
        cout<<"Enter the "<<name()<<"'s side: ";
        cin>>side;
    }
    double area() const{
        return 6*Square::area();
    }
    
    double volume() const{
        return side*side*side;
    }
    
protected:
    
};

/*
 *START TRIANGLE SHAPE'S
 *
 */

class Triangle: public Shape {
public:
    
    Triangle(double s = 0.0){
        side = s;
    }
    
    char* name()const{
        return "Triangle";
    }
    void printSize() const{
        cout<<"The "<<name()<<"'s area = "<<setprecision(1)<<fixed<<area()<<endl;
    }
    void inputData(){
        cout<<"Enter the "<<name()<<"'s side: ";
        cin>>side;
    }
    double area() const{
        double a = sqrt(3)*side*side;
        return a/4;
    }
    
    
    
    
protected:
    double side;
    
};

class Tetrahedron: public Triangle{
public:
    Tetrahedron(double s = 0.0): Triangle(s){
        side = s;
    }
    
    char* name()const{
        return "Tetrahedron";
    }
    void printSize() const{
        cout<<"The "<<name()<<"'s surface area = "<<setprecision(1)<<fixed<<area()<<endl;
        cout<<"The "<<name()<<"'s volume = "<<setprecision(1)<<fixed<<volume()<<endl;
    }
    void inputData(){
        cout<<"Enter the "<<name()<<"'s side: ";
        cin>>side;
    }
    double area() const{
        return 4*Triangle::area();
        
    }
    
    double volume() const{
        double v = sqrt(2)*side*side*side;
        return v/12;
    }
    

protected:

    
};

#define NUM 7

int displayMenu(Shape *s[]);

int main(){
    
    Shape *shapeArray[NUM];
    shapeArray[0] = new Circle();
    shapeArray[1] = new Sphere();
    shapeArray[2] = new Cylinder();
    shapeArray[3] = new Square();
    shapeArray[4] = new Cube();
    shapeArray[5] = new Triangle();
    shapeArray[6] = new Tetrahedron();
    /*
     shapeArray[1] = new Sphere();
     shapeArray[2] = new Cylinder();
     shapeArray[3] = new Square();
     shapeArray[4] = new Cube();
     shapeArray[5] = new Triangle();
     shapeArray[6] = new Tetrahedron();
     */
    int choice = displayMenu(shapeArray);
    while(choice>=0 && choice<=6){
        shapeArray[choice]->inputData();
        shapeArray[choice]->printSize();
        cout<<endl;
        choice = displayMenu(shapeArray);
    }
    return 0;
}

int displayMenu(Shape *s[]){
    int choice = 0;
    cout<<"Select an object from the menu (enter 7 to quit)."<<endl;
    for(int i=0;i<NUM;i++){
        cout<<'\t'<<i<<". "<<s[i]->name()<<endl;
    }
    cin>>choice;
    return choice;
}

/*
 Select an object from the menu (enter 7 to quit).
 0. Circle
 1. Sphere
 2. Cylinder
 3. Square
 4. Cube
 5. Triangle
 6. Tetrahedron
 0
 Enter the Circle's radius: 10
 The Circle's area = 314
 
 Select an object from the menu (enter 7 to quit).
 0. Circle
 1. Sphere
 2. Cylinder
 3. Square
 4. Cube
 5. Triangle
 6. Tetrahedron
 1
 Enter the Sphere's radius: 20
 The Sphere's surface area = 5024
 The Sphere's volume = 33493.3
 
 Select an object from the menu (enter 7 to quit).
 0. Circle
 1. Sphere
 2. Cylinder
 3. Square
 4. Cube
 5. Triangle
 6. Tetrahedron
 2
 Enter the Cylinder's radius: 30
 Enter the Cylinder's height: 40
 The Cylinder's surface area = 13188
 The Cylinder's volume = 113040
 
 Select an object from the menu (enter 7 to quit).
 0. Circle
 1. Sphere
 2. Cylinder
 3. Square
 4. Cube
 5. Triangle
 6. Tetrahedron
 3
 Enter the Square's side: 50
 The Square's area = 2500
 
 Select an object from the menu (enter 7 to quit).
 0. Circle
 1. Sphere
 2. Cylinder
 3. Square
 4. Cube
 5. Triangle
 6. Tetrahedron
 4
 Enter the Cube's side: 60
 The Cube's surface area = 21600
 The Cube's volume = 216000
 
 Select an object from the menu (enter 7 to quit).
 0. Circle
 1. Sphere
 2. Cylinder
 3. Square
 4. Cube
 5. Triangle
 6. Tetrahedron
 5
 Enter the Triangle's side: 70
 The Triangle's area = 2121.76
 
 Select an object from the menu (enter 7 to quit).
 0. Circle
 1. Sphere
 2. Cylinder
 3. Square
 4. Cube
 5. Triangle
 6. Tetrahedron
 6
 Enter the Tetrahedron's side: 80
 The Tetrahedron's surface area = 11085.1
 The Tetrahedron's volume = 60339.8
 
 Select an object from the menu (enter 7 to quit).
 0. Circle
 1. Sphere
 2. Cylinder
 3. Square
 4. Cube
 5. Triangle
 6. Tetrahedron
 7
 */






