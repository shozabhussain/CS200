#include <iostream>
using namespace std;

void sortArray(int *array, int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			if(array[j+1] < array[j])
			{
				int temp = array[j+1] ;
				array[j+1] = array[j];
				array[j] = temp ;
			}
		}
	}
}

void printArray(int *array, int size)
{
	for(int i=0; i<size; i++)
	{
		cout << array[i] << " " ;
	}
}

int occur(int *array, int size, int c)
{
	int occurence=0;
	for(int i=0; i<size; i++)
	{
		if(array[c] == array[c+1])
		{
			occurence++;
		}
		else 
		{
			return occurence;
		}
	}
	return occurence ;
}

int main()
{
	int size;
	cout << "Please input the size of the array: " ;
	cin >> size ;

	int array[size];
	for (int i=0; i<size; i++)
	{
		cout << "Please input the " << i+1 << " element of the array: " ;
		cin >> array[i];
	}
	cout << endl;
	cout << "The sorted Array is: " ;
	sortArray(array, size);
	printArray(array, size);
	cout << endl;
	cout << "The range of the array is: " ;
	cout << array[size-1]-array[0];
	cout << endl;

	double mean=0 ;
	for (int i=0; i<size; i++)
	{
		mean = array[i] + mean ;
	}

	mean = mean/size ;
	cout << "The mean of the array is: ";
	cout << mean ;
	cout << endl;

	double median;
	if (size%2 !=0)
	{
		int index = (size+1)/2 ;
		median = array[index-1];
	}
	else if (size%2 == 0)
	{
		int index= size/2 ;
		median = (array[index] + array[index-1] ) ;
		median = median/2.0 ;
	}

	cout << "The median of the array is: ";
	cout << median;
	cout << endl;

	int mode=0 ;
	int count=0;
	int currentModeCount =0 ;

	for(int i=0; i<size; i++)
	{
		if(array[i] == array [i+1])
		{
			count++;
		}
		else
		{
			if(count > currentModeCount )
			{
				currentModeCount = count ;
				mode = array[i] ;
				count =0;
			}
			else if(count == currentModeCount && mode > array[i])
			{
				currentModeCount= count;
				mode = array[i];
				count =0 ;
			}
		}
	}
	cout << "The mode of the Array is: " ;
	cout << mode ;
}