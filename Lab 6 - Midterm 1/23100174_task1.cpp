#include <iostream>
using namespace std;

class meme
{
public:
	string caption;
	string image;
	string author;

	meme()
	{
		caption = " ";
		image = " ";
		author= " ";
	}

	meme(string c, string i, string a)
	{
		caption = c;
		image = i;
		author= a;
	}

	void setCaption(string c)
	{
		caption = c ;
	}

	void setImage(string i)
	{
		image =i ;
	}

	void setAuthor(string a)
	{
		author= a;
	}

	string getCaption()
	{
		return caption;
	}

	string getImage()
	{
		return image;
	}

	string getAuthor()
	{
		return author;
	}

	void displayMeme()
	{
		cout << "Caption: " << caption << endl;
		cout << "Image: " << image << ".jpg" << endl;
		cout << "Author: " << author << endl; 
	}
};

struct memer
{
	string name;

	memer()
	{
		name = " ";
	}

	memer(string n)
	{
		name = n;
	}

	void makeMeme(meme *obj)
	{
		obj->author = name ;
		cout << "Enter Caption for your meme: " ;
		cin >> obj -> caption ;
		cout << "Enter image name name for your meme: " ;
		cin >> obj -> image ;
	}
};


int main()
{
	meme m1 ;
	memer s("shozab");
	s.makeMeme(&m1);
	m1.displayMeme();
}