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
        //your implementation here

    }
    Node* getHead()
    {
        //your implementation here
    }

    void insert_song(Node* &head, string s, int i)
    { //recursive
    // your implementation here
    }
    void insert_song_after(Node* &head, string s, int i, string song2)
    { //iterative (song2 is the song after which new song should be inserted)
    // your implementation here
    }

    void delete_song(Node* &head, Node* prev)
    { //recursive
    // your implementation here

    }
    void display_playlist(Node* head)
    { //recursive
    // your implementation here

    }
    int find_min(Node* head, int length)
    { //recursive
    // your implementation here

    }
    int playlist_size(Node* head)
    { //recursive
    // your implementation here
 
    }
    void search_song(Node* head,string song)
    { //recursive
    // your implementation here
    }
    void search_song(Node* head, int id)
    { //recursive
    // your implementation here
    }
    void delete_playlist(Node* &head, Node* prev)
    { //recursive
    // your implementation here
    }


};

int main()
{
    //create your object and any other variables here
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
    }
        //do the rest here
        

    return 0;
}