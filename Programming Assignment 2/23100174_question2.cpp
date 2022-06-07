#include <iostream>
using namespace std;

void print(char** arr, int row, int*col )
{
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col[i]; j++)
		{
			cout << arr[i][j] << " " ;
		}

		cout << endl;
	}
	cout << endl;
}

int main()
{	
	int row ;
	cout << "Enter the number of rows " << endl;
	cin >> row ;

	char **arr ;
	arr = new char*[row] ;

	int *col ;
	col = new int[row] ;

	int*dup ;
	dup = new int[row] ;

	for(int i=0; i<row; i++)
	{
		cout << "Please enter the number of columns for row " << i+1 << endl;
		cin >> col[i] ;

		arr[i] = new char[col[i]] ;

		for(int j=0; j<col[i]; j++)
		{
			cout << "Please enter element " << j+1 << endl;
			cin >> arr[i][j] ;
		}
		cout << endl;
	} 

	print(arr, row, col ) ;


	for(int i=0; i<row; i++)       // stores & in place of duplicates
	{
		for(int j=0; j<col[i]; j++)
		{	
			int a =1;
			while( j<col[i] && arr[i][j+a] == arr[i][j] )
			{
				arr[i][j+a] = '&' ;
				a++ ;
				
			}

			j+a-1 ;
		}
	}

	print(arr, row, col ) ;

	for(int i=0; i<row; i++)         // stores the number of & for each column in the array dup
	{	
		dup[i] = 0 ;
		for(int j=0; j<col[i]; j++)
		{
			if(arr[i][j] == '&')
			{
				dup[i]++ ;
			}
		}
	}

	char **temp ;
	temp = new char*[row];

	for(int i=0; i<row; i++)
	{
		temp[i] = new char[ (col[i] - dup[i]) ] ;
	}

	int k=0 ;
	for(int i=0; i<row; i++)      // stores values other than & in the new temp 2D array
	{ 
		int l= 0 ;

		for(int j=0; j<col[i]; j++)
		{
			if(arr[i][j] != '&')
			{
				temp[k][l] = arr[i][j] ;
				l++ ;
			}
		}
		k++;
	}

	for(int i=0; i<row; i++)
	{
		col[i] = col[i] - dup[i] ;  // updates the col array by removing the number duplicates in each row
	}

	for(int i=0; i<row; i++)
	{
		delete [] arr[i] ;
		arr[i] = temp[i] ;
	}

	print(arr, row, col) ;

	for(int i=0; i<row; i++)
	{
		delete [] arr[i] ;
		delete arr ;
	}
	
		cout << "Data successfully deleted " << endl;
}
