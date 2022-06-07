#include <iostream>
using namespace std;

struct Swap
{
	int oddSwap(int *Arr, int n)
	{
		for(int i=0; i<n; i++)
		{	
			if(i == n-1 && n-1%2 != 0)
			{
				Arr[n-1] = -1*Arr[1];
				int temp = Arr[n-1];
				temp = -1*temp;
				Arr[n-1]= temp;
				break;
			}
			else
			{
				int temp = Arr[i+1];
				Arr[i+1]= Arr[i+3];
				Arr[i+3] = temp;
				i++;
				i++;
				i++;
			}
		}
		return *Arr;
	}
};

int main()
{
	cout << "Enter 8 integars for Array1 " << endl;
	int Array1[8];
	for (int i=0; i<8; i++)
	{
		cin >> Array1[i];
	}

	cout << "Enter 10 integars for Array2 " << endl;
	int Array2[10];
	int *pArray2 = Array2;
	for (int i=0; i<10; i++)
	{
		cin >> Array2[i];
	}

	cout << " inputArray_1: " << endl;
	for (int i=0; i<8; i++)
	{
		cout << Array1[i] << ", " ;
	}
	cout << "" << endl;

	Swap *ptr = NULL;
	ptr = new Swap;

	ptr -> oddSwap(Array1, 8);

	cout << " outputArray_1: " << endl;
	for (int i=0; i<8; i++)
	{
		cout << Array1[i] << ", " ;
	}
	cout << "" << endl;

	cout << " inputArray_2: " << endl;
	for (int i=0; i<10; i++)
	{
		cout << Array2[i] << ", " ;
	}
	cout << "" << endl;

	ptr -> oddSwap(Array2, 10);

	cout << " outputArray_2: " << endl;
	for (int i=0; i<10; i++)
	{
		
		cout << Array2[i] << ", " ;
	}








}