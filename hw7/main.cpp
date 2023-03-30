#include <iostream>
#include <algorithm>
#include <chrono>
#include <time.h>
#include <random>

#define SIZE 10

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

int Lomoto_Partition(int arr[], int start, int end) {
    int pivot = arr[start]; // choose first element as pivot
    int i = start; // index of smaller element

    for (int j = start + 1; j <= end; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]); // swap arr[i] and arr[j]
        }
    }
    swap(arr[start], arr[i]); // swap arr[low] and arr[i], putting pivot in its correct position
    return i; // return partition index
}

int Hoare_Partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start - 1;
    int j = end + 1;

    while(true)
    {
        //finding index of the first value from the left side greater than pivot
        do
        {
            i++;
        } while (arr[i] < pivot);
        

        //finding index of the first value from the right side smaller than pivot
        do 
        {
            j--;
        } while (arr[j] > pivot);
        
        //if left side exceeded right side, return j
        if(i >= j)
            return j;

        //swapping them
        swap(arr[i], arr[j]);
    }
}

int medianOfThree(int arr[], int a, int b, int c) {
    if ((arr[a] > arr[b] && arr[a] < arr[c]) || (arr[a] < arr[b] && arr[a] > arr[c])) 
        return a;
    else if ((arr[b] > arr[a] && arr[b] < arr[c]) || (arr[b] < arr[a] && arr[b] > arr[c])) 
        return b;
    else
        return c;
}
int MedianOfThree_Partition(int arr[], int start, int end)
{
    int pivot = medianOfThree(arr, start, end, (start + end)/2);
    swap(arr[pivot], arr[start]);
    Lomoto_Partition(arr,start,end);
}


void Quick_Sort_Lomoto(int arr[], int start, int end)
{
    if(start < end)
    {
        int pivot = Lomoto_Partition(arr,start,end);
        Quick_Sort_Lomoto(arr,start,pivot-1);
        Quick_Sort_Lomoto(arr,pivot+1,end);
    }
}
void Quick_Sort_Hoare(int arr[], int start, int end)
{
    if(start < end)
    {
        int pivot = Hoare_Partition(arr,start,end);
        Quick_Sort_Hoare(arr,start,pivot);
        Quick_Sort_Hoare(arr,pivot+1,end);
    }
}
void Quick_Sort_MedianOfThree(int arr[], int start, int end)
{
    if(start < end)
    {
        int pivot = MedianOfThree_Partition(arr,start,end);
        Quick_Sort_Lomoto(arr,start,pivot-1);
        Quick_Sort_Lomoto(arr,pivot+1,end);
    }
}

void Evaluate(void (*func)(int arr[], int start,int end))
{
    chrono::duration<double> sum;

    chrono::time_point<chrono::system_clock> start, end;
    chrono::duration<double> elapsed_seconds;

    for (int n = 0; n < 100000; n++)
    {
        int* arr = new int[SIZE];
        generateRandomArray(arr, SIZE, 100);

        start = chrono::system_clock::now();
        func(arr,0,SIZE-1); // sort
        end = chrono::system_clock::now();

        elapsed_seconds = end - start;
        sum += elapsed_seconds;
        //cout << elapsed_seconds.count() << endl;
        delete[] arr;
    }
    cout << sum.count()/100000.;
    cout << endl;
}



void Modified_Partition(int arr[], int start, int end, int& pivot11, int& pivot22)
{
    int pivotsmaller, pivotlarger, ismall, ilarge;
    ismall = start;
    ilarge = start + 1;

    if(arr[start] > arr[start + 1])
    {
        swap(arr[start], arr[start+1]);
    }

    if(end - start + 1 == 2)
    {
        pivot11 = start;
        pivot22 = start + 1;
        return;
    }
    
    pivotsmaller = arr[start];
    pivotlarger = arr[start+1];
    
    ismall++;
    for (int j = start + 2; j <= end; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivotsmaller) {
            ismall++; // increment index of smaller element
            swap(arr[ismall], arr[j]); // swap arr[i] and arr[j]
        }
    }
    swap(arr[start+1], arr[ismall]);
    swap(arr[start], arr[ismall-1]);


    ilarge = ismall;

    for (int j = ilarge + 1; j <= end; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivotlarger) {
            ilarge++; // increment index of smaller element
            swap(arr[ilarge], arr[j]); // swap arr[i] and arr[j]
        }
    }
    swap(arr[ismall], arr[ilarge]); // swap arr[low] and arr[i], putting pivot in its correct position

    pivot11 = ismall - 1;
    pivot22 = ilarge;
}

