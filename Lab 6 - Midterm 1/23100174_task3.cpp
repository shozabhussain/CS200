#include <iostream>
using namespace std;

class BookShelf
{
private:
	int *shelf ;
	int no_of_books;
	string genre;

public:

	BookShelf()
	{
		shelf= NULL ;
		no_of_books= 0; 
		genre= " " ;
	}

	BookShelf(int nobooks, string g)
	{
		no_of_books= nobooks ;
		genre = g ;
		shelf = new int[no_of_books];
	}

	void setShelf(int size)
	{
		
		shelf = new int[size] ;
	}

	void setShelfid(int i, int id)
	{
		shelf[i] = id;
	}

	void setNo_of_books(int n)
	{
		no_of_books = n;
	}

	void setGenre(string g)
	{
		genre = g ;
	}

	int getShelf(int i)
	{
		return shelf[i] ;
	}

	int getNo_of_books()
	{
		return no_of_books;
	}

	string getGenre()
	{
		return genre ;
	}

	void print()
	{
		cout << "No of books: " << no_of_books << endl;
		cout << "Genre: " << genre << endl;
		cout << "Identification numbers are as follows: " << endl;
		for (int i=0; i<no_of_books; i++)
		{
			cout << getShelf(i) << endl;
		}
	}

	BookShelf operator +(const BookShelf& x)
	{
		BookShelf temp;
		temp.no_of_books= this->no_of_books + x.no_of_books ;
		temp.genre = this-> genre + " and " + x.genre ;
		temp.setShelf(temp.no_of_books) ;
		for (int i=0; i<this->no_of_books; i++)
		{
			temp.shelf[i] = this->shelf[i] ;
		}
		for (int i=this->no_of_books; i<x.no_of_books; i++)
		{
			temp.shelf[i] = x.shelf[i] ;
		} 
		return temp ;
	}

	BookShelf operator -(const BookShelf& x)
	{
		BookShelf temp;
		temp.no_of_books= x.no_of_books - this->no_of_books;
		temp.setShelf(temp.no_of_books);
		if (temp.no_of_books > 0 )
		{
			temp.genre = x.genre;
			for (int i=0; i<temp.no_of_books; i++)
			{
				temp.shelf[i] = x.shelf[i] ;
			} 
		}
		else if ( temp.no_of_books <= 0 )
		{
			temp.genre = "None";
			temp.no_of_books= 0;
		}
		return temp;
	}

	BookShelf(const BookShelf &x)
	{
		no_of_books = x.no_of_books;
		genre = x.genre;
		for (int i=0; i<no_of_books; i++)
		{
			shelf[i] = x.shelf[i] ;
		}
	}

	~BookShelf()
	{
		delete[] shelf ;
	}
};

int main()
{
	BookShelf b1, b2, b3, b4 ;
	int n;
	string g ;
	cout << "Number of Books: " ;
	cin >> n ;
	cout << endl;
	cout << "Genre: " ;
	cin >> g ;
	cout << endl;
	cout << "Identification numbers are as follows: " << endl;
	b1.setGenre(g);
	b1.setNo_of_books(n);
	b1.setShelf(n);
	for (int i=0; i<n; i++)
	{
		int id=0;
		cin >> id;
		b1.setShelfid(i, id);
		
	}

	//b1.print();

	//int n;
	//string g ;
	cout << "Number of Books: " ;
	cin >> n ;
	cout << "Genre: " ;
	cin >> g ;
	b2.setGenre(g);
	cout << "Identification numbers are as follows: " << endl;
	b2.setNo_of_books(n);
	b2.setShelf(n);
	for (int i=0; i<n; i++)
	{
		int id=0;
		cin >> id;
		b2.setShelfid(i, id);
		
	}

	//b2.print();

	b3 = b1+ b2 ;
	b3.print();
	b4 = b1-b2;
	b4.print();
}