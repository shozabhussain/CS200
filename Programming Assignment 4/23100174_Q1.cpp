#include <iostream>
using namespace std;

struct node
{
public:

	int value ;
	node *next ;

	node()
	{
		value = 0 ;
		next = NULL ;
	}

	node(int x)
	{
		value = x ;
		next = NULL ;
	}
};

class linkedList
{

public:

	node *root ;

	linkedList()
	{
		root = NULL ;
	}

	void insert(int x)
	{
		node *temp = new node ;
		temp -> value = x ;
		if(root == NULL )
		{
			root = temp ;
		}
		else
		{ 
			temp = root ;
			while(temp -> next != NULL)
			{
				temp = temp ->next ;
			}

			node *temp2 = new node ;
			temp2 -> value = x ;
			temp2 -> next = NULL ;
			temp -> next = temp2 ; 
		}	
	}

	print()
	{	
		node *temp = new node;
		temp = root ;
		cout << "[" ;
		while(temp != NULL)
		{
			if ( temp -> value == 999999 )
			{
				cout << "" ;
				temp = temp -> next ;
			}
			else if (temp -> next == NULL)
			{
				cout << temp -> value ;
				temp = temp -> next ;
			}
			else
			{
				cout << temp -> value << ", ";
				temp = temp -> next ;
			}
		}
		cout << "] " ;
	}

	int length()
	{
		node *temp = new node ;
		temp = root ;
		int count = 0 ;
		while(temp != NULL)
		{
			count ++ ;
			temp = temp->next ;
		}

		return count ;
	}

};

linkedList* splitListToParts(node *n, int k, int l)
{
	linkedList *arr = new linkedList[k] ;
	node *ptr = new node ;
	ptr = n ;

	if( l/k > 0 && l%k == 0)
	{
		for(int i=0; i<k; i++)
		{
			node *temp = new node ;

			for(int j=0 ; j<(l/k); j++ )
			{
				arr[i].insert(ptr -> value) ;
				temp = ptr ;
				ptr = ptr -> next ;
			}
		}

		//for(int i=0; i<k; i++)
		//{
		//	arr[i].print() ;
		//	cout << endl;
		//}
		return arr ;
	}

	else if( l/k > 0 && l%k != 0)
	{
		int sizeSmall = l/k ;
		int sizeBig = sizeSmall + 1 ;
		int noBig = 0;
		int noSmall = 0 ;

		while(1)
		{
			l = l - sizeSmall ;
			noSmall++ ;
			if( l % sizeBig == 0 )
			{
				break ;
			}
		}

		noBig = l/sizeBig ;

		for(int i=0; i<k; i++)
		{
			node *temp = new node ;

			if( i < noBig )
			{
				for(int j=0 ; j<sizeBig; j++ )
				{
					arr[i].insert(ptr -> value) ;
					temp = ptr ;
					ptr = ptr -> next ;
				}
			}
			else 
			{
				for(int j=0 ; j<sizeSmall; j++ )
				{
					arr[i].insert(ptr -> value) ;
					temp = ptr ;
					ptr = ptr -> next ;
				}
			}	
		}

		//for(int i=0; i<k; i++)
		//{
		//	arr[i].print() ;
		//	cout << endl;
		//}

		return arr ;
	}
	else if( l/k == 0)
	{
		for(int i=0; i<k; i++)
		{
			node *temp = new node ;

			if( i > l-1 )
			{
					arr[i].insert(999999) ;
					temp = ptr ;
			}
			else
			{
					arr[i].insert(ptr -> value) ;
					temp = ptr ;
					ptr = ptr -> next ;
			}
		}

		//for(int i=0; i<k; i++)
		//{
		//	arr[i].print() ;
		//	cout << endl;
		//}

		return arr ;
	}
}

int main()
{
	node *head = new node ;
	head -> next = NULL ;
	linkedList l;

	cout << "Enter elements for the linked list (enter an alphabet when done): " ;
	int input ;
	while( 1 )
	{
		cin >> input ;
		if(cin.fail())
		{
			break ;
		}

		l.insert(input) ;
	}

	cin.clear ();
    cin.ignore(10000,'\n');
    cout << "root= " ;
	l.print();
	cout << endl ;

	cout << "Please enter the number of parts in which you want to split the list: " ;
	int parts ;
	cin >> parts ;

	while(parts <=0 || cin.fail())
	{
		cin.clear ();
      	cin.ignore(10000,'\n');
      	cout << "number of parts should be greater than 0 " ;
      	cin >> parts ;
	}

	int length = l.length();

	linkedList *answer ;

	answer = splitListToParts(l.root, parts, length);

	cout << "Output: [ " ;
	for(int i=0; i<parts; i++)
	{
		answer[i].print() ;
	}
	cout << " ]" ;

}