void Quick_Sort_Modified(int arr[], int start, int end)
{
    if(start < end)
    {
        int pivot1, pivot2;
        Modified_Partition(arr, start, end, pivot1, pivot2);

        Quick_Sort_Modified(arr,start,pivot1-1);
        Quick_Sort_Modified(arr,pivot1+1, pivot2-1);
        Quick_Sort_Modified(arr,pivot2+1,end);
    }
}

void Modified_Partition_Randomized(int arr[], int start, int end, int& pivot11, int& pivot22)
{
    int p1 = rand()%10;
    int p2 = rand()%10;
    swap(arr[start],arr[p1]);
    swap(arr[start+1], arr[p2]);

    int pivotsmaller, pivotlarger, ismall, ilarge;
    ismall = start;
    ilarge = start + 1;

    if(arr[start] > arr[start + 1])
    {
        swap(arr[start], arr[start+1]);
    }

    if(end - start + 1 == 2)
    {
        pivot11 = start;
        pivot22 = start + 1;
        return;
    }
    
    pivotsmaller = arr[start];
    pivotlarger = arr[start+1];
    
    ismall++;
    for (int j = start + 2; j <= end; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivotsmaller) {
            ismall++; // increment index of smaller element
            swap(arr[ismall], arr[j]); // swap arr[i] and arr[j]
        }
    }
    swap(arr[start+1], arr[ismall]);
    swap(arr[start], arr[ismall-1]);


    ilarge = ismall;

    for (int j = ilarge + 1; j <= end; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivotlarger) {
            ilarge++; // increment index of smaller element
            swap(arr[ilarge], arr[j]); // swap arr[i] and arr[j]
        }
    }
    swap(arr[ismall], arr[ilarge]); // swap arr[low] and arr[i], putting pivot in its correct position

    pivot11 = ismall - 1;
    pivot22 = ilarge;
}

void Quick_Sort_Modified_Randomized(int arr[], int start, int end)
{
    if(start < end)
    {
        int pivot1, pivot2;
        Modified_Partition_Randomized(arr, start, end, pivot1, pivot2);

        Quick_Sort_Modified(arr,start,pivot1-1);
        Quick_Sort_Modified(arr,pivot1+1, pivot2-1);
        Quick_Sort_Modified(arr,pivot2+1,end);
    }
}

void IsSorted(int arr[], int n)
{
    for (size_t i = 1; i < n; i++)
    {
        if(arr[i-1] > arr[i])
        {
            cout << "Not sorted: ";
            printArray(arr,n);
        }
    }
    
}

int main()
{
    srand(time(0));

    //cout << "Lomoto" << endl;
    //Evaluate(Quick_Sort_Lomoto);
    //cout << "Hoare" << endl;
    //Evaluate(Quick_Sort_Hoare);
    //cout << "MedianOfThree" << endl;
    //Evaluate(Quick_Sort_MedianOfThree);

    // cout << "Modified" << endl;
    int arr[10];
    // generateRandomArray(arr,10,10);
    // printArray(arr,10);
    // Quick_Sort_Modified(arr,0,9);
    // printArray(arr,10);

    //check for my algorithm (check if the array is sorted)
    for(int i = 0; i < 100000000; i++)
    {
        generateRandomArray(arr,SIZE,10);
        Quick_Sort_Modified_Randomized(arr,0,SIZE-1);
        IsSorted(arr,SIZE);
    }

    return 0;
}