#include <iostream>
using namespace std;

string encrypt(string& a, int n){

	int l= sizeof(a) / sizeof(a[0]);

	for (int i=0; i<l; i++){

		if (a[i]-n > 64 && a[i]-n <90){
		a[i]= a[i]- n;
		
		} 

		else{

			int rem= n-(a[i]-64);
			a[i]= 90-rem;
		}
	}

	return a;
}

string decrypt(string& a, int n)
{

	int l= sizeof(a)/sizeof(a[0]);
	for (int i=0; i<l; i++)
	{
		if (a[i]+n > 64 && a[i]+n <90){
		a[i]= a[i]+ n;
		}
		else{

			int rem= n-(90-a[i]);
			a[i]= 64+rem;
		}
	
	}

	return a;
}

	
int main()
{	
	string input;
 	cout << "Enter a string (CAPITAL LETTERS): ";
 	cin >> input;
 	bool check= true;
 	for (int i=0; i<input.length(); i++)
 	{
 		 if(input[i]<65 || input[i]>90)
 		 {
 		 	check= false;
 		 	main();
 		 }
 	}
 
 	cout << "Enter the shift length: ";
 	int n;
 	cin >>n;
 	char response;
 	cout << "Press E for encrypt or D for decrypt: " ;
 	cin >> response;
	
 	if (response == 'E')
 	{
 		encrypt(input, n);
 		cout << "Cipher: " << input << endl;
 	}
 	else if (response == 'D')
 	{
 		decrypt(input, n);
 		cout << "Decipher: " << input << endl;	
 	}
 	



}

	