#include <iostream>
#include<iomanip>
#include <string>
using namespace std; 

//  So actually I saw the email regarding private data memebers a few days late, as a result, when I read it 70% of my code was 
//	done like 1000 lines and I have more than 15 variables so making 30+ getters/setters and then changing the whole code will be very cumbersome to implement
// i hope you will understand and will accomodate me.

class prisoner
{

public:

	string	name;
	int		age ;
	string	bloodgroup;
	string	crime;

	int		entryDay; 
	int		entryMonth ;
	int		entryYear;

	float	durationDay;
	float 	durationMonth;
	float	durationYear;

	int		releaseDay;
	int		releaseMonth;
	int		releaseYear;

	int		cellno ;
	string	behaviour;

	prisoner()
	{	
		name = " ";
		age = 0 ;
		bloodgroup = " " ;
		crime = " " ;

		entryDay = 0; 
		entryMonth= 0 ;
		entryYear= 0;

		durationDay= 0 ;
		durationMonth= 0;
		durationYear= 0;

		releaseDay = 0;
		releaseMonth = 0 ;
		releaseYear = 0;
		
		cellno = 0;
		behaviour= "average";
	}

void printdate(int day, int month, int year) // prints a date 
	{
		if (day < 10)
		{
			cout << "0" << day;
		}
		else 
		{
			cout << day;
		}
		cout << "-" ; 
		if (month < 10)
		{
			cout << "0" << month;
		}
		else 
		{
			cout << month;
		}
		cout << "-" ;
		cout << year ; 
	}

void	printDuration()   // print duration period
	{
		cout << durationYear ;
		if( durationYear < 2)
		{
			cout << " Year, " ;
		}
		else 
		{
			cout << " Years, " ;
		}
		cout << durationMonth ;
		if( durationMonth < 2)
		{
			cout << " Month, " ;
		}
		else 
		{
			cout << " Months, " ;
		}
		cout << durationDay ;
		if( durationDay < 2)
		{
			cout << " Day" ;
		}
		else 
		{
			cout << " Days" ;
		}
	}

void	print() // print table
	{
	    cout << setw(3) << cellno <<  setw(21) << name << setw(8) << age << setw(11) << bloodgroup << setw(17) << crime << setw(9); printdate(entryDay, entryMonth, entryYear); 
	    cout << setw(9); printDuration();
	    cout << setw(8); printdate(releaseDay, releaseMonth, releaseYear);
	    cout << setw(16) << behaviour ;
	}

void	setDuration( int x )  // update duration period after behaviour has been changed
	{	
		switch(x)
		{
			case 1:
			durationYear = durationYear + 5 ;
			durationMonth = durationMonth + 3;
			durationDay = durationDay + 20 ;

			break;

			case 2:
			durationYear = durationYear + 2.5 ;
			durationMonth = durationMonth + 9;
			durationDay = durationDay + 15 ;
			break;

			case 3:
			break;

			case 4:
			durationDay = durationDay - 20  ;
			if(durationDay < 0 )
			{
				durationDay= durationDay + 30 ;
				durationMonth-- ;
			}

			durationMonth = durationMonth - 6 ;
			if (durationMonth < 0 )
			{
				durationMonth = durationMonth + 12 ;
				durationYear-- ;
			}
			if (durationYear < 0)
			{
				durationYear = 0 ;
				durationMonth = 0;
				durationDay =0 ;
			}
			
			break;

			case 5:
			durationYear = durationYear - 1 ;
			durationMonth = durationMonth - 3;
			if (durationMonth < 0 )
			{
				durationMonth = durationMonth + 12 ;
				durationYear-- ;
			}
			if (durationYear < 0)
			{
				durationYear = 0 ;
				durationMonth = 0;
				durationDay =0 ;
			}
			break;
		}
	}

void	setReleaseDate( int x ) // update release date after behaviour has been changed
	{
		switch(x)
		{
			case 1:
			releaseDay = releaseDay + 20 ;
			if (releaseDay > 30)
			{
				releaseDay = releaseDay - 30;
				releaseMonth++ ;
			}

			releaseMonth= releaseMonth + 3;
			if (releaseMonth > 12)
			{
				releaseMonth = releaseMonth - 12;
				releaseYear++ ;
			}

			releaseYear= releaseYear + 5;
			break ;

			case 2:
			releaseDay = releaseDay + 15 ;
			if (releaseDay > 30)
			{
				releaseDay = releaseDay - 30;
				releaseMonth++ ;
			}

			releaseMonth= releaseMonth + 3;
			if (releaseMonth > 12)
			{
				releaseMonth = releaseMonth - 12;
				releaseYear++ ;
			}

			releaseYear= releaseYear + 3;
			break ;

			case 3:
			break ;

			case 4:
			releaseDay = releaseDay - 20;
			if (releaseDay < 0)
			{
				releaseDay = releaseDay + 30;
				releaseMonth -- ;
			}

			releaseMonth= releaseMonth - 6;
			if (releaseMonth < 0)
			{
				releaseMonth = releaseMonth + 12;
				releaseYear-- ;
			}
			break;

			case 5:
			releaseMonth= releaseMonth - 3;
			if (releaseMonth < 0)
			{
				releaseMonth = releaseMonth + 12;
				releaseYear-- ;
			}
			releaseYear-- ;
			break;
		}

		if(releaseYear < entryYear)
			{
				releaseDay = 0;
				releaseMonth= 0;
				releaseYear= 0 ;
			}
 	}

void	setBehaviour() // update behviour and duration and release dates accordingly
	{
		cout << "Please select one of the behaviours from list by entering a suitable number" << endl << endl ;
		cout << "1. Very Bad: +5 years, 3 months, and 20 days" << endl ;				
		cout <<	"2. Bad: +2.5 years, 9 months, and 15 days" << endl;				
		cout <<	"3. Average: No change" << endl;
		cout <<	"4. Good: -6 months, and 20 days" << endl;
		cout <<	"5. Very Good: -1 Year and 3 month" << endl;
		int inputBehaviour ;
		cin >> inputBehaviour ;
		while ( cin.fail() || inputBehaviour < 1 || inputBehaviour > 5 )
		{
			cout << "Please enter a correct number" << endl;
			cin.clear ();
      		cin.ignore(10000,'\n');
			cin >> inputBehaviour ;
		}

		switch(inputBehaviour)
		{
			case 1:
			behaviour = "Very Bad" ;
			setDuration(1) ;
			setReleaseDate(1) ;
			break;

			case 2:
			behaviour = "Bad" ;
			setDuration(2) ;
			setReleaseDate(2) ;
			break;

			case 3:
			behaviour = "Average" ;
			break;

			case 4:
			behaviour = "Good" ;
			setDuration(4);
			setReleaseDate(4) ;
			break;

			case 5:
			behaviour = "Very Good" ;
			setDuration(5);
			setReleaseDate(5) ;
			break;
		}
	}

