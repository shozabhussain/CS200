// DO NOT MODIFY THIS STRUCT
#include<iostream>
using namespace std;

struct Node
{
    string song_title;
    int id;
    Node *next;

    Node(string s, int i, Node* n){
        song_title = s;
        id = i;
        next = n;
    }
};

class playlist{
private:
    Node* head;
public:
    playlist()
    {
        head = NULL ;

    }
    Node* getHead()
    {
        return head ;
    }

    void insert_song(Node* &head, string s, int i)
    { //recursive
        Node *temp = new Node(" ", 0, NULL) ;
        temp = head ;

        if(temp -> song_title == " " && temp -> id == 0)
        {
            temp -> song_title = s ;
            temp -> id = i ;
            temp -> next = NULL ;
            head = temp ;
            return ;
        }
        else if(temp->next == NULL)
        {
            Node *temp2 = new Node(s, i, NULL) ;
            temp ->next = temp2 ;
            return;
        }
        else
        {
            temp = temp-> next ;
            insert_song(temp, s, i) ;
        }
    }
    void insert_song_after(Node* &head, string s, int i, string song2)
    { //iterative (song2 is the song after which new song should be inserted)
        Node *temp = new Node(s, i, NULL) ;
        Node *current = new Node(" ", 0, NULL) ;
        //Node *previous = new Node(" ", 0, NULL) ;
        current = head ;
        while(current -> song_title != song2 )
        {
            if(current -> next == NULL)
            {
                system("CLS") ;
                cout << "Invalid song entered! Try again " << endl;
                return ;
            }
            current = current->next ;
        }
        temp -> next = current -> next ;
        current -> next = temp ;
        system("CLS");
        cout << "song entered successfully!! " << endl << endl;
    }

    void delete_song(Node* &head, Node* prev)
    { //recursive
        Node *current = new Node(" ", 0, NULL) ;
        Node *previous = new Node(" ", 0, NULL) ;
        current = head ;
        previous = current ;
        if(playlist_size(head) == 1)
        {
            current -> song_title = " ";
            current -> id = 0 ;
            return ;
        }
        if( current -> next -> next == NULL)
        {
            delete current -> next ;
            previous -> next = NULL ;
            current = previous ;
            return ;
        }
        else
        {
            previous = current ;
            current = current -> next ;
            delete_song(current, previous) ;
        }


    }
    void display_playlist(Node* head)
    { //recursive
        Node *temp = new Node(" ", 0, NULL) ;
        temp = head ;
        if(temp -> next == NULL)
        {
            cout << temp -> song_title << "     " ;
            cout << temp -> id ;
            cout << endl;
            return ;
        }
        else
        {
            cout << temp -> song_title << "     " ;
            cout << temp -> id ;
            cout << endl;
            temp = temp -> next ;
            display_playlist(temp);
        }

    }
    int find_min(Node* head, int length)
    { //recursive
        Node *temp = new Node(" ", 0, NULL) ;
        temp = head ;
        if(temp -> next == NULL )
        {
            if(temp -> id < length)
            {
                return temp -> id;
            }
            else
            {
                return length ;
            }
        }
        else
        {
            if( length < temp -> id)
            {
                find_min(temp -> next, length) ;
            }
            else
            {
                find_min(temp -> next, temp -> id ) ;
            }
        }

    }
    int playlist_size(Node* head)
    { //recursive
        Node *temp = new Node(" ", 0, NULL) ;
        temp = head ;
        if(temp -> next == NULL)
        {
            return 1 ;
        }
        else
        {
            return 1 + playlist_size(temp -> next) ;
        }

    }
    void search_song(Node* head,string song)
    { //recursive
        Node *temp = new Node(" ", 0, NULL) ;
        temp = head ;
        if( temp -> next == NULL)
        {
            if(temp -> song_title == song)
            {
                cout << "song found"  << endl;
                cout << temp -> song_title << "     " << temp -> id << endl;
                return  ;
            }
            else
            {
                cout << "song not found" ;
                return ;
            }
        }
        else
        {
            if( temp -> song_title == song)
            {
                cout << "song found " << endl ;
                cout << temp -> song_title << "     " << temp -> id << endl;
                return ;
            }
            else
            {
                search_song(temp -> next, song) ;
            }
        }
    }
    void search_song(Node* head, int id)
    { //recursive
        Node *temp = new Node(" ", 0, NULL) ;
        temp = head ;
        if( temp -> next == NULL)
        {
            if(temp -> id == id)
            {
                cout << "song found" << endl ;
                cout << temp -> song_title << "     " << temp -> id << endl;
                return ;
            }
            else
            {
                cout << "song not found" ;
                return ;
            }
        }
        else
        {
            if( temp -> id == id)
            {
                cout << "song found " << endl;
                cout << temp -> song_title << "     " << temp -> id << endl;
                return ;
            }
            else
            {
                search_song(temp -> next, id) ;
            }
        }
    }
    void delete_playlist(Node* &head, Node* prev)
    { //recursive
    //  Node *current = new Node(" ", 0, NULL) ;
    //  Node *previous = new Node(" ", 0, NULL) ;
   //   current = head ;
   //   previous = current ;
        if(head -> next == NULL)
        {
            delete head ;
            prev->next = NULL ;
            //previous = current ;
            cout << "playlist successfully deleted" ;
            //return ;
        }
        else
        {
            delete_playlist(head->next, head) ;
            delete head ;
            //delete prev ;
            delete prev ;

        }
        return ;
    }

