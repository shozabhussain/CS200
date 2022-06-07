#include <iostream>
using namespace std;

class faculty
{
private:
	int numOfStudents ;

protected:
	int *marks;

public:

	faculty()
	{
		numOfStudents = 0;
		marks= NULL ;
	}

	faculty(int x)
	{
		numOfStudents= x ;
		marks = new int[x];
		for (int i=0; i<x; i++)
		{
			cout << "Enter marks for student " << i+1 << " " ;
			cin >> marks[i] ;
		}

		cout << "Marks for all students have been set!" << endl;
	}

	void setnumOfStudents(int x)
	{
		numOfStudents = x ;
	}

	int getnumOfStudents()
	{
		return numOfStudents ;
	}

	void setmarks(int i, int x)
	{
		marks[i] = x ;
	}

	int getmarks(int i)
	{
		return marks[i] ;
	}

};

class admin: protected faculty
{
private:
	string *status ;

public:

	admin(): faculty()
	{
		status = NULL ;
	}

	admin(int x): faculty(x)
	{
		status = new string[x] ;
		for (int i=0; i<x; i++)
		{
			if (getmarks(i) >= 50)
			{
				status[i] = "PASS" ;
			}
			else 
			{
				status[i] = "FAIL" ;
			}
		}

		cout << "Grades for all students have been set!" << endl;
	}

	void displayMarksAndStatus()
	{
		for(int i=0; i<getnumOfStudents(); i++)
		{
			cout << "Marks of student " << i+1 << " are: " << getmarks(i) << ". They " << status[i] << endl;
		}
	}
};

class students: public admin
{
private:

	int num ;

public:

	students(): admin()
	{
		num = 0;
	}

	students(int x): admin(x)
	{

	}

	void display()
	{
		displayMarksAndStatus();
	}
};

int main()
{
int n = 0;
cout << "Enter number of students: ";
cin >> n;
students obj1(n);
obj1.display();
return 0;
} 