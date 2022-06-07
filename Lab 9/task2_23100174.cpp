#include <iostream>
using namespace std;

void AllocateTriangularMatrix(int ***arr, int n)
{
	int **temp ;
	temp = new int*[n] ;
	for (int i=0; i<n; i++)
	{
		temp[i]= new int[n-i] ;
	}

	for (int i=0; i<n; i++)
	{
		for(int j=0; j<n-i; j++)
		{
			 temp[i][j]= 1 ;
		}

	}
	
	*arr = temp ;
	 
}

void deallocate(int ***arr, int n)
{
	for(int i=0; i<n; i++)
	{
		delete [] arr[0][i] ;
	}

	

	cout << "deallocation successful " << endl;
	 delete [] arr[0] ;
}

void input(int ***arr, int n)
{
	
	for (int i=0; i<n; i++)
	{
		for(int j=0; j<n-i; j++)
		{	
			cin >> arr[0][i][j] ;
		}
	}
}

void print(int ***arr, int n)
{
	for (int i=0; i<n; i++)
	{
		for(int k=0; k<i; k++)
		{
			cout << "0 " ;
		}
		
		for(int j=0; j<n-i; j++)
		{
			cout  << arr[0][i][j] << " " ;
		}

		cout << endl;
	}
}

int main()
{
	cout << "Enter size of matrix " << endl;
	int x = 5 ;
	cin >> x ;
	int n = x ;
	int ***arr ;
	AllocateTriangularMatrix(arr, n) ;

	input(arr, n) ;
	print(arr, n) ;
	cout << endl;
	deallocate(arr, n);
}