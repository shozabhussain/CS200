#include <iostream>
using namespace std;

class personInfo
{
private:
	string name ;
	int age ;

public:

	personInfo()
	{
		name = " " ;
		age = 0 ;
	}

	personInfo(string n, int a )
	{
		cout << "personInfo's parametrized constructor called " << endl;
		name = n ;
		age = a ;
	}

	void setName(string n)
	{
		name = n ;
	}

	string getName()
	{
		return name ;
	}

	void setAge(int a)
	{
		age = a ;
	}

	int getAge()
	{
		return age ;
	}

	void printPersonInfo()
	{
		cout << getName() << endl;
		cout << getAge() << endl;
	}
};

class father : public personInfo
{
public:

	father(): personInfo()
	{

	}

	father(string n, int a): personInfo(n, a)
	{
		cout << "father's parametrized constructor called " << endl;
	}

	void printFather()
	{
		cout << "Father's Info: " << endl;
		printPersonInfo() ;
	}
};

class mother : public personInfo
{
public:

	mother(): personInfo()
	{

	}

	mother(string n, int a): personInfo(n,a)
	{
		cout << "mother's parametrized constructor called " << endl;
	}

	void printMother()
	{
		cout << "Mother's Info: " << endl;
		printPersonInfo() ;
	}
};

class child: public father, public mother
{
private:
	string Name ;

public:

	child(): father(), mother()
	{
		cout << "child's default constructor" << endl;
		Name = " " ;
	}

	child(string name1, string name3, int age2, string name2, int age1): father(name3, age2), mother(name2, age1)
	{
		Name = name1 ;
	}

	void printChild()
	{
		cout << "Child's Info: " << Name << endl;
		printFather();
		printMother();
	}
};

int main()
{
int age1, age2 = 0;
string name1, name2, name3 = "";
cout << "Please enter child's name: ";
cin >> name1;
cout << "Please enter mother's name: ";
cin >> name2;
cout << "Please enter mother's age: ";
cin >> age1;
cout << "Please enter father's name: ";
cin >> name3;
cout << "Please enter father's age: ";
cin >> age2;
child obj(name1, name3, age2, name2, age1);
obj.printChild();
return 0;
}