#include <iostream>
using namespace std; 

struct node
{
	int id ;
	double price ;
	node *next ;

	node()
	{
		id = 0 ;
		price = 0 ;
		next = NULL ;
	}

	node(int x, double y)
	{
		id = x ;
		price = y ;
		next = NULL ;
	}
};

class shoppingList
{
private:
	node *head ;
	node *tail ;

public:

	shoppingList()
	{
		head = NULL ;
		tail = NULL ;
	}

	void setHead(node *h)
	{
		head = h ;
	}

	void setTail(node *t)
	{
		tail = t ;
	}

	void print()
	{
		node *temp = new node ;
		temp = head ;
		while (temp != NULL)
		{
			if (temp->id == 10)
			{
				cout << "Chips ->  ID: " << temp->id << "   Price: $" << temp->price << endl;
			}
			else if (temp->id == 11)
			{
				cout << "Cheese ->  ID: " << temp->id << "   Price: $" << temp->price << endl;
			}
			else if (temp->id == 12)
			{
				cout << "Ice-cream ->  ID: " << temp->id << "   Price: $" << temp->price << endl;
			}
			else if (temp->id == 13)
			{
				cout << "Face Wash ->  ID: " << temp->id << "   Price: $" << temp->price << endl;
			}


			temp = temp->next ;
			
		}
		cout << endl;
	}

	int length()
	{
		node *temp = new node ;
		temp = head ;
		int count = 0 ;
		while(temp != NULL)
		{
			count ++ ;
			temp = temp->next ;
		}

		return count ;
	}

	void insertAtTail(int x, double p)
	{
		node *temp = new node(x, p) ;
		temp->next = NULL ;
		tail->next = temp ;
		tail = temp ;
	}

	void deleteTail()
	{
		node *temp = new node ;
		temp = head ;
		while(temp->next != tail )
		{
			temp = temp->next ;
		}
		temp->next = NULL ;
		delete tail ;
		tail = temp ;
	}

	void swap(node* a, node* b)
	{
		node* temp = new node;
		temp->id = a->id ;
		temp->price = a->price ;
		a->id = b->id;
		a->price = b->price ;
		b->id = temp ->id ; 
		b->price = temp ->price ;  
	}

	void sortShoppingList(int len)
	{
		node* previous= new node ;
		node* current = new node;

		for (int i=0; i<len*2; i++)
		{
			previous = head ;
			current = head->next ;
			while(current != NULL )
			{
				if(previous->id > current->id)
				{
					swap(previous, current) ;
				}
				previous = previous->next ;
				current = current->next ;
			}
		}
	}

	void deleteAtPos(int p)
	{
		node *previous = new node ;
		node *current = new node ;
		current = head ;
		for(int i= 0; i<p; i++)
		{
			previous = current ;
			current = current->next ;
		}

		previous->next = current->next ;
		delete current ;
	}

	void removeDuplicate()
	{
		node* temp = new node;
		temp = head ;
		int count = 1 ;
		while(temp->next != NULL)
		{
			if(temp->id == temp->next->id)
			{
				deleteAtPos(count) ;
			}
			else
			{
				count++ ;
				temp = temp->next ;
			}
		}

	}

	void checkout()
	{
		double bill = 0 ;
		//for(int i=0; i<length()+1; i++)
		while (head != tail)
		{
			//cout << tail->price ;
			bill = bill + tail->price ;
			deleteTail() ;
			print();
		}

		bill = bill + tail->price ;
		cout << "Your list is now empty " << endl;
	 	cout << "Your bill is $" << bill << endl;
	}

};

int main()
{
	node *head = new node(10, 50) ;
	node *tail = new node(11, 125.30) ;
	head->next = tail; 

	shoppingList s;
	s.setHead(head);
	s.setTail(tail);

	s.insertAtTail(10, 50.00);
	s.insertAtTail(10, 50.00);
	s.insertAtTail(13, 320.25);
	s.insertAtTail(12, 180.00);
	s.insertAtTail(10, 50.00);
	s.insertAtTail(12, 180.00);
	s.insertAtTail(10, 50.00);
	s.insertAtTail(12, 180.00);
	s.print();
	s.sortShoppingList(s.length());
	s.print();
	s.removeDuplicate();
	s.print();

	s.checkout();

}