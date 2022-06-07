#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <string.h>
using namespace std;

struct customer
{
	string name;
	int seatingStatus;
	int servingStatus;
	int seatNo;
	int amountDue;
	string customerOrder ;

	customer()
	{
		name= " ";
		seatingStatus=0;
		servingStatus=0;
		seatNo=0;
		amountDue;
		customerOrder= "null" ;
	}
};

struct menuItems
{
	string name;
	float price;

	menuItems()
	{
		name= " ";
		price= 0 ;
	}

};
void printSeats(char *seats)
{
	for(int i=0; i<10; i++)
	{
		cout << i+1 << "  " ;
	}

	cout << endl;

	for(int i=0; i<10; i++)
	{
		cout << seats[i] << "  " ;
	}
}
void printMainMenu()
{
	system("CLS");
	cout << "Press 1 for customer mode " << endl;
	cout << "Press 2 for owner mode " << endl;
	cout << "Press 3 to exit program " << endl;
}

void printCustomerMode()
{	
	//system("CLS");
	cout << "Press 1 for new customer " << endl;
	cout << "Press 2 for current customer " << endl;
}


void printCustomerMenu()
{
	cout << "Press 1 to View food menu " << endl;
	cout << "Press 2 to Place order " << endl;
	cout << "Press 3 to View order " << endl;
	cout << "Press 4 to Pay bill " << endl;
	cout << "Press 5 to Leave " << endl;
	cout << "Press 6 to Return to Main menu" << endl;
}

void printOwnerMenu()
{
	cout << "Press 1 to Update food menu" << endl;
	cout << "Press 2 to View food menu" << endl;
	cout << "Press 3 to View number of customers served" << endl;
	cout << "Press 4 to View orders received" << endl;
	cout << "Press 5 to Amount earned" << endl;
	cout << "Press 6 to Offer discount" << endl;
	cout << "Press 7 to Return to Main menu" << endl;
}

void setSeat(char *seats,  customer &a)
{
	printSeats(seats);
	cout << endl ;
	cout << "Please enter the seat number you want to book " << endl;
	cin >> a.seatNo;
	while (cin.fail() || a.seatNo < 1 || a.seatNo > 10 ) 
    {
      cout << "Please select the correct option\n" ;
      cin.clear ();
      cin.ignore(10000,'\n');
      cin >> a.seatNo ;
    }
	a.seatNo--;
	if(seats[a.seatNo] == 'x')
	{
		system("CLS");
		cout << "Seat already taken please select another seat " << endl;
		setSeat(seats, a) ;
	}
	if ((a.seatNo) != 0 && (a.seatNo) != 9)
	{
		if( seats[a.seatNo-1] == 'o' && seats[a.seatNo+1] == 'o')
		{
			seats[a.seatNo] = 'x';
			a.seatingStatus= 1 ;
		}
		else if ((seats[a.seatNo-1] == 'x' || seats[a.seatNo+1] == 'x') )
		{
			system("CLS");
			cout << "Please select a different seat, the seat next to you is already occupied " << endl;
			setSeat(seats, a) ;
		}
	}
	else if (a.seatNo == 0 || a.seatNo == 9)
	{
		seats[a.seatNo] = 'x';
		a.seatingStatus= 1 ;
	}
	

}
void NewCustomer( customer *arrcustomer, int &numberOfCustomers, char *seats, int &customerIndex)
{
	system("CLS");
	cout << "Please enter your name " << endl;
	cin >> arrcustomer[numberOfCustomers].name ;
	customerIndex= numberOfCustomers;
	system("CLS");
	setSeat(seats, arrcustomer[numberOfCustomers]);
	numberOfCustomers++ ;

}
void CustomerMode(menuItems *foodMenu, int &numberOfItems, int &customersServed, int &numberOfOrdersReceived, string *orderRecieved, int &earnings, customer *arrcustomer, int &numberOfCustomers, char *seats, int &customerIndex);

void CurrentCustomer(menuItems *foodMenu, int &numberOfItems, int &customersServed, int &numberOfOrdersReceived, string *orderRecieved, int &earnings, customer *arrcustomer, int &numberOfCustomers, char *seats, int &customerIndex)
{
	system("CLS");
	cout << "Please enter your name " << endl;
	bool found = false;
	string name;
	cin >> name;
	for(int i=0; i<10; i++)
	{
		if(arrcustomer[i].name == name)
		{
			customerIndex=i;
			found = true;
			break;
		}
	}
	system ("CLS");
	if (found)
	{
		if(arrcustomer[customerIndex].seatNo == 0)
		{
		cout << "Customer is not currently at restaurant " << endl;
		CustomerMode(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);
		}
	}
	system ("CLS");
	if (!found)
	{
		cout << "Name not found, Please register yourself as a new customer " << endl;
		CustomerMode(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);
	}
	// system("CLS");
}
void printFoodMenu(menuItems *foodMenu, int numberOfItems);
void MainMenu(menuItems *foodMenu, int &numberOfItems, int &customersServed, int &numberOfOrdersReceived, string *orderRecieved, int &earnings, customer *arrcustomer, int &numberOfCustomers, char *seats, int &customerIndex);


