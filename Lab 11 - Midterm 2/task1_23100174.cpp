#include <iostream>
using namespace std ;

void swap(int &a, int &b)
{
	int temp = a ;
	a = b ;
	b = temp ;
}

void sort(int* arr, int len)
{
	for(int j=0; j<len; j++)
	{
		for(int i=0; i<len-1; i++)
		{
			if(arr[i] > arr[i+1])
			{
				swap(arr[i], arr[i+1]) ;
			}
		}

	}
}

void print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " " ;
	}
}

bool check(int low, int high, int* arr)
{
	if(low == high)
	{
		if (arr[low] == low) 
		{
			return true;
		} 
		else 
		{
			return false;
		}
	}

	if ( low > high)
	{
		return false ;
	}
	else 
	{
		int mid = low + (high - low) / 2;

		if (mid == arr[mid])
		{
			return true;
		}
		else if (mid < arr[mid]) 
		{
			return check(low, mid - 1, arr);
		} 
		else 
		{
			return check(mid + 1, high, arr);
		}
	}
}

int main()
{
	cout << "Enter the length of the array: " ;
	int length ;
	cin >> length ;

	int* arr = new int[length] ;
	for(int i=0; i<length; i++)
	{
		cout << "Enter the element " << i+1 << " of the array: " ;
		cin >> arr[i] ;
	}

	print(arr, length);
	cout << endl;
	sort(arr, length);
	print(arr, length);
	cout << endl;
	if (check(0, length-1, arr))
	{
		cout << "True" << endl;
	}
	else 
	{
		cout << "False" << endl;
	}

	delete [] arr ;




}