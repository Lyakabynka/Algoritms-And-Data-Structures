#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>

using namespace std;


struct node{
int data;
node *left;
node *right;
node *parent;
};
void replace(node **root, node *x, node *y){
    if(x == *root)
    *root = y;
    else {
    if(y != NULL)
    y->parent = x->parent;
    if(x->parent->left == x)
    x->parent->left = y;
    else
    x->parent->right = y;
    }
}

node* find_min(node **root){
    node *min = NULL;
    node *tmp = *root;
    while(tmp != NULL)
    min = tmp,
    tmp = tmp->left;
    return min;
}
node* extract_min(node **root){
    node *min = find_min(root);
    if(min == NULL)
    return NULL;
    replace(root, min, min->right);
    min->right = NULL;
    return min;
}
node* find_max(node **root){
    node *max = NULL;
    node *tmp = *root;
    while(tmp != NULL)
    max = tmp,
    tmp = tmp->right;
    return max;
}
node* extract_max(node **root){
    node *max = find_max(root);
    if(max == NULL)
    return NULL;
    replace(root, max, max->left);
    max->left = NULL;
    return max;
}
void transform(node **root) {
    if (*root == NULL) {
        return;
    }
    
    // Extract the minimum and maximum nodes
    node* min = extract_min(root);
    node* max = extract_max(root);
    
    // Recursively transform the left and right subtrees
    transform(&(*root)->left);
    transform(&(*root)->right);
    
    // Attach the extracted minimum and maximum nodes as children
    // to the current node
    (*root)->left = NULL;
    (*root)->right = NULL;
    if (min != NULL) {
        min->left = NULL;
        min->right = NULL;
        min->parent = *root;
        (*root)->left = min;
    }
    if (max != NULL) {
        max->left = NULL;
        max->right = NULL;
        max->parent = *root;
        (*root)->right = max;
    }
}


int main() {
    

    
    return 0;
}