    print(Node* head)
    {
        Node *temp = new Node(" ", 0, NULL) ;
        temp = head ;
        cout << temp -> song_title ;
        cout << temp -> id ;
        temp = temp -> next ;
        cout << temp -> song_title ;
        cout << temp -> id ;
        temp = temp -> next ;
        cout << temp -> song_title ;
        cout << temp -> id ;
       temp = temp -> next ;
       cout << temp -> song_title ;
        cout << temp -> id ;
    }

};

int main()
{
    Node *head = new Node(" ", 0, NULL);
    playlist p ;
    int choice;

    while(1)
    {
        cout << "Welcome to your Playlist!" << endl
        << "0. Exit" << endl  //selecting this should terminate the program
        << "1. Insert a song at the end" << endl
        << "2. Insert a song after a specified song" << endl
        << "3. Delete a song from the playlist" << endl
        << "4. Display Playlist" << endl
        << "5. Find minimum id song of playlist" << endl
        << "6. Find length of Playlist" << endl
        << "7. Search for a song" << endl
        << "8. Delete Playlist" << endl
        << "Choice: ";
        cin >> choice;
        while(cin.fail() || choice < 0 || choice > 8)
        {
            cin.clear ();
            cin.ignore(10000,'\n');
            cout << "Please enter a corrent option " << endl;
            cin >> choice ;
        }

        cout << endl << endl ;
        switch(choice)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                string songName ;
                int id ;
                cout << "Enter the song's name: " ;
                cin >> songName ;
                cout << "Enter the song id: " ;
                cin >> id ;
                while(cin.fail() || id < 0 )
                {
                    cin.clear ();
                    cin.ignore(10000,'\n');
                    cout << "Enter an id greater than zero: " ;
                    cin >> id ;
                }
                p.insert_song(head, songName, id) ;
                cout << endl << endl;
                system("CLS") ;
                cout << "song entered successfully!! " << endl << endl;
                break;
            }

            case 2:
            {
                if (head -> song_title == " " && head -> id == 0)
                {
                    system("CLS") ;
                    cout << "Please insert a song first! " << endl << endl;
                    break ;
                }
                string songName ;
                int id ;
                cout << "Enter the song's name: " ;
                cin >> songName ;
                cout << "Enter the song id: " ;
                cin >> id ;
                while(cin.fail() || id < 0 )
                {
                    cin.clear ();
                    cin.ignore(10000,'\n');
                    cout << "Enter an id greater than zero: " ;
                    cin >> id ;
                }
                cout << endl << endl;
                cout << "Song Name" << "    " << "Id" << endl << endl;
                p.display_playlist(head) ;
                cout << endl << endl;
                string song2 ;
                cout << "Enter the song you want to add this new song after: " ;
                cin >> song2 ;
                p.insert_song_after(head, songName, id, song2) ;
                cout << endl << endl;
                break ;
            }

            case 3:
            {

                if (head -> song_title == " " && head -> id == 0)
                {
                    system("CLS") ;
                    cout << "Please insert a song first! " << endl << endl;
                    break ;
                }
                p.delete_song(head, head) ;
                system("CLS") ;
                cout << "song deleted successfully " << endl;
                cout << endl << endl;
                break ;
            }

            case 4:
            {
                if (head -> song_title == " " && head -> id == 0)
                {
                    system("CLS") ;
                    cout << "Please insert a song first! " << endl << endl;
                    break ;
                }
                system("CLS") ;
                cout << "Song Name" << "    " << "Id" << endl << endl;
                p.display_playlist(head) ;
                cout << endl << endl ;
                break ;
            }

            case 5:
            {
                if (head -> song_title == " " && head -> id == 0)
                {
                    system("CLS") ;
                    cout << "Please insert a song first! " << endl << endl;
                    break ;
                }
                system("CLS") ;
                cout << "Minimum id of the playlist is " << p.find_min(head, 9999) << endl << endl;
                break ;
            }

            case 6:
            {
                if (head -> song_title == " " && head -> id == 0)
                {
                    system("CLS") ;
                    cout << "Please insert a song first! " << endl << endl;
                    break ;
                }
                system("CLS") ;
                cout << "The total number of songs in the playlist are " << p.playlist_size(head) << endl << endl ;
                break ;
            }

            case 7:
            {
                if (head -> song_title == " " && head -> id == 0)
                {
                    system("CLS") ;
                    cout << "Please insert a song first! " << endl << endl;
                    break ;
                }
                system("CLS") ;
                cout << "Press 1 to search song through name " << endl;
                cout << "Press 2 to search song through id " << endl;
                int input ;
                cin >> input ;
                while(cin.fail() || (input != 1 && input != 2))
                {
                    cin.clear ();
                    cin.ignore(10000,'\n');
                    cout << "Select the right option " ;
                    cin >> input ;
                }

                if(input == 1)
                {
                    string songName ;
                    cout << "Please enter the name of the song you want to search: " ;
                    cin >> songName ;
                    system("CLS") ;
                    p.search_song(head, songName);
                    cout << endl << endl;
                    break ;
                }
                else
                {
                    int id ;
                    cout << "Please enter the id of the song you want to search: " ;
                    cin >> id ;
                    while(cin.fail())
                    {
                        cin.clear ();
                        cin.ignore(10000,'\n');
                        cout << "please enter an integer " ;
                        cin >> id;
                    }
                    system("CLS") ;
                    p.search_song(head, id) ;
                    cout << endl << endl;
                    break;
                }
            }

            case 8:
            {
                system("CLS") ;
                if(head->next == NULL)
                {
                    delete head ;
                    head = new Node(" ", 0, NULL);
                    cout << "Playlist deleted!!" ;
                }
                else
                {
                    p.delete_playlist(head->next, head) ;
                    head = new Node(" ", 0, NULL);
                }

                cout << endl << endl;


                break ;
            }

        }
    }
        //do the rest here */

     





    return 0;
}