#include <iostream>
using namespace std;

class library
{
private:
	int id ;
	bool isIssued; 
	string name ;

public:

	library()
	{
		id = 0 ;
		isIssued = false;
	}

	library(string n, int i, bool issued)
	{
		name = n ;
		id = i ;
		isIssued = issued ;
	}

	void setName(string n)
	{
		name= n ;
	}

	string getName()
	{
		return name ;
	}

	void setId(int i)
	{
		id = i ;
	}

	int getId()
	{
		return id; 
	}

	void setIssued(bool issued)
	{
		isIssued = issued ;
	}

	bool getIssued()
	{
		return isIssued ;
	}

	void print()
	{
		cout << "Name: " << getName() << endl;
		cout << "ID: " << getId() << endl;
		if (getIssued())
		{
			cout << "Issue Status: Issued "  << endl;
		}
		else if (!getIssued())
		{
			cout << "Issue Status: Not Issued "  << endl;
		}
		
	}


};

class manuscripts: public library
{
public:

	manuscripts(): library()
	{

	}

	manuscripts(string n, int i, bool issue): library(n, i, issue)
	{

	}

	void printManuscript()
	{
		cout<< "manuscript details are as follows: " << endl;
		print();
	}
};

class newspaper: public library
{
public:

	newspaper(): library()
	{

	}

	newspaper(string n, int i, bool issue): library(n, i, issue)
	{

	}

	void printNewspaper()
	{
		cout<< "newspaper details are as follows " << endl;
		print();
	}
};

class book: public library
{
private:

	string author ;

public:

	book(): library()
	{
		author = " " ;
	}

	book(string n, string a, int i, bool issue): library(n, i, issue)
	{
		author = a ;
	}

	string getAuthor()
	{
		return author ;
	}

	void setAuthor(string a)
	{
		author= a ;
	}

	void printBook()
	{
		cout<< "Book details are as follows " << endl;
		print();
		cout << "Author Name: " << getAuthor() << endl;
	}
};

int main()
{
	string manuscriptName ;
	int manuscriptId ;
	bool manuscriptIssue ;

	cout << "Please enter manuscript's name " << endl;
	cin >> manuscriptName ;

	cout << "Please enter manuscript's ID " << endl;
	cin >> manuscriptId ; 

	cout << "Please enter issue status, press 1 if true and 0 if false" << endl;
	cin >> manuscriptIssue ;

	manuscripts m ;
	m.setName(manuscriptName) ;
	m.setId(manuscriptId) ;
	m.setIssued(manuscriptIssue) ;
	cout << endl;
	cout << "Printing details using print function" << endl ;
	m.printManuscript() ;

 	cout << endl ;
	cout << "Printing details using getters" << endl ;
	cout << "Name: " << m.getName() << endl;
		cout << "ID: " << m.getId() << endl;
		if (m.getIssued())
		{
			cout << "Issue Status: Issued "  << endl;
		}
		else if (!m.getIssued())
		{
			cout << "Issue Status: Not Issued "  << endl;
		}
	cout<< endl;

	string newspaperName ;
	int newspaperId ;
	bool newspaperIssue ;

	cout << "Please enter newspaper's name " << endl;
	cin >> newspaperName ;

	cout << "Please enter newspaper's ID " << endl;
	cin >> newspaperId ; 

	cout << "Please enter issue status, press 1 if true and 0 if false" << endl;
	cin >> newspaperIssue ;


	newspaper n ;
	n.setName(newspaperName) ;
	n.setId(newspaperId) ;
	n.setIssued(newspaperIssue) ;
	cout << endl;
	cout << "Printing details using print function" << endl ;
	n.printNewspaper() ;

 	cout << endl ;
	cout << "Printing details using getters" << endl ;
	cout << "Name: " << n.getName() << endl;
		cout << "ID: " << n.getId() << endl;
		if (n.getIssued())
		{
			cout << "Issue Status: Issued "  << endl;
		}
		else if (!n.getIssued())
		{
			cout << "Issue Status: Not Issued "  << endl;
		}
		cout << endl;
string bookName ;
	int bookId ;
	bool bookIssue ;
	string bookAuthor ;

	cout << "Please enter book's name " << endl;
	cin >> bookName ;

	cout << "Please enter book's ID " << endl;
	cin >> bookId ; 

	cout << "Please enter issue status, press 1 if true and 0 if false" << endl;
	cin >> newspaperIssue ;

	cout << "Please enter Author's name " << endl;
	cin >> bookAuthor ;


	book b ;
	b.setName(bookName) ;
	b.setId(bookId) ;
	b.setIssued(bookIssue) ;
	b.setAuthor(bookAuthor) ;
	cout << endl;
	cout << "Printing details using print function" << endl ;
	b.printBook() ;

 	cout << endl ;
	cout << "Printing details using getters" << endl ;
	cout << "Name: " << b.getName() << endl;
		cout << "ID: " << b.getId() << endl;
		if (b.getIssued())
		{
			cout << "Issue Status: Issued "  << endl;
		}
		else if (!b.getIssued())
		{
			cout << "Issue Status: Not Issued "  << endl;
		}
		cout << "Author Name: " << b.getAuthor() << endl;

}