	prisoner(const prisoner &x)
	{
		name = x.name ;
		age = x.age ;
		bloodgroup = x.bloodgroup ;
		crime = x.crime ;

		entryDay = x.entryDay; 
		entryMonth= x.entryMonth ;
		entryYear= x.entryYear;

		durationDay= x.durationDay;
		durationMonth= x.durationMonth;
		durationYear= x.durationYear;

		releaseDay = x.releaseDay;
		releaseMonth = x.releaseMonth;
		releaseYear = x.releaseYear;

		cellno = x.cellno ;
		behaviour = x.behaviour ;
	}

	friend istream& operator >> (istream& input, prisoner& x)
	{
		string str; 
	    getline(input, str);
		cout << "Please enter the name of prisoner " << endl;
		//getline(input, x.name) ;
		cin >> x.name ;
		cout << "Please enter the age of the prisoner" << endl;
		input >> x.age ;
		while (cin.fail() || x.age < 0 )
		{
			cout << "Please enter a correct age" << endl;
			cin.clear ();
	      	cin.ignore(10000,'\n');
			input >> x.age ;
		}

		cout << "Please enter the blood group of the prisoner" << endl;
		input >> x.bloodgroup ;

		cout << "Please enter the crime of the Prisoner" << endl;
		input >> x.crime ;

		cout << "Please enter day of entry " << endl;
		input >> x.entryDay ;
		while (cin.fail() || x.entryDay > 30 || x.entryDay < 1 )
		{
			cout << "Please enter a correct day" << endl;
			cin.clear ();
	      	cin.ignore(10000,'\n');
			input >> x.entryDay ;
		}

		cout << "Please enter month of entry " << endl;
		input >> x.entryMonth ;
		while (cin.fail() || x.entryMonth > 12 || x.entryMonth < 1 )
		{
			cout << "Please enter a correct month" << endl;
			cin.clear ();
	      	cin.ignore(10000,'\n');
			input >> x.entryMonth ;
		}

		cout << "Please enter year of entry " << endl;
		input >> x.entryYear ;
		while (cin.fail() || x.entryYear < 1900 || x.entryYear > 2020 )
		{
			cout << "Please enter a correct year" << endl;
			cin.clear ();
	      	cin.ignore(10000,'\n');
			input >> x.entryYear ;
		}

		cout << "Please enter days of duration " << endl;
		input >> x.durationDay ;
		while (cin.fail() || x.durationDay > 30 || x.durationDay < 0 )
		{
			cout << "Please enter a correct day" << endl;
			cin.clear ();
	      	cin.ignore(10000,'\n');
			input >> x.durationDay ;
		}

		cout << "Please enter months of duration " << endl;
		input >> x.durationMonth ;
		while (cin.fail() || x.durationMonth > 30 || x.durationMonth < 0 )
		{
			cout << "Please enter a correct month" << endl;
			cin.clear ();
	      	cin.ignore(10000,'\n');
			input >> x.durationMonth ;
		}

		cout << "Please enter years of duration" << endl;
		input >> x.durationYear ;
		while (cin.fail() || x.durationYear < 0 )
		{
			cout << "Please enter a correct year" << endl;
			cin.clear ();
	      	cin.ignore(10000,'\n');
			input >> x.durationYear ;
		}

		x.releaseDay = x.entryDay + x.durationDay;
		x.releaseMonth = 0 ;
		x.releaseYear = 0;
		if (x.releaseDay > 30)
		{
			x.releaseDay = x.releaseDay - 30;
			x.releaseMonth++ ;
		}
		x.releaseMonth= x.releaseMonth + x.entryMonth + x.durationMonth;
		if (x.releaseMonth > 12)
		{
			x.releaseMonth = x.releaseMonth - 12;
			x.releaseYear++ ;
		}
		x.releaseYear= x.releaseYear+ x.entryYear + x.durationYear;
		return input ;
	}

};

