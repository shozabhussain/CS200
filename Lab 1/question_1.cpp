#include <iostream>
using namespace std;

int main()
{
	int size= 1000;
	int number[size];
	for(int i=0; i<size; i++)
	{
		number[i]=0;
	}
	int i=0;
	int sum=0;
	int count5= 0;
	do
	{
		cout << "Please enter a number: ";
		cin >> number[i];
		sum= sum + number[i];
		if(number[i] == 5)
		{
			count5++;
		}
		i++;
	} while (i<10 || count5==0 || sum<100);

	cout << "total number of inputs: " << i << endl;
	cout << "sum of numbers: " << sum << endl;
	cout << "number of times 5 was entered: " << count5<< endl;

	return 0;
}