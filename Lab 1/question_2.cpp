#include <iostream>
using namespace std;

bool trianguler(int num)
{
	bool check = false;
	if (num == 1 || num==0)
	{
		check= true;
	}
	else
	{
		int i=1;
		while (!check)
		{
			num=num-i;
			i++;
			if (num<i)
			{
				break;
			}
			else if( num==i)
			{
				check= true;
				break;
			}
			
		}
	}
	return check;
}

int main()
{
	cout << "Enter a number: " ;
	int number;
	cin >> number;
	if (trianguler(number))
	{
		cout << "true" ;
	}
	else if (!trianguler(number))
	{
		cout << "false" ;
	}
	return 0;
}