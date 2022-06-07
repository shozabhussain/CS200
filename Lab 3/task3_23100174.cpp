#include <iostream>
#include <time.h>
using namespace std;

struct player
{
	string name;
	int id;

	player()
	{
		name= " none" ;
		id= 0;
	}	

	player( string n, int i)
	{
		name = n ;
		id= i;
	}

	void SetName( string n)
	{
		name= n;
	}

	string GetName()
	{
		return name;
	}

	void Setid(int i)
	{
		id= i;
	}

	int Getid()
	{
		return id;
	}

	rollADie()
	{
		int random;
		random = rand() % 6 + 1;

	}

};

struct team
{
	player members[3];
	int numplayer;
	string nameteam;

	team()
	{
		numplayer= 0;
		nameteam= " 0 ";
		for (int i=0; i<3; i++)
		{
			members[i];
		}
	}

	team( int nplayer, string name)
	{
		nameteam=name;
		numplayer= nplayer;
		for (int i= 0; i<3; i++)
		{
		cout << " Enter the player's name and id " << endl;
		int idofplayer;
		string nameofplayer;
		cin >> nameofplayer >> idofplayer ;
		members[i]= player( nameofplayer, idofplayer) ;
		}
		
	}

	void printteam()
	{
		cout << "Name of Team is: " << nameteam << endl;
		cout << " Number of Players in team are: " << numplayer << endl;
		for (int i= 0; i<3; i++)
		{
		cout << members[i].player.GetName << " " << members[i].player.Getid << endl;
		}
	}

	int chooseAndPlay()
	{
		int randomplayer = rand() % 2 + 0;
		cout << members[randomplayer].GetName << " " << members[randomplayer].Getid << endl;
		return members[randomplayer].rollADie;
	}
};

int main()
{
	srand(time(0));
	team one( 3 , one );
	team two( 3 , one );
	one.printteam;
	two.printteam
	int onescore;
	int twoscore;
	int oneout;
	int twoout;

	bool check= true ;
	while (check)
	{
		cout << "Enter p to play another round or s to stop"
		char input;
		cin >> input ;
		if (input == 'p') 
		{
			oneout= one.chooseAndPlay;
			if( oneout == 6)
			{
				onescore++;
			}
			twoout= two.chooseAndPlay;
			if( twoout == 6)
			{
				twoscore++;
			}
		}
		else if (input == 's')
		{
			check=false;
			break;
		}
	}

	if( onescore > twoscore)
	{
		cout << " Team one has win the match" << endl;

	}

	else 
	{
		cout << " Team two has win the match " << endl;
	}

}