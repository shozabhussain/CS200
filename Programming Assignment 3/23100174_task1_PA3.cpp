#include <iostream>
using namespace std;

void inputBoard(bool** board, int rows, int cols)
{
	int input = 0;
	for(int i =0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cout << "Enter the element for row " << i+1 << " and column " << j+1 <<": " ;
			cin >> input ;

			while(cin.fail() || (input !=1 && input !=0))
			{
				cout << "Enter either 1 or 0 " ;
				cin.clear ();
      			cin.ignore(10000,'\n');
      			cin >> input ;
			}

			while(cin.fail() ||( i==0 && j==0 && input != 1))
			{
				cout<< "First element of board should be one " ;
				cin.clear ();
      			cin.ignore(10000,'\n');
				cin >> input ;
			}

			board[i][j] = input ;
		}
	}
}

void print(bool** board, int rows, int cols )
{
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cout << board[i][j] << " " ;
		}

		cout << endl;
	}
	cout << endl;
}

bool findPossibility(bool** board, int rows, int cols)
{
	int i=0;
	int j=0;
	bool check = true;
	while(1) // This loop will always try to move towards right and will only move below if there is a 0 on the right
	{
		//cout << "loop 1" << endl;
		if(i == rows-1 && j==cols-1)
		{
			return true;
		}
		if( j+1 < cols) 
		{
			if(board[i][j+1] ==1)
			{
				j= j+1 ;
				continue;
			}
		}
		if( i+1 < rows )
		{
			if (board[i+1][j] == 1)
			{
				i = i+1;
				continue;
			}
		}
		break ;
	}

	 i=0;
	 j=0;

	while(1) // This loop will always try to move below and will only move right if there is a 0 below
	{	
		//cout << "loop 2" << endl;
		if(i == rows-1 && j==cols-1)
		{
			return true;
		}
		if( i+1 < rows )
		{
			if (board[i+1][j] == 1)
			{
				i = i+1;
				continue;
			}
		}
		if( j+1 < cols) 
		{
			if(board[i][j+1] ==1)
			{
				j= j+1 ;
				continue;
			}
		}
		break ;
	}

	i=0;
	j=0;
	int count=0;

	while(1) // This loops first runs as coloumn oriented and then as row oriented. 
	{	
		//cout << "loop 3" << endl;
		count++;
		if( count % 2 != 0 )
		{

			if(i == rows-1 && j==cols-1)
			{
				return true;
			}
			if( j+1 < cols) 
			{
				if(board[i][j+1] ==1)
				{
					j= j+1 ;
					continue;
				}
			}
			if( i+1 < rows)
			{
				if(board[i+1][j] == 1)
				{
					i= i+1;
					continue;
				}
			}

			continue ;
		}

		else if (count%2 == 0)
		{
			if(i == rows-1 && j==cols-1)
			{
				return true;
			}
			if( i+1 < rows  )
			{
				if (board[i+1][j] == 1)
				{
					i = i+1;
					continue;
				}
			}
			if( j+1 < cols) 
			{
				if(board[i][j+1] ==1)
				{
					j= j+1 ;
					continue;
				}
			}

			break ;
		}
	}

	i =0;
	j =0;
	count =0;

	while(1) // This loop first runs as row oriented and then as coloumn oriented
		{	
			//cout << "loop 4" << endl;
			count++;
			if( count % 2 != 0 )
			{
				if(i == rows-1 && j==cols-1)
				{
					return true;
				}
				if( i+1 < rows  )
				{
					if (board[i+1][j] == 1)
					{
						i = i+1;
						continue;
					}
				}
				if( j+1 < cols) 
				{
					if(board[i][j+1] ==1)
					{
						j= j+1 ;
						continue;
					}
				}
				
			continue;
			}
			else if (count%2 == 0)
			{
				if(i == rows-1 && j==cols-1)
				{
					return true;
				}
				if( j+1 < cols) 
				{
					if(board[i][j+1] ==1)
					{
						j= j+1 ;
						continue;
					}
				}
				if( i+1 < rows  )
				{
					if (board[i+1][j] == 1)
					{
						i = i+1;
						continue;
					}
				}

				break ;
			}
		}
	return false ;
}
int main()
{
	cout << "Enter the number of rows: " ;
	int rows;
	cin >> rows;
	while (cin.fail() || rows <= 0)
	{
		cout << "Enter correct number of rows " ;
		cin.clear ();
      	cin.ignore(10000,'\n');
		cin >> rows ;
	}
	cout << "Enter the number of coloumns: " ;
	int cols;
	cin >> cols ;
	while (cin.fail() || cols <= 0)
	{
		cout << "Enter correct number of coloumns " ;
		cin.clear ();
      	cin.ignore(10000,'\n');
		cin >> cols ;
	}

	bool **board ;
	board = new bool*[rows]; 
	for(int i=0; i<rows; i++)
	{
		board[i]= new bool[cols] ;
	}

	inputBoard(board, rows, cols);
	print(board, rows, cols) ; 
		if (findPossibility(board,rows, cols))
		{
			cout << "True " << endl;
		}
		else
		{
			cout << "False" << endl;
		}
}