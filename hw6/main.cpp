#include <iostream>
#include <algorithm>

using namespace std;

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

        // if no elements were swapped, thus array is sorted and no need to continue
        if(swapped == false) break;
    }
        // basically in each iteration of 'i' it places the largest element of 0..n-i-1
        // to the n-i-1 and decrements 'i'
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
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int leafSearch(int a[], int i, int end)
{
    int j = i;
    int LeftChild = j*2;
    int RightChild = j*2 + 1;
    while(RightChild <= end)
    {
        if(a[RightChild] > a[LeftChild])
            j = RightChild;
        else
            j = LeftChild;
    }
    if(LeftChild <= end)
        j = LeftChild;
    return j;
}

void siftDown(int a[], int i, int end)
{
    int j = leafSearch(a,i,end);
    while(a[i] > a[j])
        j = j/2;
    int x = a[j];
    a[j] = a[i];
    while(j>i)
    {
        swap(x,a[j/2]);
        j = j/2;
    }
}

int main()
{
    int arr[10] = {5,1,7,1,3,7,2,47,78,1};

    siftDown(arr,0,10);

    return 0;
}