#include <iostream>
using namespace std;

class complexNumber
{
public:
	int real;
	int imaginary;

	complexNumber()
	{
		real=0;
		imaginary=0;
	}

	void print()
	{
		cout << "Real Part: " << real << endl;
		cout << "imaginary: " << imaginary << endl;
	}

};

complexNumber sumComplex(complexNumber x, complexNumber y)

	{
		complexNumber z;
		z.real = x.real + y.real;
		z.imaginary= x.imaginary+ y.imaginary ;
		return z ;
	}

int main()
{
	complexNumber a,b,c ;
	cout << "Input the real part: " <<endl;
	cin >> a.real;
	cout << "Input the imaginary part: " << endl;
	cin >> a.imaginary ; 

	cout << "Input the real part: " <<endl;
	cin >> b.real;
	cout << "Input the imaginary part: " << endl;
	cin >> b.imaginary ; 

	c= sumComplex(a,b);
	c.print();

}