void customerMenu(menuItems *foodMenu, int &numberOfItems, int &customersServed, int &numberOfOrdersReceived, string *orderRecieved, int &earnings, customer *arrcustomer, int &numberOfCustomers, char *seats, int &customerIndex)
{
	printCustomerMenu();
	int customerMenuResponse;
	cin >> customerMenuResponse;
	while (cin.fail() || customerMenuResponse < 1 || customerMenuResponse >6  ) 
    {
      cout << "Please select the correct option\n" ;
      cin.clear ();
      cin.ignore(10000,'\n');
      cin >> customerMenuResponse;
    }
	if (customerMenuResponse == 1)
	{
		system("CLS");
		printFoodMenu(foodMenu, numberOfItems);
		cout << endl;
		customerMenu(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

	}
	else if (customerMenuResponse == 2)
	{
		system("CLS");
		printFoodMenu(foodMenu, numberOfItems);
		cout << endl;
		cout << "Press the item number to add it to your order " << endl;
		int order;
		cin >> order;
		arrcustomer[customerIndex].amountDue = foodMenu[order-1].price ;
		arrcustomer[customerIndex].customerOrder = foodMenu[order-1].name ;
		system("CLS");
		customerMenu(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

	}
	else if (customerMenuResponse == 3)
	{
		system("CLS");
		cout << "You have ordered: " << arrcustomer[customerIndex].customerOrder << endl;
		cout << endl;
		customerMenu(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

	}
	else if (customerMenuResponse == 4)
	{
		if (arrcustomer[customerIndex].customerOrder == "null")
		{
			system("CLS");
			cout << "Please order something before paying the bill " << endl;
			cout << endl;
		}
		else
		{
			system("CLS");
			arrcustomer[customerIndex].servingStatus = 1;
			arrcustomer[customerIndex].customerOrder = "null" ;
			earnings = earnings + arrcustomer[customerIndex].amountDue ;
			customersServed++ ;
			cout << "Payment successful " << endl;
			cout << endl;
		}
		customerMenu(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

	}
	else if (customerMenuResponse == 5)
	{
		system("CLS");
		if(arrcustomer[customerIndex].customerOrder == "null")
		{
			seats[arrcustomer[customerIndex].seatNo] = 'o' ;
			cout << "Thanks for visiting us! " << endl;
			arrcustomer[customerIndex].seatNo = 0;
			arrcustomer[customerIndex].name = " " ;
		}
		else 
		{
			cout << "Please pay the bill before leaving " << endl;
		}
		cout << endl;
		customerMenu(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

	}
	else if (customerMenuResponse == 6)
	{
		system("CLS");
		MainMenu(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);
	}
}


void CustomerMode(menuItems *foodMenu, int &numberOfItems, int &customersServed, int &numberOfOrdersReceived, string *orderRecieved, int &earnings, customer *arrcustomer, int &numberOfCustomers, char *seats, int &customerIndex)
{
	printCustomerMode();
	int CustomerModeResponse;
	cin >> CustomerModeResponse;
	while (cin.fail() || CustomerModeResponse !=1 && CustomerModeResponse !=2 ) 
    {
      cout << "Please select the correct option\n" ;
      cin.clear ();
      cin.ignore(10000,'\n');
      cin >> CustomerModeResponse ;
    }
	if (CustomerModeResponse == 1)
	{
		NewCustomer(arrcustomer, numberOfCustomers, seats, customerIndex);
		system("CLS");
		customerMenu(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);
	}
	else if (CustomerModeResponse == 2)
	{
		CurrentCustomer(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);
		system("CLS");
		customerMenu(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);
	}
}



void printFoodMenu(menuItems *foodMenu, int numberOfItems)
{
	cout << setw(30) << "Menu" << endl;
	for(int i=0; i<numberOfItems; i++)
	{
		cout << i+1 << "." << setw(20) << foodMenu[i].name << setw(20) << "$" << foodMenu[i].price << endl;
	}
}

void updateFoodMenu(menuItems *foodMenu, int &numberOfItems)
{
	cout << "Press 1 to add an item " << endl;
	cout << "Press 2 to change price of an existing item " << endl;
	int ownerResponse;
	cin >> ownerResponse;
	while (cin.fail() || ownerResponse !=1 && ownerResponse !=2 ) 
    {
      cout << "Please select the correct option\n" ;
      cin.clear ();
      cin.ignore(10000,'\n');
      cin >> ownerResponse ;
    }
	if (ownerResponse == 1)
	{
		system("CLS");
		 string str; 
    	getline(cin, str); 
		cout << "Please enter the name of the dish you want to add " << endl;
		string itemname;
		getline(cin, itemname) ;
		foodMenu[numberOfItems].name = itemname;
		cout << "Please enter the price of your new dish " << endl;
		cin >> foodMenu[numberOfItems].price ;
		cout << endl;
		numberOfItems++;
		printFoodMenu(foodMenu, numberOfItems);
		cout << endl;
	}
	else if (ownerResponse == 2 )
	{
		system("CLS");
		printFoodMenu(foodMenu, numberOfItems);
		cout << endl ;
		cout << "Please enter the Item no. you want to update the price of " << endl;
		int itemNo;
		cin >> itemNo;
		cout << "Please enter the updated price " << endl;
		cin>> foodMenu[itemNo-1].price ;
		system("CLS");
		printFoodMenu(foodMenu, numberOfItems);
		cout << endl;
	}

}


void OwnerMode(menuItems *foodMenu, int &numberOfItems, int &customersServed, int &numberOfOrdersReceived, string *orderRecieved, int &earnings, customer *arrcustomer, int &numberOfCustomers, char *seats, int &customerIndex);

void MainMenu(menuItems *foodMenu, int &numberOfItems, int &customersServed, int &numberOfOrdersReceived, string *orderRecieved, int &earnings, customer *arrcustomer, int &numberOfCustomers, char *seats, int &customerIndex)
{
	printMainMenu();
	int MainMenuResponse;
	cin >> MainMenuResponse;
	while (cin.fail() || MainMenuResponse !=1 && MainMenuResponse !=2 && MainMenuResponse !=3 ) 
    {
      cout << "Please select the correct option\n" ;
      cin.clear ();
      cin.ignore(10000,'\n');
      cin >> MainMenuResponse ;
    }

	if( MainMenuResponse == 1)
	{
		system("CLS");
		CustomerMode(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);
	}
	else if ( MainMenuResponse == 2)
	{
		system("CLS") ;
		OwnerMode(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);
	}
	else if (MainMenuResponse == 3)
	{
		exit (EXIT_FAILURE) ;
	}
}

void discount(menuItems *foodMenu, int &numberOfItems)
{
	cout << "Enter the amount of discount you want to offer" << endl;
	int discount;
	cin >> discount;
	for(int i=0; i<numberOfItems; i++)
	{
		foodMenu[i].price = foodMenu[i].price*((100-discount)/100.0); 
	}
}

void OwnerMode(menuItems *foodMenu, int &numberOfItems, int &customersServed, int &numberOfOrdersReceived, string *orderRecieved, int &earnings, customer *arrcustomer, int &numberOfCustomers, char *seats, int &customerIndex)
{
	printOwnerMenu();
	int ownerResponse;
	cin>> ownerResponse;
	while (cin.fail() || ownerResponse <= 0 || ownerResponse >7  ) 
    {
      cout << "Please select the correct option\n" ;
      cin.clear ();
      cin.ignore(10000,'\n');
      cin >> ownerResponse ;
    }

	if(ownerResponse == 1)
	{
		system("CLS") ;
		updateFoodMenu(foodMenu, numberOfItems);
		OwnerMode(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

	}
	else if (ownerResponse == 2)
	{
		system ("CLS");
		printFoodMenu(foodMenu, numberOfItems);
		cout << endl;
		OwnerMode(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

	}
	else if (ownerResponse == 3)
	{
		system("CLS");
		cout << "The number of customers served: " << customersServed << endl;
		cout << endl;
		OwnerMode(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

	}
	else if (ownerResponse == 4)
	{
		system("CLS");
		bool check = true;
		for(int i=0; i<10; i++)
		{	
			if(arrcustomer[i].customerOrder != "null" )
			{
				cout << arrcustomer[i].customerOrder << endl;
				check = false;
			}
		}
		if (check)
		{
			cout << "No current orders " << endl;
		}
		cout << endl;
		OwnerMode(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

	}
	else if (ownerResponse == 5)
	{
		system("CLS");
		cout << "The amount earned is: " << earnings << endl;
		cout << endl;
		OwnerMode(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

	}
	else if (ownerResponse == 6) 
	{
		system("CLS");
		discount(foodMenu, numberOfItems );
		cout << "Discount applied successfully " << endl;
		cout << endl;
		OwnerMode(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

	}
	else if (ownerResponse == 7)
	{
		MainMenu(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);
	}
}


int main()
{	
	int customersServed=0;
	int earnings=0;
	string orderRecieved[10]= " " ; 
	int numberOfOrdersReceived=0;
	int customerIndex=0;

	char seats[10];
	for(int i=0; i<10; i++)
	{
		seats[i]= 'o' ;
	}

	customer arrcustomer[10];
	int numberOfCustomers=0;


	menuItems foodMenu[10];
	foodMenu[0].name= "Apple Pie" ;
	foodMenu[0].price= 11.00;
	foodMenu[1].name= "French Fries" ;
	foodMenu[1].price= 8.00;
	foodMenu[2].name= "Lasanga" ;
	foodMenu[2].price= 24.00;
	foodMenu[3].name= "Chop Suey" ;
	foodMenu[3].price= 15.00;
	int numberOfItems= 4;

  MainMenu(foodMenu, numberOfItems, customersServed, numberOfOrdersReceived, orderRecieved, earnings, arrcustomer, numberOfCustomers, seats, customerIndex);

}
