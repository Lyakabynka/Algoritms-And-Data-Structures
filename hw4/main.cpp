#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
#include <chrono>
using namespace std;

void mergeMy(int array[], int const left, int const mid,
    int const right);
void insertion_sort(int arr[], const int begin, const int end);
void print_arr(int arr[], int size);
void merge_sort(int* arr, const int& k, const int begin, const int end);

void generate_random(int* arr, int size);

void join(int arr[], int left[], int right[],
            int lsize, int rsize);
//generates Worst case from SORTED ARRAY!!!
void generate_Worst(int arr[], int arrsize);

void generate_best(int* arr, int size);

int main()
{
    srand(time(0));

    int n = 500;
    chrono::time_point<chrono::system_clock> start,end;
    chrono::duration<double> duration;

/*     #pragma region // Worst cases
    for(int k = 0; k < 300; k++)
    {
            int* arr = new int[n];

            generateSorted(arr,n);
            generate_Worst(arr,n);
            
            start = chrono::system_clock::now();
            merge_sort(arr, k, 0, n-1);
            end = chrono::system_clock::now();
            
            duration = end - start;
            cout << duration.count() << endl;

            delete[] arr;
    }
    #pragma endregion */

    #pragma region // Avg Cases
    chrono::duration<double> sum;
    for(int k = 0; k < 300; k++)
    {
        sum = chrono::duration<double>::zero();
        for (int i = 0; i < 10; i++)
        {
            int* arr = new int[n];
 
            generate_random(arr,n);
            
            start = chrono::system_clock::now();
            merge_sort(arr, k, 0, n-1);
            end = chrono::system_clock::now();
            
            duration = end - start;
            
            sum = sum + duration;

            delete[] arr;
        }
        cout << sum.count()/10. << endl;
    }
    #pragma endregion

    /* #pragma region // Best cases
    for(int k = 0; k < 300; k++)
    {
            int* arr = new int[n];

            generate_best(arr,n);
            
            start = chrono::system_clock::now();
            merge_sort(arr, k, 0, n-1);
            end = chrono::system_clock::now();
            
            duration = end - start;
            cout << duration.count() << endl;

            delete[] arr;
    }
    #pragma endregion
    return 0; */
}

void merge_sort(int* arr, const int& k, const int begin, const int end)
{
    if (begin >= end)
        return;

    if(end-begin+1 <= k)
    {
        insertion_sort(arr,begin,end);
        return;
    }

    auto mid = begin + (end - begin) / 2;
    merge_sort(arr, k, begin, mid);
    merge_sort(arr, k, mid + 1, end);
    mergeMy(arr, begin, mid, end);
}

void mergeMy(int array[], int const left, int const mid,
           int const right)
{
    if(array[mid] < array[mid+1])
    {
        return;
    }

    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void insertion_sort(int arr[], const int begin, const int end)
{
    int temp;
    int j;
    int i;
    for (i = begin + 1; i < end; i++)
    {
        j = i - 1;
        temp = arr[i];
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

#pragma region // Sorted Generation

void generateSorted(int arr[], int size)
{
    arr[0] = rand() % 100;
    for(int i = 1; i < size; i++)
    {
        arr[i] = arr[i-1] + rand() % 100;
    }
}

#pragma endregion

#pragma region // Random Generation

void generate_random(int* arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand()%100;
    }
}

#pragma endregion

#pragma region // Worst Generation

void join(int arr[], int left[], int right[],
            int lsize, int rsize) {
        int i,j;
        for(i=0;i<lsize;i++)
                arr[i]=left[i];
        for(j=0;j<rsize;j++,i++)
                arr[i]=right[j];
}
    //Pass a sorted array here
void generate_Worst(int arr[], int arrsize) { 
            if(arrsize<=1)

                return;

            if(arrsize==2)
            {
                int swap=arr[0];
                arr[0]=arr[1];
                arr[1]=swap;

                return;
            }

        int i,j;
        int m = (arrsize + 1) / 2;
        int* left = new int[m];
        int* right = new int[arrsize-m];

        //adds to LEFT array all even elements
        for(i=0,j=0;i<arrsize;i=i+2,j++) //Storing alternate elements in left subarray
            left[j]=arr[i];

        //adds to RIGHT array all odd elements
        for(i=1,j=0;i<arrsize;i=i+2,j++) //Storing alternate elements in right subarray
            right[j]=arr[i];

        generate_Worst(left, m);
        generate_Worst(right, arrsize-m);
        join(arr, left, right,
                    m, arrsize-m);
        
        delete[] left;
        delete[] right;
}

#pragma endregion