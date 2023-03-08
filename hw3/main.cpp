#include <iostream>
#include <time.h>
#include <random>
#include <chrono>
using namespace std;
void generate_random(int* arr, int size)
{
    //just the random numbers
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%100;
    }
}
void generate_best(int* arr, int size)
{
    //arr[0] is the lowest
    arr[0] = rand()%100;
    for(int i = 1; i < size; i++)
    {
        //then each new element is bigger than the previous
        arr[i] = (rand() % 100) + arr[i-1];
    }
}
void generate_worst(int* arr, int size)
{
    //makes the last element the lowest
    arr[size-1] = rand() % 100;
    //makes the first element bigger than the lowest
    arr[0] = rand() % 100 + arr[size-1];
    for(int i = 1; i < size - 1; i++)
    {
        //then each new element is bigger than the previous 
        arr[i] = (rand() % 100) + arr[i-1];
    }
}
//Loop invariant: In each iteration of the algorithm a sequence [0, … i ] is in sorted order.
void selection_Sort(int* arr, int size)
{
    if(arr == nullptr || size <= 1)
    {
        return;
    }

    int tempmin;
    int min = 0;
    for(int i = 0; i < size - 1; i++)
    {
        min = i;
        for(int g = i+1; g < size; g++)
        {
            if(arr[min] > arr[g])
                min = g;
        }

        if(min != i)
        {
            tempmin = arr[min];
            arr[min] = arr[i];
            arr[i] = tempmin;
        }
    }
}
void print_arr(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
int main()
{
    //to estimate the execution time
    chrono::time_point<chrono::system_clock> start,end;
    chrono::duration<double> elapsed_seconds;
    srand(time(0));
    int size = 100;

    #pragma region //Case A
    //it is the worst, because the lowest element of [i+1..n] (inner loop) is always at the end,
    //so we need to swap every time.
    // 1 2 3 4 5 6 7 8 9 0
    // 0 2 3 4 5 6 7 8 9 1
    // 0 1 3 4 5 6 7 8 9 2 and so on.
    int* arrworst;
    for(int i = 400; i < 500; i++)
    {
        chrono::duration<double> sum;
        for(int g = 0; g < 10; g++)
        {
            arrworst = new int[i];
            generate_worst(arrworst,i);

            //measures the execution time
            start = chrono::system_clock::now();
            selection_Sort(arrworst, i);
            end = chrono::system_clock::now();
            
            elapsed_seconds = end - start;

            sum += elapsed_seconds;

            delete[] arrworst;
        }
        //cout << "WORST: Avg between size " << i << " : " << double(sum.count() / 10) << endl;
        cout << double(sum.count() / 10) << endl;
    }
    cout << "---------------------------------------------------" << endl;
    //print_arr(arr1,size);
    #pragma endregion

    #pragma region //Case B
    //CASE B
    //best case = sorted array
    int* arrbest;
    for(int i = 400; i < 500; i++)
    {
        chrono::duration<double> sum;
        for(int g = 0; g < 10; g++)
        {
            arrbest = new int[i];
            generate_best(arrbest,i);

            //measures the execution time
            start = chrono::system_clock::now();
            selection_Sort(arrbest, i);
            end = chrono::system_clock::now();
            
            elapsed_seconds = end - start;

            sum += elapsed_seconds;

            delete[] arrbest;
        }
        //cout << "BEST: Avg between size " << i << " : " << double(sum.count() / 10) << endl;
        cout << double(sum.count() / 10) << endl;
    }
    cout << "---------------------------------------------------" << endl;
    //print_arr(arr,size);
    #pragma endregion

    #pragma region //Average Case

    int* arravg;
    for(int i = 400; i < 500; i++)
    {
        chrono::duration<double> sum;
        for(int g = 0; g < 10; g++)
        {    
            arravg = new int[i];
            generate_worst(arravg,i);

            //measures the execution time
            start = chrono::system_clock::now();
            selection_Sort(arravg, i);
            end = chrono::system_clock::now();
            
            elapsed_seconds = end - start;

            sum += elapsed_seconds;

            delete[] arravg;
        }
        //cout << "BEST: Avg between size " << i << " : " << double(sum.count() / 10) << endl;
        cout << double(sum.count() / 10) << endl;
    }
    cout << "---------------------------------------------------";

    #pragma endregion
    return 0;
}