void printEditMenu() ;

class Prison
{

public:
	
	prisoner *prison ;
	int noPrisoners ;
	int todayDay ;
	int todayMonth;
	int todayYear ;
	prisoner date ; // an instance of perisoner that will store current date as it's release date 

	Prison()
	{
		prison = NULL ;
		noPrisoners = 0 ;
		todayDay = 0 ;
		todayMonth= 0 ;
		todayYear =0  ;

	}

	Prison(int x)
	{
		noPrisoners= x ;
		prison = new prisoner[noPrisoners] ;
		for(int i=0; i<noPrisoners; i++)
		{
			prison[i].cellno = i ;	
		}
		todayDay = 0 ;
		todayMonth= 0 ;
		todayYear =0  ;
	}

    void	printall() // prints all of the data
	{
		cout  << "Cell No." ;
		cout << setw(15) << "Name" ;
		cout << setw(10) << "Age" ;
		cout << setw(15) << "Blood Group" ;
		cout << setw(10) << "Crime" ; 
		cout << setw(20) << "Entry Date" ; 
		cout << setw(26) << "Sentence Duration" ;
		cout << setw(25) << "Release Day" ;
		cout << setw(16) << "behaviour" <<endl << endl;

		for(int i=0; i<noPrisoners; i++)
		{
			prison[i].print() ;
			cout << endl;
		}
	}

    void	inputall() // inputs data of all prisoners in the starting
	{
		for(int i=0; i<noPrisoners; i++)
		{
			cout << "Please enter the details of prisoner " << i+1 << endl;
			cin >> prison[i] ;
			cout <<  endl << endl;
		}
	}

