#include <iostream>
using namespace std;

class student
{
public:
	string *name;
	int *age;

	student()
	{
		name = NULL ;
		age= NULL;
	}

	student(string studentn, int studenta)
	{
		cout << " Constructor Implemented " << endl;
		name = new string;
		age = new int ;

		*name = studentn ;
		*age = studenta ;


	}

	void print()
	{
		cout << "Student name: " << *name << endl;
		cout << "Student age: " << *age << endl; 
 	}

 	~student()
 	{
 		cout << " Overloading delete operator " << endl;
 		delete name;
 		delete age ;
 	}

};

int main()
{	
	cout << "Enter the name:" ;
	string n; 
	cin >> n;

	cout << "Enter the age: " ;
	int a ;
	cin >> a ;

	student x(n,a);
	x.print();

	

}
