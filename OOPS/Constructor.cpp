// same name of class and member functions, doesn't have any return type 
#include<iostream>
using namespace std;
class Complex{
	private:
        double real;
        double img;
    public: 
        Complex(){                          // default constructor
            real = 0.0;                  
            img = 0.0;
        }
        Complex(double real, double img){        // parameterized constructor
            this->real= real;
            this->img= img;
        }
        Complex(Complex &C){                    // copy constructor
            this->real= C.real;
            this->img= C.img;
        }
        void showComplex(){
            cout<<real<<" + i"<<img<<endl;
        }
};

int main() {
    Complex c1;
    Complex c2(4.5,2.8);
    Complex c3(6.2,8.7);

    c1.showComplex();
    c2.showComplex();
    c3.showComplex();

    return 0;
}


