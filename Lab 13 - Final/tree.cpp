#include <iostream>

using namespace std;

struct node{
    int value; 
    node *left;
    node *right;
    
    node (int value){
        this->value = value;
        left = NULL;
        right = NULL;
    }
};


class BinaryTree {
    node *root;
    void insertNodeHelper(node*, int value);

public:
    BinaryTree();
    void insertNode(int );
    node* getRoot();
    void printInorder(node*);
    int maxDepth(node*);
    string givePath(int input_value);
};

BinaryTree::BinaryTree(){
    this->root = NULL;
}

void BinaryTree :: insertNodeHelper(node* currentNode, int value){
    if(currentNode->value > value)
    {
        if(currentNode->left==NULL)
        {
            currentNode->left = new node(value);
        }
        else
        {
            insertNodeHelper(currentNode->left,value);
        }
    }
    else
    {
        if(currentNode->right==NULL)
        {
            currentNode->right = new node(value);
        }
        else
        {
            insertNodeHelper(currentNode->right,value);
        }
    }
    return;
}

void BinaryTree :: insertNode(int value){
    if(root == NULL)
    {
        root = new node(value);
    }
    else
    {   
        insertNodeHelper(root, value);
    }

    return;
}

node* BinaryTree :: getRoot(){
    return root;
}

void BinaryTree :: printInorder(node* currentNode){
    if (currentNode == NULL) 
        return; 
  
    printInorder(currentNode->left); 
  
    cout << currentNode->value << " "; 
  
    printInorder(currentNode->right); 
}

int BinaryTree :: maxDepth(node* rootNode){
    //Write
    //Your
    //Code
    //Here
    return 0;
}

string BinaryTree :: givePath(int input_value){
    //Write
    //Your
    //Code
    //Here
    return "";
}

int main(){

    BinaryTree Tree_1;
    Tree_1.insertNode(10);
    Tree_1.insertNode(2);
    Tree_1.insertNode(13);
    Tree_1.insertNode(21);
    Tree_1.insertNode(15);
    Tree_1.insertNode(22);
    Tree_1.insertNode(1);
    Tree_1.insertNode(6);
    Tree_1.insertNode(7);
    Tree_1.insertNode(12);
    Tree_1.insertNode(3);
    Tree_1.insertNode(25);
    Tree_1.insertNode(20);
    Tree_1.insertNode(30);
    Tree_1.insertNode(41);
    Tree_1.insertNode(36);

    int height1 = Tree_1.maxDepth(Tree_1.getRoot());
    int height2 = Tree_1.maxDepth(Tree_1.getRoot()->left);
    int height3 = Tree_1.maxDepth(Tree_1.getRoot()->right->right->right);

    if(height1 == 7 && height2 == 2 && height3 == 4){
        cout << "maxDepth() is CORRECT (20/20)" << endl;
    }
    else{
        cout << "maxDepth() is INCORRECT (0/20)" << endl;
    }
    cout << "\n";

    string path1 = Tree_1.givePath(12);
    string path2 = Tree_1.givePath(30);
    string path3 = Tree_1.givePath(3);
    string path4 = Tree_1.givePath(33);
    if(path1 == "10-> 13-> 12" && path2 == "10-> 13-> 21-> 22-> 25-> 30" && path3 == "10-> 2-> 6-> 3" && path4 == "Path DNE"){

        cout << "givePath() is CORRECT (20/20)" << endl;
    }
    else{
        cout << "givePath() is INCORRECT (0/20)" << endl;
    }
    cout << "\n";
}