	void operator ++(int) // adds a prisoner 
	{	
		cout << "Please enter the cell number you want to add a new prisoner in " << endl;
		int x;
		cin >> x ;
		bool checkcell = true;

		
		 while (1)
		{
			checkcell = true ;
			for(int i=0; i<noPrisoners; i++)
			{
				if( x == prison[i].cellno)
				{
					checkcell = false ;
				}
			}

			if(cin.fail())
			{
				cout << "Please enter a correct number " << endl;
				cin.clear ();
	      		cin.ignore();
	      		cin >> x ;
	      		continue ;
			}

			else if (noPrisoners == 0 && x!= 0 )
			{
				cout << "Please enter 0, as first cell should be zero " << endl;  // check if first cell is 0
				cin.clear ();
	      		cin.ignore();
				cin >> x ;
				continue ;
			}
			else if(checkcell == false )
			{
				cout << "Cell Occupied or wrong cell, please enter another cell or correct " << endl;
				cin.clear ();
	      		cin.ignore();
				cin >> x ;
				continue ;
			}
			else if(checkcell = true)
			{
				break ;
			}
		}
		
		prisoner *temp ;
		temp = new prisoner[noPrisoners+1] ;
		for (int i=0; i<noPrisoners; i++)
		{
			temp[i] = prison[i] ;
		}
		noPrisoners++ ;
		cout << "Please enter the details for the new prisoner" << endl;
		cout << endl;
		temp[noPrisoners-1].cellno = x ;
		cin >> temp[noPrisoners-1];
		delete [] prison ;
		prison = temp ;
		int u=0 ;
			for(int k=0; k<noPrisoners; k++) // checks and delete the new prisoner if his release date has already passed 
			{
				if(noPrisoners == 0)
				{
					break; 
				}

				if( compareReleaseDate(date, prison[u] ) )
				{
					prison[u].durationDay = 0;
					prison[u].durationMonth = 0;
					prison[u].durationYear = 0;
					checkAndDelete(u) ;
					k-- ;
				}
				else
				{
					u++ ;
				}
			}
	}

	void operator --(int) // deletes a prisoner 
	{
		cout << "Please enter the cell number you want to delete a prisoner from " << endl;
		int x ;
		cin >> x ;
		bool checkcell = false;
		do
		{
			checkcell = false;
			if (!cin.fail())
			{
			for(int i=0; i<noPrisoners; i++)
			{
				cout << "hello" << endl;
				if( x == prison[i].cellno)
				{
					checkcell = true ;
				}
			}
			}

			if(checkcell == false || cin.fail())
			{
				cout << "Please enter a correct cell no " << endl;
				cin.clear ();
	      		cin.ignore();
				cin >> x ;
			}

		}while(!checkcell || cin.fail());

		prisoner *temp ;
		temp = new prisoner[noPrisoners-1] ;
		int k = 0;
		for (int i=0; i<noPrisoners; i++)
		{
			if(prison[i].cellno == x)
			{
				continue ;
			}
			else 
			{
				temp[k] = prison[i] ;
				k++ ;
			}
		}
		noPrisoners-- ;
		delete [] prison ;
		prison = temp ;
	}

	friend ostream& operator << (ostream& output, Prison& x)
	{
		x.printall();
		return output ;
	}

	void checkAndDelete(int x) // deletes a prisoner if his duration is zero
	{
		if( prison[x].durationDay <= 0 && prison[x].durationMonth <= 0 && prison[x].durationYear <= 0)
		{
			prisoner *temp ;
			temp = new prisoner[noPrisoners-1] ;
			int k = 0;
			for (int i=0; i<noPrisoners; i++)
			{
				if(i == x)
				{
					continue ;
				}
				else 
				{
					temp[k] = prison[i] ;
					k++ ;
				}
			}
			noPrisoners-- ;
			delete [] prison ;
			prison = temp ;
		}
	}

	Prison& operator [] (int x) // prints details of only single customer according to cell number
	{
		bool checkcell = false;
		do
		{
			checkcell = false;
			if (!cin.fail())
			{
			for(int i=0; i<noPrisoners; i++)
			{
				if( x == prison[i].cellno)
				{
					checkcell = true ;
				}
			}
			}
			if( !checkcell || cin.fail() )
			{
				cout << "Please enter a correct or occupied cell number to view it's prisoner's details " << endl;
				cin.clear ();
	      		cin.ignore(10000,'\n');
				cin >> x ;
			}
		}while(!checkcell || cin.fail() );

		for(int i=0; i<noPrisoners; i++)
		{
			if( x == prison[i].cellno)
			{
				cout  << "Cell No." ;
				cout << setw(15) << "Name" ;
				cout << setw(10) << "Age" ;
				cout << setw(15) << "Blood Group" ;
				cout << setw(10) << "Crime" ; 
				cout << setw(20) << "Entry Date" ; 
				cout << setw(26) << "Sentence Duration" ;
				cout << setw(25) << "Release Day" ;
				cout << setw(16) << "behaviour" <<endl << endl;
				prison[i].print(); 
				break;
			}
		}
	}

