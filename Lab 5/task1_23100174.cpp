#include <iostream>
using namespace std; 

class date
{
public:
	int month;
	int day;
	int year;

	date()
	{
		this-> month =0;
		this-> day= 0;
		this->year = 0;
	}

	void print()
	{
		cout << this->year << " - " ;
		if (this-> month < 10)
		{
			cout << "0" << this->month;
		}
		else 
		{
			cout << this->month;
		} 
		cout << " - " ;
		if (this-> day < 10)
		{
			cout << "0" << this->day;
		}
		else 
		{
			cout << this->day;
		} 
	}

	date operator-(const date &x)
	{
		date temp;
		temp.day = this->day - x.day;
		if (temp.day < 0)
		{
			temp.day = temp.day + 30;
			temp.month-- ;
		}
		temp.month= this->month - x.month + temp.month;
		if (temp.month < 0)
		{
			temp.month = temp.month + 12;
			temp.year-- ;
		}
		temp.year= this->year - x.year + temp.year ;
		temp.year= temp.year + 2000 ;
		return temp;
	}

	date operator +(const date &x)
	{
		date temp;
		temp.day = this->day + x.day;
		if (temp.day > 30)
		{
			temp.day = temp.day - 30;
			temp.month++ ;
		}
		temp.month= this->month + x.month + temp.month;
		if (temp.month > 12)
		{
			temp.month = temp.month - 12;
			temp.year++ ;
		}
		temp.year= this->year + x.year + temp.year;
		temp.year = temp.year - 2000 ;
		return temp ;
	}
};

int main()
{
	date d1, d2, dsum, dsub ;
	cout << " First date: " << endl;
	cout << "month " << endl;
	cin >> d1.month ;
	while (cin.fail() || d1.month < 1 || d1.month > 12 ) 
    {
      cout << "Please select the correct month\n" ;
      cin.clear ();
      cin.ignore(10000,'\n');
      cin >> d1.month ;
    }
	cout << "day " << endl;
	cin >> d1.day ;
	while (cin.fail() || d1.day < 1 || d1.day > 30 ) 
    {
      cout << "Please select the correct day\n" ;
      cin.clear ();
      cin.ignore(10000,'\n');
      cin >> d1.day ;
    }
	cout << "year " << endl;
	cin >> d1.year ; 

	cout << endl;

	cout << " Second date: " << endl;
	cout << "month " << endl;
	cin >> d2.month ;
	while (cin.fail() || d2.month < 1 || d2.month > 12 ) 
    {
      cout << "Please select the correct month\n" ;
      cin.clear ();
      cin.ignore(10000,'\n');
      cin >> d2.month ;
    }
	cout << "day " << endl;
	cin >> d2.day ;
	while (cin.fail() || d2.day < 1 || d2.day > 30 ) 
    {
      cout << "Please select the correct day\n" ;
      cin.clear ();
      cin.ignore(10000,'\n');
      cin >> d2.day ;
    }
	cout << "year " << endl;
	cin >> d2.year ;

	cout << endl;

	dsum= d1 + d2;
	cout << "Add Date: " ;
	dsum.print();

	cout << endl;
	cout << "Subtract Date: " ;
	dsub= d1 - d2 ;
	dsub.print();
}