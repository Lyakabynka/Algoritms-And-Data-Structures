#include <iostream>
#include <algorithm>
#include <time.h>
#include <chrono>
#include <random>

using namespace std;

void generateRandomArray(int arr[], int n, int max)
{
    for(int i = 0; i<n; i++)
    {
        arr[i] = rand()%max;
    }
}
void printArray(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    bool swapped = false;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // we iterate through 0..n-i-1 and
        for (j = 0; j < n - i - 1; j++)
        {
            // if ( current element < next element ) then swap them
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);

                // indicates that the swap happened       
                swapped = true;
            }
        }

        // if no elements were swapped, the array is sorted and no need to continue
        if(swapped == false) break;
    }
        // basically in each iteration of 'i' it places the largest element of 0..n-i-1
        // to the n-i-1 and decrements size in the inner loop ( j < n - i - 1 )
}
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
void buildmaxheap(int arr[], int n)
{
    for (int i = (n-1) / 2; i >= 0; i--)
        heapify(arr, n, i);
}
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    buildmaxheap(arr,n);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int LeftChild(int i)
{
    return i*2 + 1;
}
int RightChild(int i)
{
    return i*2+2;
}
int Parent(int i)
{
    return i/2;
}

//finds the first element larger than the root
int leafSearch(int a[], int i, int end)
{
    int j = i;
    while(RightChild(j) <= end){
        if (a[RightChild(j)] > a[LeftChild(j)]){
            j = RightChild(j);
        }
        else{
            j = LeftChild(j);
        }
    }
    if (LeftChild(j) <= end){
        j = LeftChild(j);
    }
    return j;
}
void shiftDown(int a[], int i, int end)
{
    int j = leafSearch(a, i, end);
    while(a[i] > a[j]){
        j = Parent(j);
    }
    int x = a[j];
    a[j] = a[i];
    while (j > i){
        swap(x, a[Parent(j)]);
        j = Parent(j);
    }
}
void heapSort_BottomUp(int arr[], int N)
{
    for (int i = N/2 - 1; i >= 0; i--){
        heapify(arr, N, i);
    }
    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        shiftDown(arr, 0, i-1);
    }
}

int main()
{
    chrono::time_point<chrono::system_clock> start, end;
    chrono::duration<double> elapsed_seconds;

    srand(time(0));

    // for (int n = 0; n < 500; n++)
    // {
    //     int* arr = new int[n];
    //     generateRandomArray(arr, n, 10);

    //     start = chrono::system_clock::now();
    //     heapSort_BottomUp(arr, n);
    //     end = chrono::system_clock::now();

    //     elapsed_seconds = end - start;
    //     cout << elapsed_seconds.count() << endl;
    //     delete[] arr;
    // }
    // cout << endl << endl;
    for (int n = 10; n < 20; n++)
    {
        int* arr = new int[n];
        generateRandomArray(arr, n, 10);

        printArray(arr,n);
        start = chrono::system_clock::now();
        heapSort(arr, n);
        end = chrono::system_clock::now();

        printArray(arr,n);
        elapsed_seconds = end - start;
        cout << elapsed_seconds.count() << endl;
        delete[] arr;
    }

    return 0;
}