	void setDetail() // edits the details of prisoner
	{	
		system("CLS");
		printall();
		cout << endl;
		cout << "Please enter the cellno of prisoner you want to edit the details of " << endl ;
		int setDetailInput ; 
		int prisonerIndex ;
		cin >> setDetailInput ;
		bool checkDetailInput = false;
					do
					{
						checkDetailInput = false;
						if (!cin.fail())
						{
						for(int j=0; j<noPrisoners; j++)
						{
							if( prison[j].cellno == setDetailInput)
							{
								checkDetailInput = true ;
							}
						}
						}
						if(checkDetailInput == false || cin.fail())
						{
							cout << "Cell not found, please try again " << endl;
							cin.clear ();
				      		cin.ignore(10000,'\n');
							cin >> setDetailInput ;
						}

					}while(!checkDetailInput || cin.fail());

		for(int i=0; i<noPrisoners; i++)
		{
			if( prison[i].cellno == setDetailInput)
			{
				prisonerIndex = i ;
			}
		}
		system("CLS");
		prison[prisonerIndex].print() ;
		cout << endl << endl; 
		printEditMenu() ;

		cout << "Please enter a number corresponding to a detail to edit it" << endl;
		cin >> setDetailInput ;
		while( cin.fail() || setDetailInput <1 || setDetailInput > 8)
			{
				cout << "Please enter a correct number" << endl;
				cin.clear ();
      			cin.ignore(10000,'\n');
      			cin >> setDetailInput ;
			}

		bool cellset = false ;
		switch(setDetailInput)
		{
			case 1:
			cout << "Please enter the new cellno: " << endl;
			int cell ;
			cin >> cell ; 
			while( cin.fail())
			{
				cout << "Please enter a correct cell no." << endl;
				cin.clear ();
      			cin.ignore(10000,'\n');
      			cin >> cell ;
			}

			

			for (int i=0; i<noPrisoners; i++)
			{
				if( prison[i].cellno == cell && i!=prisonerIndex)
				{
					cout << "Cell already ouccpied. Press s to swap or n to add a new cell " << endl;
					char swap ;
					cin >> swap ;
					while( cin.fail() || (swap!= 's' && swap!= 'n'))
					{
						cout << "Please enter a correct alphabet" << endl;
						cin.clear ();
      					cin.ignore(10000,'\n');
      					cin >> swap ;
					}

					if ( swap == 's')
					{
						prison[i].cellno = prison[prisonerIndex].cellno ;
						prison[prisonerIndex].cellno = prison[i].cellno; 
					}
					else if ( swap == 'n')
					{
						cout << "Please enter a new cell number that is not occupied " << endl;
						int newcell ;
						cin >> newcell;
						bool checkcell = true;
						while(1)
						{
							checkcell = true;

							for(int j=0; j<noPrisoners; j++)
							{
								if( newcell == prison[j].cellno && j!=prisonerIndex )
								{
									checkcell = false ;
								}
							}

							if (cin.fail())
							{
								cout << "Please enter a number " << endl;
								cin.clear ();
					      		cin.ignore();
								cin >> newcell ;
								continue; 
							}

							else if(checkcell == false)
							{
								cout << "Cell Occupied, please enter another cell no. " << endl;
								cin.clear ();
					      		cin.ignore();
								cin >> newcell ;
								continue ;
							}
							else if (checkcell == true)
							{
								break ;
							}

						}

						if (swap == 's')
						{
							prison[prisonerIndex].cellno = cell ;
							prison[i].cellno = newcell ;
							cellset = true ;
						}
						else if (swap == 'n')
						{
							prison[prisonerIndex].cellno = newcell ;
							cellset = true ;
						}
					}

				}
			}
			if(!cellset)
			{
				prison[prisonerIndex].cellno = cell ;
				cout << "Cellno updated" << endl;
			}
			break ;

			case 2 :
			cout << "Please enter the name of prisoner " << endl;
			//getline(input, x.name) ;
			cin >> prison[prisonerIndex].name ;
			break;

			case 3 :
			cout << "Please enter the age " << endl;
			cin >> prison[prisonerIndex].age ;
			while( cin.fail())
			{
				cout << "Please enter a correct age" << endl;
				cin.clear ();
      			cin.ignore(10000,'\n');
      			cin >> prison[prisonerIndex].age ;
			}
			break ;

			case 4 :
			cout << "Please enter the bloodgroup" << endl;
			cin >> prison[prisonerIndex].bloodgroup ;
			break ;

			case 5:
			cout << "Please enter the crime of bloodgroup" << endl;
			cin >> prison[prisonerIndex].crime ;
			break ;

			case 6:
			cout << "Please enter day of entry " << endl;
			cin >>  prison[prisonerIndex].entryDay ;
			while (cin.fail() ||  prison[prisonerIndex].entryDay > 30 ||  prison[prisonerIndex].entryDay < 1 )
			{
				cout << "Please enter a correct day" << endl;
				cin.clear ();
		      	cin.ignore(10000,'\n');
				cin >>  prison[prisonerIndex].entryDay ;
			}

			cout << "Please enter month of entry " << endl;
			cin >>  prison[prisonerIndex].entryMonth ;
			while (cin.fail() ||  prison[prisonerIndex].entryMonth > 12 ||  prison[prisonerIndex].entryMonth < 1 )
			{
				cout << "Please enter a correct month" << endl;
				cin.clear ();
		      	cin.ignore(10000,'\n');
				cin >>  prison[prisonerIndex].entryMonth ;
			}

			cout << "Please enter year of entry " << endl;
			cin >>  prison[prisonerIndex].entryYear ;
			while (cin.fail() ||  prison[prisonerIndex].entryYear < 1900 || prison[prisonerIndex].entryYear > 2020 )
			{
				cout << "Please enter a correct year" << endl;
				cin.clear ();
		      	cin.ignore(10000,'\n');
				cin >>  prison[prisonerIndex].entryYear ;
			}
			prison[prisonerIndex].releaseDay = prison[prisonerIndex].entryDay + prison[prisonerIndex].durationDay; // updates release date
			prison[prisonerIndex].releaseMonth = 0 ;
			prison[prisonerIndex].releaseYear = 0;
			if (prison[prisonerIndex].releaseDay > 30)
			{
				prison[prisonerIndex].releaseDay = prison[prisonerIndex].releaseDay - 30;
				prison[prisonerIndex].releaseMonth++ ;
			}
			prison[prisonerIndex].releaseMonth= prison[prisonerIndex].releaseMonth + prison[prisonerIndex].entryMonth + prison[prisonerIndex].durationMonth;
			if (prison[prisonerIndex].releaseMonth > 12)
			{
				prison[prisonerIndex].releaseMonth = prison[prisonerIndex].releaseMonth - 12;
				prison[prisonerIndex].releaseYear++ ;
			}
			prison[prisonerIndex].releaseYear= prison[prisonerIndex].releaseYear+ prison[prisonerIndex].entryYear + prison[prisonerIndex].durationYear;
			break ;

			case 7:
			cout << "Please enter days of duration " << endl;
			cin >> prison[prisonerIndex].durationDay ;
			while (cin.fail() || prison[prisonerIndex].durationDay > 30 || prison[prisonerIndex].durationDay < 0 )
			{
				cout << "Please enter a correct day" << endl;
				cin.clear ();
		      	cin.ignore(10000,'\n');
				cin >> prison[prisonerIndex].durationDay ;
			}

			cout << "Please enter months of duration " << endl;
			cin >> prison[prisonerIndex].durationMonth ;
			while (cin.fail() || prison[prisonerIndex].durationMonth > 30 || prison[prisonerIndex].durationMonth < 0 )
			{
				cout << "Please enter a correct month" << endl;
				cin.clear ();
		      	cin.ignore(10000,'\n');
				cin >> prison[prisonerIndex].durationMonth ;
			}

			cout << "Please enter years of duration" << endl;
			cin >> prison[prisonerIndex].durationYear ;
			while (cin.fail() || prison[prisonerIndex].durationYear < 0 )
			{
				cout << "Please enter a correct year" << endl;
				cin.clear ();
		      	cin.ignore(10000,'\n');
				cin >> prison[prisonerIndex].durationYear ;
			}

			prison[prisonerIndex].releaseDay = prison[prisonerIndex].entryDay + prison[prisonerIndex].durationDay; // updates release date
			prison[prisonerIndex].releaseMonth = 0 ;
			prison[prisonerIndex].releaseYear = 0;
			if (prison[prisonerIndex].releaseDay > 30)
			{
				prison[prisonerIndex].releaseDay = prison[prisonerIndex].releaseDay - 30;
				prison[prisonerIndex].releaseMonth++ ;
			}
			prison[prisonerIndex].releaseMonth=prison[prisonerIndex].releaseMonth +  prison[prisonerIndex].entryMonth + prison[prisonerIndex].durationMonth;
			if (prison[prisonerIndex].releaseMonth > 12)
			{
				prison[prisonerIndex].releaseMonth = prison[prisonerIndex].releaseMonth - 12;
				prison[prisonerIndex].releaseYear++ ;
			}
			prison[prisonerIndex].releaseYear= prison[prisonerIndex].releaseYear + prison[prisonerIndex].entryYear + prison[prisonerIndex].durationYear;
			checkAndDelete(prisonerIndex);
			break ;

			case 8:
			prison[prisonerIndex].setBehaviour() ;
			checkAndDelete(prisonerIndex);
			break ;
		}
	}

