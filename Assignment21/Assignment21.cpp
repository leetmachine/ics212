/* A class called complex to perform arithmetic on complex numbers
 * Gladstone, Keegan
 * Assignment 20
 * 04/08/16
 */

#include <iostream>
#include <math.h>
using namespace std;

#define EYE sqrt(-1.0);

class Complex{
    
public:
    
    static const int ZERO = 0;

    //constructor
    Complex() {
        real = ZERO;
        imaginary = ZERO;
        i = EYE;
    }
    
    Complex(double a, double b) {
        real = a;
        imaginary = b;
        i = EYE;
    }
    
    //destructor
    ~Complex() {
        cout<<"Destructor for ("<<real<<" + "<<imaginary<<"i)"<<endl;
    }
    
    //copy constructor
    Complex(const Complex &complex){
        set(complex.real, complex.imaginary);
        
    }
    
    //mutator function to set both the real and imaginary variables
    void set(double a, double b) {
        real = a;
        imaginary = b;
    }
    
    //accessor for get Real
    double getReal() const {
        return real;
        
    }
    
    //accessor for get Imaginary
    double getImaginary() const {
        return imaginary;
    }
    
    //print function to output the variables in the form "a + bi"
    void print() const {
        cout <<"("<< real << " + " << imaginary << "i"<<")";
    }
    
    /* ARITHMETIC MEMBER FUNCTIONS:
    */
    //Add member function
    Complex add(const Complex &complex) {
        double real3 = real + complex.real;
        double imaginary3 = imaginary + complex.imaginary;
        Complex complex3(real3, imaginary3);
        return complex3;
    }
    
    Complex subtract(const Complex &complex) {
        double  real3 = real - complex.real;
        double imaginary3 = imaginary - complex.imaginary;
        Complex complex3(real3, imaginary3);
        return complex3;
    }
    
    Complex multiply(const Complex &complex) {
        double  first = real * complex.real; //a*c
        double last = imaginary * complex.imaginary; //b*d
        double inner = imaginary * complex.real; //b*c
        double outer = real * complex.imaginary; //a*d
        Complex complex3((first - last), (inner + outer));
        return complex3;
    }
    
    Complex divide(const Complex &complex) {
        double first =  real * complex.real; //a*c
        double last = imaginary * complex.imaginary; //b*d
        double inner = imaginary * complex.real; //b*c
        double outer = real * complex.imaginary; //a*d
        double cSquare = complex.real * complex.real; //c*c
        double dSquare = complex.imaginary * complex.imaginary; //d*d
        
        //new real
        double realQuotient = first + last;
        double realDivisor = cSquare + dSquare;
        double real3 = realQuotient/realDivisor;
        
        //new imaginary
        double imaginaryQuotient = inner - outer;
        double imaginaryDivisor = cSquare + dSquare;
        double imaginary3 = imaginaryQuotient/imaginaryDivisor;
        
        Complex complex3(real3, imaginary3);
        return complex3;
    }
    
    
    
private:
    double real;
    double imaginary;
    double i;
    

};//end of class definition

//program driver to test class Complex
int main() {
    //test the constructor
    puts("Test the constructor with two parameters");
    Complex c1(1.1, 2.3);
    cout<<"Complex number c1 is: ";
    c1.print();
    cout<<endl;
    puts("");
    {
        
    //test copy constructor
    puts("Test the copy constructor");
    Complex c2(c1);
    cout<<"Complex number c2 is: ";
    c2.print();
    cout<<endl;
    puts("");
    
        {
    //test the add() member function
    puts("Test the add() member function.");
    Complex c3 = c1.add(c2);
    c1.print();
    cout<<" + ";
    c2.print();
    cout<<" = ";
    c3.print();
    cout<<endl;
    puts("");
            {
    //test the subtract() member function
    puts("Test the subtract() member function.");
    Complex c4 = c1.subtract(c2);
    c1.print();
    cout<<" - ";
    c2.print();
    cout<<" = ";
    c4.print();
    cout<<endl;
    puts("");
                {
    //Test the multiply() member function
    puts("Test the multiply() member function.");
    Complex c5 = c1.multiply(c2);
    c1.print();
    cout<<" * ";
    c2.print();
    cout<<" = ";
    c5.print();
    cout<<endl;
    puts("");
                    {
    //test the divide() member function
    puts("Test the divide() member function.");
    Complex c6 = c1.divide(c2);
    c1.print();
    cout<<" / ";
    c2.print();
    cout<<" = ";
    c6.print();
    cout<<endl;
    puts("");
    
                    }
                }
            }
        }
    }
    
    
}