#include <iostream>
using namespace std;

struct practiseStruct
{

	practiseStruct()
	{
		a=0;
	}	

	void setter( int *p)
	{
		a = *p;
	}

	int getter()
	{
		int *p= &a;
		return *p;
	}

	void print()
	{
		int print= getter();
		cout << print ;
	}

	void incrementPrint()
	{
		int *p;
		int inc= getter();
		inc++;
		p= &inc;
		setter(p);
		cout << inc;
	}

private:
	int a;

};

int main()
{
	int number;
	practiseStruct *ptr = NULL;
	ptr = new practiseStruct;

	cout << "Enter Number " ;
	cin >> number ;

	int *p = &number;
	ptr -> setter(p);

	cout << "Your Number is: " ;
	ptr -> print();
	cout << "" << endl;

	cout << "Your Incremented Number is: " ;
	ptr -> incrementPrint();
	cout << "" << endl;

	int incremented = ptr -> getter();
	cout << "Number Retruned To Main is: " << incremented ;

}