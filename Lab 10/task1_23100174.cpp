#include <iostream>
using namespace std;

struct node
{
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
private:
	node *head ;
	node *tail ;

public:

	linkedList()
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
	
	void length()
	{
		node *temp = new node ;
		temp = head ;
		int count = 0 ;
		while(temp != NULL)
		{
			count ++ ;
			temp = temp->next ;
		}

		cout << "The length of list is " << count << endl;
	}

	void insertAtHead(int x)
	{
		node *temp = new node(x) ;
		temp -> next = head ;
		head = temp ;
	}

	void insertAtTail(int x)
	{
		node *temp = new node(x) ;
		temp -> next = NULL ;
		tail ->next = temp ;
		tail = temp ;
	}

	void insertAtPos(int p, int x)
	{
		node *temp = new node(x) ;
		node *current = new node ;
		node *previous = new node ;
		current = head ;
		for(int i=0; i<p; i++)
		{
			previous = current ; 
			current = current->next ;
		}
		previous->next = temp ;
		temp ->next = current ;
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

	void deleteHead()
	{
		node *temp = new node ;
		temp = head ;
		temp = temp ->next ;
		delete head ;
		head = temp ;
	}

	void deleteAtPos(int p)
	{
		node *previous = new node ;
		node *current = new node ;
		current = head ;
		for(int i= 0; i<p; i++)
		{
			previous = current ;
			current = current ->next ;
		}

		previous->next = current->next ;
		delete current ;
	}

	void print()
	{
		node *temp = new node ;
		temp = head ;
		while (temp != NULL)
		{
			if(temp->next == NULL)
			{
				cout << temp->value ;
			}
			else
			{
				cout << temp->value << " -> " ;
			}	
			
			temp = temp->next ;
		}
	}

};

int main()
{

	node *head = new node(3) ;
	node *tail = new node(4) ;
	head -> next = tail; 

	linkedList l ;
	l.setHead(head);
	l.setTail(tail);


	l.insertAtHead(2) ;
	l.insertAtHead(1) ;
	l.insertAtTail(5) ;
	cout << "List after insertion: " ;
	l.print();
	cout << endl; 
	l.length();

	cout << "List after insertion at head: " ;
	l.insertAtHead(0) ;
	l.print() ;
	cout << endl; 
	l.length();

	cout << "List after insertion at tail: " ;
	l.insertAtTail(6) ;
	l.print() ;
	cout << endl;
	l.length();

	cout << "List after insertion at 2: " ;
	l.insertAtPos(2,2) ;
	l.print();
	cout << endl;
	l.length();

	cout << "List after delete at tail: " ;
	l.deleteTail() ;
	l.print() ;
	cout << endl;
	l.length();

	cout << "List after delete at head: " ;
	l.deleteHead() ;
	l.print() ;
	cout << endl;
	l.length();

	cout << "List after deletion of node 3: " ;
	l.deleteAtPos(2);
	l.print();
	cout << endl;

	l.length();

}