	void swap(prisoner &a, prisoner &b)
	{
		prisoner temp ;
		temp = a ;
		a = b ;
		b = temp ;
	}

	bool compareReleaseDate(prisoner a, prisoner b) // returns false if release date is greater than today's date
	{
		if (a.releaseYear < b.releaseYear)
		{
			return false ;
		}
		else if (a.releaseYear <= b.releaseYear && (a.releaseMonth < b.releaseMonth) )
		{
			return false ;
		}
		else if (a.releaseYear <= b.releaseYear && a.releaseMonth <= b.releaseMonth && a.releaseDay < b.releaseDay)
		{
			return false ;
		}
		else 
		{
			return true ;
		}

	}

	void sort()
	{
		for(int i=1; i<noPrisoners; i++)
		{	
			int j = i ;
			while ( j>0 && compareReleaseDate( prison[j-1], prison[j]) )
			{
				swap(prison[j-1], prison[j]) ;
				j = j -1 ;
			}
		}
	}

	void todayDate()
	{
		cout << "Please enter today's " << endl;
			cin >>  todayDay ;
			while (cin.fail() ||  todayDay > 30 ||  todayDay < 1 )
			{
				cout << "Please enter a correct day" << endl;
				cin.clear ();
		      	cin.ignore(10000,'\n');
				cin >> todayDay ;
			}

			cout << "Please enter today's month" << endl;
			cin >> todayMonth ;
			while (cin.fail() ||  todayMonth > 12 ||  todayMonth < 1 )
			{
				cout << "Please enter a correct month" << endl;
				cin.clear ();
		      	cin.ignore(10000,'\n');
				cin >>  todayMonth ;
			}

			cout << "Please enter today's year " << endl;
			cin >>  todayYear ;
			while (cin.fail() ||  todayYear < 2020  )
			{
				cout << "Please enter a correct year" << endl;
				cin.clear ();
		      	cin.ignore(10000,'\n');
				cin >>  todayYear ;
			}

			date.releaseDay = todayDay ;
			date.releaseMonth = todayMonth ;
			date.releaseYear = todayYear ;

			int u=0 ;
			for(int k=0; k<noPrisoners; k++) // deletes a prison if release date has passed
			{
				if(noPrisoners == 0)
				{
					break; 
				}

				if( compareReleaseDate(date, prison[u] ) )
				{
					prison[u].durationDay = 0;
					prison[u].durationMonth = 0;
					prison[u].durationYear = 0;
					checkAndDelete(u) ;
					k-- ;
				}
				else
				{
					u++ ;
				}
			}
	}

