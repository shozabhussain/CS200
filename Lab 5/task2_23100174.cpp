#include <iostream>
using namespace std;

class concateName
{
public:

	int size;
	string *name ;

	concateName()
	{
		size = 0;
		name = NULL ;
	}

	concateName(int s)
	{
		this->size = s;
		name = new string[s] ;
	}

	int getSize()
	{
		return size;
	}

	string getName(int i)
	{
		return *(name + i) ;
	}

	friend istream& operator >> (istream& input, concateName const& temp)
	{
		for(int i=0; i<temp.size; i++)
		{
			cout << "Enter the name for " << i+1 << " position: " ;
			input >> temp.name[i];
		}
		return input;
	}

	friend ostream& operator <<(ostream& output, concateName const& temp)
	{
		for(int i=0; i<temp.size; i++)
		{
			output << temp.name[i] << endl ;
		}
		return output;
	}

	concateName operator +(const concateName &x )
	{
		concateName temp(this->size);
		for (int i=0; i<size; i++)
		{
			*(temp.name + i) = this-> name[i] + " " + *(x.name + i) ;
		}
		return temp;
	}

};


int main()
{
	cout << "Please enter the size of your array: " << endl;
	int size;
	cin >> size;

	concateName n1(size);
	concateName n2(size);
	concateName n3(size);

	cin >> n1;
	cout << endl;
	cin >> n2;

	n3= n1 + n2 ;

	cout << n3 ;
}