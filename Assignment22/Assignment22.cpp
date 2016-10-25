/* A class called complex to perform arithmetic on complex numbers
 * Gladstone, Keegan
 * Assignment 20
 * 04/08/16
 */

#include <iostream>
#include <math.h>
using namespace std;



class Complex{
    
public:
    
    static const int ZERO = 0;
    
    //constructor
    Complex() {
        real = ZERO;
        imaginary = ZERO;
    }
    
    Complex(double a, double b) {
        real = a;
        imaginary = b;
    }
    
    //destructor
    ~Complex() {
        
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
        cout<< real << "+" << imaginary << "i";
    }
    
    /* OVERLOADED MEMBER FUNCTIONS:
     */
    Complex operator+(const Complex &complex) {
        double real3 = real + complex.real;
        double imaginary3 = imaginary + complex.imaginary;
        Complex complex3(real3, imaginary3);
        return complex3;
    }
    
    Complex operator-(const Complex &complex) {
        double  real3 = real - complex.real;
        double imaginary3 = imaginary - complex.imaginary;
        Complex complex3(real3, imaginary3);
        return complex3;
    }
    
    Complex operator*(const Complex &complex) {
        double  first = real * complex.real; //a*c
        double last = imaginary * complex.imaginary; //b*d
        double inner = imaginary * complex.real; //b*c
        double outer = real * complex.imaginary; //a*d
        Complex complex3((first - last), (inner + outer));
        return complex3;
    }
    
    Complex operator/(const Complex &complex) {
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
    
    friend bool operator==(const Complex &complex1, const Complex &complex2) {
        
        if(complex1.real == complex2.real) {
            if(complex1.imaginary == complex2.imaginary) {
                return true;
            }
        }
        
        return false;
        
    }
    
    friend bool operator!=(const Complex &complex1, const Complex &complex2) {
        
        if(complex1.real == complex2.real) {
            if(complex1.imaginary == complex2.imaginary) {
                return false;
            }
        }
        
        return true;
        
    }
    
    
    //overload cout << operator
    friend ostream &operator<<(ostream &output, const Complex &complex) {
        
        //if 'b' is less than zero, do not include + symbol.
        if (complex.imaginary < 0) {
            output <<complex.real<<complex.imaginary<<"i";
        }
        else {
            //otherwise, include + for 'a + bi' form.
            output <<complex.real<<"+"<<complex.imaginary<<"i";
            
        }
        
        return output;
    }
    
    //overload cin input stream.
    friend istream &operator<<(istream &input, Complex &complex) {
        string form;
        input >> form;
        string delimiter = "+";
        string delimiter2 = "i";
        string real = form.substr(0, form.find(delimiter));
        string imaginary = form.substr(form.find(delimiter)+1, form.find(delimiter2));
        complex.real = atof(real.c_str());
        complex.imaginary = atof(imaginary.c_str());
        
        return input;
    }
    
private:
    double real;
    double imaginary;
    double i;
    
    
};//end of class definition


//program driver to test class Complex
int main() {
    
    Complex c1, c2, c3;
    bool b;
    
    cout<<"Enter a Complex number in the form 'a+bi': ";
    cin << c1;
    
    cout<<"Enter another Complex number in the form 'a+bi': ";
    cin << c2;
    
    //test the operators
    cout<<"Test the + operator:\n";
    c3 = c1 + c2;
    cout << c1<< " + "<<c2 << " = "<< c3 << "\n" <<endl;
    
    cout<<"Test the - operator:\n";
    c3 = c1 - c2;
    cout << c1<< " - "<<c2 << " = "<< c3 << "\n" <<endl;
    
    cout<<"Test the * operator:\n";
    c3 = c1 * c2;
    cout << c1<< " * "<<c2 << " = "<< c3 << "\n" <<endl;
    
    cout<<"Test the / operator:\n";
    c3 = c1 / c2;
    cout << c1<< " / "<<c2 << " = "<< c3 << "\n" <<endl;
    
    cout<<"Test the == operator:\n";
    b = (c1 == c2);
    
    if(b) {
        cout << c1<< " == "<<c2 << " = "<< "true\n" <<endl;
    } else {
        cout << c1<< " == "<<c2 << " = "<< "false\n" <<endl;
    }
    
    cout<<"Test the != operator:\n";
    b = (c1 != c2);
    
    if(b) {
        cout << c1<< " != "<<c2 << " = "<< "true\n" <<endl;
    } else {
        cout << c1<< " != "<<c2 << " = "<< "false\n" <<endl;
    }
    
    
}