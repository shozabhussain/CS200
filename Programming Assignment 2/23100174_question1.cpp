#include <iostream>
using namespace std;

class fractions
{

public: 

	int numerator;
	int denominator;

	fractions()
	{
		numerator = 0 ;
		denominator = 1;
	}

	fractions( int n, int d)
	{
		numerator = n; 
		denominator = d;
	}

	print() // prints a fraction
	{
		for(int i=1; i<=numerator; i++)
		{	
			if( numerator%i == 0 && denominator%i == 0)
			{
				numerator = numerator/i ;
				denominator = denominator/i;
				i = 1 ;
			}
		}
		if (denominator == 1)
		{
			cout << numerator << endl;
		}
		else 
		{
			cout << numerator << "/" << denominator << endl;
		}
	}

	fractions operator + (const fractions& b) // overloading + operator for addition 
	{
		fractions x;
		x.denominator = b.denominator * this->denominator;
		x.numerator = b.numerator * this->denominator + this->numerator * b.denominator ;
		return x ;
	}

	fractions operator - (const fractions& b) // overloading - operator for subtraction
	{
		fractions x;
		x.denominator = b.denominator * this->denominator;
		x.numerator =  this->numerator * b.denominator - b.numerator * this->denominator ;
		return x ;
	}

	bool operator == (const fractions& b) // copies a fraction by overloading == operator
	{
		bool check = 0;
		if( this->numerator == b.numerator && this->denominator == b.denominator)
		{
			check = 1;
			return check;
		}
		else 
		{
			return check;
		}
	}

	fractions operator * (const fractions& b) // overloads * operator to multiply fractions
	{
		fractions x;
		x.denominator = b.denominator * this->denominator;
		x.numerator = b.numerator * this->numerator  ;
		return x ;
	}

	fractions operator / (const fractions& b) // overloads / operator to divide fractions
	{
		fractions x; 
		x.numerator = this->numerator * b.denominator ;
		x.denominator = this-> denominator * b.numerator ;
		return x;
	}

	bool operator > (const fractions& b) // checks if one fraction is greater than other
	{
		bool check =0;
		if ( this->numerator * b.denominator > this->denominator * b.numerator)
		{
			check =1 ;
			return check ;
		}
		else 
		{
			return check;
		}
	}

	fractions operator+() // adds 1 to a fraction
	{
		fractions x;
		x.numerator = numerator + denominator ;
		x.denominator = denominator ;
		return x ;
	}

	fractions operator--() // substract 1 from a fraction
	{
		fractions x;
		x.numerator =  numerator - denominator ;
		x.denominator = denominator ;
		return x ;
	}

	friend istream& operator >> (istream& input, fractions& x)
	{
		cout << "Please enter the numerator" << endl;
		input >> x.numerator ;
		cout << "Please enter the denominator" << endl;
		input >> x.denominator ;
		while (x.denominator == 0 )
		{
			cout << "Please enter any other denominator than 0 " << endl;
			input >> x.denominator ;
		}
		return input ;
	}

	friend ostream& operator << (ostream& output, fractions& x )
	{
		x.print();
		return output ;
	}

};

int main()
{
	fractions fracsum, fracdiff, fracdiv, fracpro, fracinc, fracdec ;
	fractions frac1 ;
	cout << "Please enter your first fraction " << endl;
	cin >> frac1 ;
	cout << endl;
	fractions frac2;
	cout << "Please enter your second fraction " << endl;
	cin >> frac2 ;

	cout << endl;
	cout << frac1 ;
	cout << frac2 ;

	if (frac1 == frac2)
	{
		cout << "Compare returns true " << endl;
	}
	else 
	{
		cout << "Compare returns false " << endl ;
	}

	fracsum = frac1 + frac2 ;
	cout << "sum = " << fracsum << endl ;

	fracinc = +frac1 ;
	cout << "frac1 = " << fracinc << endl ;

	fracdec = --frac2 ;
	cout << "frac2 = " << fracdec << endl ;

	fracdiff = fracinc - fracdec ;
	cout << "Difference = " << fracdiff << endl;

	fracpro = frac1 * fracsum ;
	cout << "Product = " << fracpro << endl ;

	fracdiv = frac1 / frac2 ;
	cout << "Division = " << fracdiv << endl;

	if (frac1 > frac2)
	{
		cout << "frac1 > frac2 returns true  " << endl;
	}
	else 
	{
		cout << "frac1 > frac2 returns false " << endl ;
	}

}