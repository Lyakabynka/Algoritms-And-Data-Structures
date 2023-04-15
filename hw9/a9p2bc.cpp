// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
#include <list>
using namespace std;
 
class BST {
    int data;
    BST *left, *right;
 
public:
    // Default constructor.
    BST();
 
    // Parameterized constructor.
    BST(int);
 
    // Insert function.
    BST* Insert(BST*, int);
 
    // Inorder traversal.
    void Inorder(BST*);

    void toList(BST* root, list<int>& l);

    void toBST(BST** root, list<int>& l);
};
 
// Default Constructor definition.
BST::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}
 
// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}
 
// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
    if (!root) {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data) {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else if (value < root->data){
        // Insert left node data, if the 'value'
        // to be inserted is smaller than 'root' node data.
 
        // Process left nodes.
        root->left = Insert(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
}
 
// Inorder traversal function.
// This gives data in sorted order.
void BST::Inorder(BST* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

void BST::toList(BST* root, list<int>& l)
{
    if (!root) {
        return;
    }
    toList(root->left, l);
    
    l.push_back(root->data);

    toList(root->right, l);
}
 

void BST::toBST(BST** root, list<int>& l)
{  
    for(auto it = l.begin(); it!=l.end(); it++)
    {
        if(it == l.begin())
            *root = this->Insert(*root,*it);
        else
            this->Insert(*root,*it);
    }
}

// Driver code
int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    //b.Inorder(root);

    list<int> l;
    b.toList(root, l);
    for(auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    BST b2, *root2 = NULL;
    b2.toBST(&root2,l);
    b2.Inorder(root2);

    return 0;
}
 
// This code is contributed by pkthapa