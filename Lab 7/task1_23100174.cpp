#include <iostream>
using namespace std;

void display(int **arr, int row, int col)
{
	for(int i=0; i<row; i++)
	{
		cout << endl;

		for(int j=0; j<col; j++)
		{
			cout << arr[i][j] << " " ;
		}
	}
}

int main()
{
	int row;
	int col;
	cout << "Please enter the number of rows " ;
	cin >> row;
	cout << "Please enter the number of columns " ;
	cin >> col; 

	int** arr ;
	arr = new int*[row] ;

	for(int i=0; i<row; i++)
	{
		arr[i]= new int[col] ;
	}

	for(int i=0; i<row; i++)
	{
		cout << "Enter elements for row number " << i+1 << endl;

		for(int j=0; j<col; j++)
		{
			cin >> arr[i][j] ;
		}
	}

	cout << "Original Matrix is " << endl;
	display(arr, row, col) ;
	cout << endl;

	int sumofall = 0; 
	int sumofrow[row]= {0};
	int sumofcol[col]= {0};

	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			sumofall = sumofall + arr[i][j] ;
			sumofrow[i] = sumofrow[i] + arr[i][j] ;
		}
	}

	for(int i=0; i<col; i++)
	{
		for(int j=0; j<row; j++)
		{
			sumofcol[i]= sumofcol[i] + arr[j][i] ;
		}
	}

	cout << "sum of all elements in matrix: " << sumofall << endl;
	for (int i=0; i<row; i++)
	{
		cout << "Sum of elements in row " << i+1 << ": " << sumofrow[i] << endl; 
	} 

	for (int i=0; i<col; i++)
	{
		cout << "Sum of elements in column " << i+1 << ": " << sumofcol[i] << endl; 
	} 

	int** arr1 ;
	arr1 = new int*[row] ;

	for(int i=0; i<row; i++)
	{
		arr1[i]= new int[col] ;
	}

	cout << "Enter a new matrix of the same size as previous: " << endl;
	for(int i=0; i<row; i++)
	{
		cout << "Enter elements for row number " << i+1 << endl;

		for(int j=0; j<col; j++)
		{
			cin >> arr1[i][j] ;
		}
	}
	cout << "new matrix: " << endl;
	display(arr1, row, col);
	cout << endl;

	int** arrsum ;
	arrsum = new int*[row] ;

	for(int i=0; i<row; i++)
	{
		arrsum[i]= new int[col] ;
	}

	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			arrsum[i][j] = arr[i][j] + arr1[i][j] ;
		}
	}

	cout << "By adding the two matrix we get: " << endl;
	display(arrsum, row, col);

	for(int i=0; i<row; i++)
	{
		delete [] arr[i] ;
		delete [] arr1[i] ;
		delete [] arrsum[i] ;
	}

		delete [] arr ;
		delete [] arr1;
		delete [] arrsum;
}
