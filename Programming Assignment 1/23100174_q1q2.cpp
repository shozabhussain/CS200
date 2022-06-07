#include <iostream>
#include <stdlib.h>
#include <string>
#include <string>
using namespace std;
// #include <string>; 


//////////////////////////////// Q(1)(a) //////////////////////////////

/*  void Swap( int *a , int *b)
{
	*a = *a + *b ;
	*b = *a - *b ;
	*a = *a - *b ;
}

int main()
{

	
	cout << " Q(1)(a): Please enter two integars to swap them " << endl;
	int x=0 ;
	int y=0; 
	cin >> x >> y ;
	int *ptrx = &x;
	int *ptry = &y;


	Swap(ptrx, ptry);
	cout << endl;
	cout << x << " " << y << endl;
	cout << "End of Q(1)(a) " << endl;
	
}
*/

/////////////////////////// End of Q(1)(a) ////////////////////////////////

/////////////////////////////// Q(1)(b) /////////////////////////////////////

/* char reverseArray(char *arr, int n)
{
	
	for(int j=0; j<n; j++)
	{
		for(int i=0; i<n-1-j; i++)
		{
			char temp = arr[i];
			arr[i] = arr[i+1] ;
			arr[i+1] = temp ;
		}
	}
	return *arr;
}

int main()
{
	cout << "Q(1)(b): " << endl;
	cout << "Please enter the array you want to reverse, enter '.' to stop " <<endl ;
	char array[10000];
	int size = 0 ;

	for(int i=0; i<10000; i++)
	{
		cin >> array[i];
		if( array[i] == '.')
		{
			break;
		}
		else
		{
			size ++;
		}
	}
	system("CLS");
	cout << "Your input:[ " ;
	for (int i=0; i<size; i++)
	{
		cout << array[i] << ", " ;
	}
	cout << "]" << endl;

	reverseArray(array, size);

	cout << "Your output:[ " ;
	for (int i=0; i<size; i++)
	{
		cout << array[i] << ", " ;
	}
	cout << "]" << endl;
	cout << endl;
	cout << "End of Q(1)(b) " << endl;
}
*/

/////////////////////////// End of Q(1)(b) ////////////////////////////////

/////////////////////////////// Q(1)(c) /////////////////////////////////////

/* void arrayUnionIntersection()
{
	cout << " Q(1)(C): "<< endl;
	cout << endl;

	int array1size;
	cout << "Enter the size of Array1: " ;
	cin >> array1size ;
	int array1[array1size];
	for (int i=0; i<array1size; i++)
	{
		cout << " Element " << i << ", " << "Array 1: " ;
		cin>> *(array1+i) ;
	}
	cout << endl;

	int array2size;
	cout << "Enter the size of Array2: " ;
	cin >> array2size ;
	int array2[array2size];
	for (int i=0; i<array2size; i++)
	{
		cout << " Element " << i << ", " << "Array 2: " ;
		cin>> *(array2+i) ;
	}
	cout << endl;

	int intersection[array1size];
	int sizeofintersection=0 ;
	for(int i=0; i<array1size; i++) // This nested loop will shift all common elements from both sets into the array of intersection
	{
		for(int j=0; j<array2size; j++)
		{
			if(*(array1+i) == *(array2+j))
			{
				*(intersection+sizeofintersection)= *(array1+i);
				sizeofintersection++ ;
				continue;
			}
		}
	}

	int finalintersection[sizeofintersection];

	finalintersection[0]= intersection[0]; 
	int countintersection =1 ;

	for(int j=1; j<sizeofintersection; j++) // This nested loop will remove all the repeating elements in the array of intersection
	{
		bool check= true;
		for(int i=0; i<j; i++)
		{
			if( *(intersection+j) == *(finalintersection+i) )
			{
				check= false;
			}
		}

		if(check)
		{
			*(finalintersection+countintersection)= *(intersection+j);
			countintersection ++;
		}
	}

	int totallength= array1size+ array2size ;
	int Union[totallength];

	for(int i=0; i<array1size; i++) // This loop puts all the elements of array 1 into the union array
	{
		*(Union+i)= *(array1+i) ;
	}

	for(int i=0; i<array2size; i++) // This loop puts all the elements of array2 into the union array
	{
		*(Union+array1size+i)= *(array2+i) ;
	}

	int finalunion[totallength];

	*(finalunion+0)= *(Union+0);
	int countunion =1 ;

	for(int j=1; j<totallength; j++) // This nested loop will remove all the repeating elements from union array
	{
		bool check= true;
		for(int i=0; i<j; i++)
		{
			if( *(Union+j) == *(finalunion+i) )
			{
				check= false;
			}
		}

		if(check)
		{
			*(finalunion+countunion)= *(Union+j);
			countunion ++;
		}
	}

	for(int i=0; i<countintersection; i++) // This will sort the intersection array
	{
		for(int i=0; i<countintersection; i++)
		{
			if( *(finalintersection+i) > *(finalintersection+i+1) )
			{
				int temp= *(finalintersection+i);
				*(finalintersection+i) = *(finalintersection+i+1) ;
				*(finalintersection+i+1) = temp;
			}
		}
	}

	cout << "Intersection: { " ; // Prints the intersection array
	for(int i=0; i<countintersection; i++)
	{
		cout << *(finalintersection+i) << ", "  ;
	}
	cout << " }"<< endl;

	for(int i=0; i<countunion; i++) // This will sort the union array
	{
		for(int i=0; i<countunion; i++)
		{
			if( *(finalunion+i) > *(finalunion+i+1) )
			{
				int temp= *(finalunion+i);
				*(finalunion+i) = *(finalunion+i+1) ;
				*(finalunion+i+1) = temp;
			}
		}
	}

	cout << "Union: { " ; // This will print the union array
	for(int i=0; i<countunion; i++)
	{
		cout << *(finalunion+i) << ", " ;
	}
	cout << " }" << endl;
	cout << endl;	
	cout << "End of Q(1)(C) " << endl; 
}

int main()
{	

	arrayUnionIntersection();
}
*/

