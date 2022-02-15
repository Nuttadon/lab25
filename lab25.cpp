#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
		
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}
// cp cp
ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	return ComplexNumber((real*c.real)-(imag*c.imag),(real*c.imag)+(imag*c.real));
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	return ComplexNumber((((real)*(c.real))+((imag)*(c.imag)))/(pow(c.real,2)+pow(c.imag,2)),(((c.real)*(imag))-((real)*(c.imag)))/(pow(c.real,2)+pow(c.imag,2)));
}
bool ComplexNumber::operator==(const ComplexNumber &c){
	if(real==c.real && imag == c.imag) return true;
	else return false;
}

//do cp
ComplexNumber operator+(double real,const ComplexNumber &c){
	return ComplexNumber(real+c.real,c.imag);
}

ComplexNumber operator-(double real,const ComplexNumber &c){
	return ComplexNumber(real-c.real,-c.imag);
}

ComplexNumber operator*(double real,const ComplexNumber &c){
	return ComplexNumber(real*c.real,real*c.imag);
}

ComplexNumber operator/(double real,const ComplexNumber &c){
	return ComplexNumber((real*c.real)/(pow(c.real,2)+pow(c.imag,2)),(-1*c.imag)/(pow(c.real,2)+pow(c.imag,2)));
}

bool operator==(double real,const ComplexNumber &c){
	if(real==c.real&&c.imag==0) return true;
	else return false;
}

double ComplexNumber::abs(){
	return sqrt((real*real)+(imag*imag));
}

double ComplexNumber::angle(){
	double a=atan(imag/real)* 180 / M_PI;
	if(real<0&&imag>0) return 180+a;
	if(real<0&&imag<0) return a-180;
	return a;
}
//Write your code here
ostream & operator<<(ostream &os, const ComplexNumber &c){
	char a;
	if(c.imag>0) a='+';
	if(c.real==0&&c.imag==0) return os << "0";
	if(c.real==0) return os << c.imag<< "i";
	if(c.imag==0) return os << c.real;
	if(c.real!=0&&c.imag>0) return os << c.real << a << c.imag<< "i";
	return os << c.real <<  c.imag<< "i";
}
int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n"; 
}






