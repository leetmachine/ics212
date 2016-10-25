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
        cout << real << " + " << imaginary << "i";
    }
    
private:
    double real;
    double imaginary;
    double i;
    

};//end of class definition

//program driver to test class Complex
int main() {
    puts("Test the constructor.");
    Complex c1;
    cout<<"Complex number c1 is ";
    c1.print();
    cout<<endl;
    puts("");
    
    puts("Test the one set() function.");
    Complex c2;
    c2.set(3.3, 4.4);
    cout<<"Complex number c2 is ";
    c2.print();
    cout<<endl;
    puts("");
    
    puts("Test the two get() functions.");
    Complex c3;
    c3.set(5.5, 6.6);
    cout<<"Complex number c3's real part is "<< c3.getReal()<<endl;
    cout<<"Complex number c3's imaginary part is "<<c3.getImaginary()<<endl;
    puts("");
    
    
    
}