/////////////////////////// End of Q(1)(c) ////////////////////////////////

/////////////////////////// Q(1)(d) ////////////////////////////////


/* int searchInsertPos(int *arr, int s, int n)
{
    int position=s ;
    for(int i=0; i<s; i++)
    {
    
        if(*(arr+i) == n)
        {
            position= i;
            break;
        }
        else if( n< *(arr+i) )
        {
            position = i ;
            break;
        }
        
    }
    return position;
}    

int main()
{
	cout << "Please enter the size of the array " << endl;
	int size;
	cin >> size;
	int array[size];
	cout << "Please enter the sorted array " << endl;
	for(int i=0; i<size; i++)
	{
		cin >> array[i];
	}
	cout << endl;
	cout << "Please enter the integar value " << endl;
	int integar;
	cin >> integar;

  int *ptr= array;
  cout << endl;
  cout << "Your integar would be found on " ;
  cout << searchInsertPos(ptr, size, integar ) ;
  cout << "th index " << endl; 
}
*/

/////////////////////////// Q(2)(a) ////////////////////////////////

/* bool checkPalindrome( string s )
{
	int l= s.length();
	int n=l;
	bool check= true;

	if(l%2 != 0)
	{
		n=n-1;
	}

	for(int i=0; i<n/2; i++)
		{
			if(s[i] != s[l-1-i])
			{
				check = false;
				break;
			}
		}
		return check;
}

string RemoveElement(string s, int n)
{
	int j=0;
	int l= s.length();
	string sample= s.substr(0, l-1) ;
	for(int i=0; i<l; i++)
	{
		if(i != n)
		{
			sample[j]= s[i];
			j++;
		}
	
	}

	return sample;
}


bool PalindromeDelete(string a)
{
	int l= a.length();
	bool check= false;
	if (checkPalindrome(a))
	{
		check= true;
	}
	else 
	{
		for(int i=0; i<l; i++)
		{
			if (checkPalindrome(RemoveElement(a,i)))
			{
				check = true;
			}
		}
	}

	return check;
}




int main()
{
	cout << "Please enter your string " << endl;
	string a ;
	cin >> a ;

	if (PalindromeDelete(a))
	{
		cout << "Output: True " << endl;
	}
	else 
	{
		cout << "Output: False " << endl;
	}
}
*/
/////////////////////////// End of Q(2)(a) ////////////////////////////////

/////////////////////////// Q(2)(b) ////////////////////////////////

/* void targetSum(int *arr, int n, int t)
{
	int i=0;
	int j=0;
	int k=0;
	bool check = true;
	int combination[n^2]; // it's the size when every pair  of element sums to target so size of this can never be bigger than this
	while(check)
	{	

		if( *(arr+k) + *(arr+1+i+k) == t ) // sums the Kth element of array with all the proceeding elements and check if sum equals the target
		{
			*(combination+j) = *(arr+k);
			*(combination+j+1) = *(arr+i+1+k); // if equals to target then add those elements to the combination array 
			j++;
			j++;
		} 

		if (i+1+k == n-1) // if no proceeding element is left then the element right to the Kth element will be checked everyother proceeding elements
		{

			i=0;
			k++;	
		}
		else 
		{	

			i++ ;
		}

		if (k == n-1) // if the Kth element is the last element then stop and print all the combinations with 999 in between
		{
			for (int z=0; z<j; z++)
			{
				if(z%2 == 0 && z !=0 )
				{
					cout << "999, " ;
				}

				cout << *(combination+z) << ", " ;
			}
		check = false ; // this will be falsed when Kth element is the last element so that loop can stop
			
		}

	}

}

int main()
{
	cout << "Please enter the size of array " << endl;
	int size; 
	cin >> size ;
	int array[size];
	cout << "Please enter the sorted array " << endl;
	for (int i=0; i<size; i++)
	{
		cin >> array[i] ;
	}
	cout << "Please input your target " << endl;
	int target;
	cin >> target; 
	system("CLS");
	cout << "Input: [ " ;
	for (int i=0; i<size; i++)
	{
		cout  << array[i] << ", ";
	}
	cout << "], " ;
	cout << "target = " << target << endl;
	cout << endl;
	cout << "Output: [ " ;
	targetSum(array, size, target);
	cout << " ]" ;

}
*/
/////////////////////////// End of Q(2)(b) ////////////////////////////////