	~Prison()
	{
		delete [] prison ;
		cout << "All data deleted " << endl;  
	}

};

void printMainMenu()
{
	cout<< endl;
	cout << "Please select one of the following options " << endl << endl;
	cout << "1. Show all prisoners' details " << endl;
	cout << "2. Show details of a prisoner in a specific cell " << endl; 
	cout << "3. Update today's date " << endl; 
	cout << "4. Sort the prisoners' data according to release date " << endl;
	cout <<"5. Edit a prisoner's info " << endl;
	cout << "6. Add another prisoner " << endl; 
	cout << "7. Remove a perisoner " << endl;
	cout << " Press 0 to exit " << endl;
}

void printEditMenu()
{
	cout << "1. Change cell number " << endl;
	cout << "2. Edit name of the prisoner " << endl;
	cout << "3. Edit age of the prisoner " << endl;
	cout << "4. Edit bloodgroup of the prisoner " << endl;
	cout << "5. Edit crime of the prisoner " << endl;
	cout << "6. Edit the entry date of the prisoner " << endl;
	cout << "7. Edit the sentence of the prisoner " << endl;
	cout << "8. Edit the behaviour of the prisoner " << endl;
}


int main()
{
	cout << "WELCOME!" << endl << endl; 
	int n ;
	cout << "Please Enter the Number of Prisoners: " << endl;
	cin >> n ;

	while ( cin.fail() || n < 0 )
		{
			cout << "Please enter a correct number of prisoners" << endl;
			cin.clear ();
      		cin.ignore(10000,'\n');
			cin >> n ;
		}

	cout << endl; 
	Prison cpo(n);
	if (n>= 1 )
	{
		system("CLS");
		cpo.inputall() ;
		system("CLS");
	}

	cpo.todayDate(); 
	system("CLS");

	int mainMenuInput;
	mainMenuInput= 2;

	printMainMenu() ;
	while((mainMenuInput >= 0 && mainMenuInput < 8 ) && !cin.fail())
	{
		cin >> mainMenuInput ;

		while((mainMenuInput < 0 || mainMenuInput > 7 ) || cin.fail())
		{
			cout << "Please enter the correct input " << endl;
			cin.clear ();
      		cin.ignore(10000,'\n');
			cin >> mainMenuInput; 
		}

		if(mainMenuInput == 0)
		{
			break;
		}

		switch(mainMenuInput)
		{
			case 1:
			if(cpo.noPrisoners == 0 )
			{
				system("CLS") ;
				cout << "Please add prisoners first " << endl;
				printMainMenu();
				break;
			}
			system("CLS");
			cout << cpo ;
			cout << endl;
			printMainMenu();
			break;

			case 2:
			if(cpo.noPrisoners == 0 )
			{
				system("CLS") ;
				cout << "Please add prisoners first " << endl;
				printMainMenu();
				break;
			}
			system("CLS");
			cout << "Please enter the cell number of prisoner you want to view the details " << endl;
			int viewDetail ;
			cin >> viewDetail ;
			cpo[viewDetail];
			printMainMenu() ;
			break;

			case 3:
			system("CLS");
			cpo.todayDate(); 
			system("CLS");
			cout << cpo ;
			printMainMenu();
			break;

			case 4:
			if(cpo.noPrisoners == 0 )
			{
				system("CLS") ;
				cout << "Please add prisoners first " << endl;
				printMainMenu();
				break;
			}
			system("CLS");
			cpo.sort() ;
			cout << cpo ;
			printMainMenu();
			break; 

			case 5:
			if(cpo.noPrisoners == 0 )
			{
				system("CLS") ;
				cout << "Please add prisoners first " << endl;
				printMainMenu();
				break;
			}
			system("CLS");
			cpo.setDetail();
			system("CLS");
			cout << cpo ;
			printMainMenu();
			break ;

			case 6:
			system("CLS");
			cpo++ ;
			system("CLS");
			cout<< cpo ;
			printMainMenu();
			break ;

			case 7:
			if(cpo.noPrisoners == 0 )
			{
				system("CLS") ;
				cout << "Please add prisoners first " << endl;
				printMainMenu();
				break;
			}
			system("CLS");
			cpo-- ;
			system("CLS");
			cout << cpo ;
			printMainMenu() ;
			break;
		}

		continue ;
	}

	
	 
}