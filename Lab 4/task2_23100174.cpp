#include <iostream>
using namespace std;

bool CompareWords(char *arr1, char *arr2, int start)
{
	bool check= true;
	for(int i=0; i<start; i++)
	{
		if((int)arr1[i] != (int)arr2[i] && (int)arr1[i] != ((int)arr2[i]-32) &&  ((int)arr1[i]-32) != (int)arr2[i] )
		{
			check = false;
		}
	}

	return check; 
}

int  Search(char *array1, char *array2, int lengthArray1, int lengthArray2)
{	
	int occurences=0; 
	for(int i=0; i<lengthArray1-lengthArray2+1; i++)
	{
		char sample[lengthArray2];

		for(int j=0; j<lengthArray2; j++)
		{
			sample[j]= array1[i+j]; 
		}

		if(CompareWords(sample, array2, lengthArray2))
		{
			occurences++ ;
		}
	}
	return occurences;

}

int main()
{

	cout << "Please enter the size of first word " << endl;
	int sizefirst;
	cin >> sizefirst ;
	char firstWord[sizefirst];
	cout << "Please enter first word" << endl;
	for (int i=0; i<sizefirst; i++)
	{
		cin >> firstWord[i] ;
	}

	cout << "Please enter the size of second word " << endl;
	int sizesecond;
	cin >> sizesecond ;
	char secondWord[sizesecond] ;
	cout << "Please enter second word" <<endl;
	for (int i=0; i<sizesecond; i++)
	{
		cin >> secondWord[i] ;
	}

	cout << Search(firstWord, secondWord, sizefirst, sizesecond);
}