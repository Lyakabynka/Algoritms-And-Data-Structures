#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
void printArray(T arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
template<typename T>
void printArray(vector<T> arr)
{
     for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
void counting_sort(int A[], int n, int k){
    int* C = new int [k];
    int* B = new int [n];
    for (int i = 0; i < k; i++){
        C[i] = 0;
    }
    for (int j = 0; j < n; j++){
        C[A[j]-1]= C[A[j]-1] + 1;
        // C[i] = |{ key = i}|
    }
    for (int i = 1; i < k; i++){
        C[i] = C[i] + C[i-1];
        // C[i] = |{ key <= i }|
    }
    for (int j = n-1; j >= 0; j--){
        B[C[A[j]-1]-1] = A[j];
        C[A[j]-1] = C[A[j]-1] - 1;
    }
    for(int i = 0; i < n; i++){
        A[i] = B[i];
    }
    delete[] C;
    delete[] B;
}

int count_occurences(int A[], int n, int k, int startval, int endval)
{
    int* C = new int [k];
    int* B = new int [n];

    for (int i = 0; i < k; i++){
        C[i] = 0;
    }
    for (int j = 0; j < n; j++){
        C[A[j]-1]= C[A[j]-1] + 1;
        // C[i] = |{ key = i}|
    }
    for (int i = 1; i < k; i++){
        C[i] = C[i] + C[i-1];
        // C[i] = |{ key <= i }|
    }
    for (int j = n-1; j >= 0; j--){
        B[C[A[j]-1]-1] = A[j];
        C[A[j]-1] = C[A[j]-1] - 1;
    }

    int count;
    if(startval == 0)
    {
        count = C[endval];
    }
    else
    {
        count = C[endval] - C[startval-1];
    }
    

    delete[] C;
    delete[] B;

    return count;
}


void bucket_sort(float arr[], int n){
    vector<float>* B = new vector<float>[n];

    for (int i = 0; i < n; i++){
        int bi = n * arr[i];
        B[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++){
        sort(B[i].begin(), B[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < B[i].size(); j++)
            arr[index++] = B[i][j];

    delete[] B;
}

vector<string> radix_sort(vector<string>& words) {
    // Get the maximum word length

    int max_length = 0;
    for (auto& w : words) {
        if (w.length() > max_length) {
            max_length = w.length();
        }
    }

    // Pad the words with spaces so that all words have the same length
    for (auto& w : words) {
        w.resize(max_length, ' ');
    }

    // Sort the words by their characters from right to left
    for (int i = max_length - 1; i >= 0; i--) {
        stable_sort(words.begin(), words.end(), [i](const string& a, const string& b) {
            return a[i] < b[i];
        });
    }

    // Remove the padding and return the sorted words
    for (auto& w : words) {
        w.erase(w.find_last_not_of(' ') + 1);
    }



    return words;
}

// Linked list node structure
struct node {
    vector<int> arr;
    struct node* nxt[10];
};
 
// Function to create a new node of
// the Linked List
struct node* new_node(void)
{
    struct node* tempNode = new node;
 
    for (int i = 0; i < 10; i++) {
        tempNode->nxt[i] = NULL;
    }
 
    // Return the created node
    return tempNode;
}
 
// Function to sort the given array
// using MSD Radix Sort recursively
void msd_sort(struct node* root, int exp,
              vector<int>& sorted_arr)
{
    if (exp <= 0) {
        return;
    }
 
    int j;
 
    // Stores the numbers in different
    // buckets according their MSD
    for (int i = 0;
         i < root->arr.size();
         i++) {
 
        // Get the MSD in j
        j = (root->arr[i] / exp) % 10;
 
        // If j-th index in the node
        // array is empty create and
        // link a new node in index
        if (root->nxt[j] == NULL) {
            root->nxt[j] = new_node();
        }
 
        // Store the number in j-th node
        root->nxt[j]->arr.push_back(
            root->arr[i]);
    }
 
    // Sort again every child node that
    // has more than one number
    for (int i = 0; i < 10; i++) {
 
        // If root->next is NULL
        if (root->nxt[i] != NULL) {
 
            if (root->nxt[i]->arr.size()
                > 1) {
 
                // Sort recursively
                msd_sort(root->nxt[i],
                         exp / 10,
                         sorted_arr);
            }
 
            // If any node have only
            // one number then it means
            // the number is sorted
            else {
                sorted_arr.push_back(
                    root->nxt[i]->arr[0]);
            }
        }
    }
}
 
// Function to calculate the MSD of the
// maximum  value in the array
int get_max_exp(vector<int> arr)
{
    // Stores the maximum element
    int mx = arr[0];
 
    // Traverse the given array
    for (int i = 1; i < arr.size(); i++) {
 
        // Update the value of maximum
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
 
    int exp = 1;
 
    while (mx > 10) {
        mx /= 10;
        exp *= 10;
    }
 
    // Return the resultant value
    return exp;
}

int main()
{
    int arr1[7] = {9, 1, 6, 7, 6, 2, 1};
    counting_sort(arr1, 7, 9);
    printArray(arr1, 7);

    float arr2[7] = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
    bucket_sort(arr2, 7);
    printArray(arr2, 7);

    cout << count_occurences(arr1,7,9,1,7) << endl; 

    vector<string> arr = {"word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"};
    arr = radix_sort(arr);
    printArray((arr));

    struct node* root = new_node();
 
    // Stores the unsorted array
    // in the root node
    root->arr.insert(root->arr.end(),
                     { 9330, 9950, 718,
                       8977, 6790, 95,
                       9807, 741, 8586,
                       5710 });
    cout << endl;
    
    cout << "Unsorted array : ";
 
    // Print the unsorted array
    printArray(root->arr);

    int exp = get_max_exp(root->arr);
 
    // Stores the sorted numbers
    vector<int> sorted_arr;
 
    // Function Call
    msd_sort(root, exp, sorted_arr);
 
    cout << "Sorted array : ";
 
    // Print the sorted array
    printArray(sorted_arr);

    return 0;
}