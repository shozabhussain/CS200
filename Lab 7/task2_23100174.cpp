#include <iostream>
#include <time.h>
using namespace std;

class spaceShip
{

public:

	string totalTasks[11];

	spaceShip()
	{
		totalTasks[0] = "Sabotage";
		totalTasks[1] = "Vent";
		totalTasks[2] = "FakeTask2";
		totalTasks[3] = "Fix Wiring";
		totalTasks[4] = "Empty Trash";
		totalTasks[5] = "Download Data";
		totalTasks[6] = "Upload Data";
		totalTasks[7] = "Start Reactor";
		totalTasks[8] = "Shoot Asteroids";
		totalTasks[9] = "Redirect Power";
		totalTasks[10] = "02 Filter Clear";
	}
};

class players:public spaceShip
{

private:
	int numberOfPlayers ;
	int imposterCount ;
	string* playerRole ;
	string** playerTasks;
	int* playerTaskCounter;
	int imposterindex;


public:
	players()
	{
		numberOfPlayers= 0 ;
		 imposterCount= 0 ;
		 playerRole= NULL;
		playerTasks= NULL ;
		playerTaskCounter = NULL;
		 imposterindex=0;
	}

	players(int n)
	{
		numberOfPlayers= n;
		 imposterCount =0 ;
		playerRole = new string[numberOfPlayers];
		for(int i=0; i<numberOfPlayers; i++)
		{
			playerRole[i] = " " ;
		}
		playerTasks = new string*[numberOfPlayers] ;
		for (int i=0; i<numberOfPlayers; i++)
		{
			playerTasks[i] = new string[3] ;
		}

		 playerTaskCounter = new int[numberOfPlayers];
		for (int i=0; i<numberOfPlayers; i++)
		{
			playerTaskCounter[i] = 3 ;
		}	
		imposterindex=0;

	}

	void setPlayerRoles()
	{
		for(int i=0; i<numberOfPlayers; i++)
		{
			cout << "Enter player " << i+1 << "'s role " << endl;
			cin >> playerRole[i] ; 

			while( imposterCount == 1 && playerRole[i] == "imposter" )
			{
				cout << "Imposter Limit reached, Please make sure all other players are crewmates: " << endl;
				cout << "Enter player " << i+1 << "'s role " << endl;
				cin >> playerRole[i] ;
			}

			if (playerRole[i] == "imposter")
			{
				cout << "Imposter Limit reached, Please make sure all other players are crewmates: " << endl;
				imposterindex= i ;
				imposterCount = 1 ;
			}

			while (playerRole[i] != "imposter" && playerRole[i] != "crewmate")    
    		{
		      cout << "invalid input. Check Spelling\n" ;
		      cout << "Enter player " << i+1 << "'s role " << endl;
		      cin >> playerRole[i] ;
			}
		}
		cout << "All players have been assigned their roles " << endl;	
	}



	void setPlayerTasks()
	{

		playerTasks[imposterindex][0] = totalTasks[0];
		playerTasks[imposterindex][1] = totalTasks[1];
		playerTasks[imposterindex][2] = totalTasks[2];

		int n = 0;
		for(int i=0; i<numberOfPlayers; i++)
		{
			if (i == imposterindex)
			{
				continue;
			}
			for(int j=0; j<3; j++)
			{
				playerTasks[i][j] = totalTasks[3+n+j] ;
			}
			n = n+ 3;
		}

	cout << "All players have been assigned their tasks " << endl;	

	}

	int playGame()
	{ 
	

		while (true)
		{	
			int crewmatecount=0 ;
			for(int i=0; i<numberOfPlayers; i++)
			{
				if(i== imposterindex)
				{
					continue;
				}
				else if(playerTaskCounter[i] == 0)
				{
					crewmatecount++ ;
				}
			}

			int random = rand() % numberOfPlayers;

			if(random == imposterindex && playerTaskCounter[random] == 0)
			{
				return 2; 
			}
			else if ( crewmatecount == 2)
			{
				return 1;
			}

			for(int i=0; i<3; i++)
			{
				if(playerTasks[random][i] != "done" )
				{	
					cout << playerRole[random] << "on index " << random << " has completed their task" << endl;
					playerTasks[random][i] = "done" ;
					playerTaskCounter[random]-- ;
					break;
				}
				else if (playerTasks[random][i] == "done")
				{
					continue;
				}
			}

			





		}
	}


			

};

int main()
{
	srand(time(0));
	int n = 0;
	int returned = 0;

	cout << "Enter number of players: ";
	cin >> n;

	players obj(n);

	obj.setPlayerRoles();
	obj.setPlayerTasks();
	cout << "The game has started" << endl;
	returned = obj.playGame();

	if(returned == 2)
	{
		cout << "Imposter won the game!" << endl;
	}
	else if(returned == 1)
	{
		cout << "Crewmates win the game!" << endl;
	}

	return 0;
}