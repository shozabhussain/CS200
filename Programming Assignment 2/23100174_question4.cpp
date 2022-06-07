#include <iostream>
using namespace std;
#include <vector>

int main()
{
	vector<string> myVector;
	string input;
	input = " " ;
	while(input != "stop")
	{
		cout << "Please enter strings and enter stop to when finished " << endl;
		cin >> input ;
		myVector.push_back(input) ;
	}

	cout << endl;
	cout << "The number of names you entered are " << myVector.size()-1 << endl;
	cout << endl;
	cout << "The names you entered are as follows: " << endl;
	for (unsigned int i=0; i<myVector.size()-1; i++)
	{
		cout << myVector.at(i) << endl;
	}

	int index ;
	index = -1;
	while (index <0 || index >myVector.size()-2 || cin.fail() )
	{
		cout << "Please enter a correct index to replace at ( Index starts from 0 ) " << endl;
		cin.clear ();
		cin.ignore(10000,'\n');
		cin >> index ;
	}

	cout << "Please enter the replacement string " << endl;
	cin >> input ;
	cout << endl;

	cout << "The names you entered are as follows: " << endl;
	myVector.erase(myVector.begin()+index) ;
	myVector.insert(myVector.begin()+index, input) ;
	for (unsigned int i=0; i<myVector.size()-1; i++)
	{
		cout << myVector.at(i) << endl;
	}

	myVector.pop_back();

	index = -1;
	while (index <0 || index >myVector.size()-1 || cin.fail() )
	{
		cout << "Please enter a correct index to delete the value of ( Index starts from 0 ) " << endl;
		cin.clear ();
		cin.ignore(10000,'\n');
		cin >> index ;
	}

	myVector.erase(myVector.begin()+index+1) ;

	cout  << endl;
	cout << "The size of the vector is now: " << myVector.size() << endl;

	for (unsigned int i=0; i<myVector.size(); i++)
	{
		cout << myVector.at(i) << endl;
	}

	myVector.clear();

	cout << endl;
	if(myVector.empty())
	{
		cout << "Vector is now empty " << endl;
	}
}
