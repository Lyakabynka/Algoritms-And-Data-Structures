#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace std;
using namespace boost::multiprecision;
int128_t fibonacci_native(int n)
{
    if (n < 2)
    {
        return n;
    }

    return fibonacci_native(n - 1) + fibonacci_native(n - 2);
}
int128_t fibonacci_bottom(int n)
{
    int128_t fib1 = 0;
    int128_t fib2 = 1;
    int128_t result = 1;
    if (n < 2)
    {
        return n;
    }
    for (int i = 2; i <= n; i++)
    {
        result = fib1 + fib2;
        fib1 = fib2;
        fib2 = result;
    }

    return result;
}
cpp_dec_float_100 pow128(double a, int b)
{
    cpp_dec_float_100 mult = 1;
    for (int i = 1; i < b; i++)
    {
        mult = mult * a;
    }
    return mult;
}
int128_t fibonacci_closed(int n)
{
    double f = ((1 + std::sqrt(5)) / 2);
    return (int128_t)(pow128(f, n) / std::sqrt(5));
}   
int128_t fibonacci_closed1(int n) {
    double sqrt5 = sqrt(5.0);
    double phi = (1 + sqrt5) / 2;
    double psi = (1 - sqrt5) / 2;
    int128_t Fn = (int128_t)(((cpp_dec_float_100)pow(phi, n) - pow(psi, n)) / sqrt5);
    return Fn;
}

void multiply(int128_t F[2][2], int128_t M[2][2]) {
    int128_t a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int128_t b = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int128_t c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int128_t d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
    F[0][0] = a;
    F[0][1] = b;
    F[1][0] = c;
    F[1][1] = d;
}
void power(int128_t F[2][2], int n) {
    if (n == 0 || n == 1)
        return;
    int128_t M[2][2] = { {1,1},{1,0} };
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}
int128_t fibonacci_matrix(int n) {
    int128_t F[2][2] = { {1,1},{1,0} };
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}

int main()
{
    int128_t s;
    double maxtime = 0.5;
    chrono::duration<double> duration;
    chrono::time_point<chrono::system_clock> start, end;


    cout << "Fibonacci Native" << endl;
    for (int i = 0; i < 200; i++)
    {
        start = chrono::system_clock::now();
        //cout << fibonacci_native(i) << " ";
        fibonacci_native(i);
        end = chrono::system_clock::now();

        duration = end - start;

        cout << duration.count() << endl;

        if (duration.count() >= maxtime)
        {
            cout << endl << "Max amount of time has exceeded: " << maxtime << " and equals: " << duration.count() << " for i = " << i;
            break;
        }
    }
    cout << endl;

    

    cout << "Fibonacci Bottom" << endl;
    for (int i = 0; i < 200; i++)
    {
        start = chrono::system_clock::now();
        //cout << fibonacci_bottom(i) << " ";
        fibonacci_bottom(i);
        end = chrono::system_clock::now();

        duration = end - start;

        cout << duration.count() << endl;

        if (duration.count() >= maxtime)
        {
            cout << endl << "Max amount of time has exceeded: " << maxtime << " and equals: " << duration.count() << " for i = " << i << endl;
            break;
        }
    }
    cout << endl;


    cout << "Fibonacci Closed" << endl;
    for (int i = 0; i < 200; i++)
    {
        start = chrono::system_clock::now();
        //cout << fibonacci_closed(i) << " ";
        fibonacci_closed(i);
        end = chrono::system_clock::now();

        duration = end - start;

        cout << duration.count() << endl;

        if (duration.count() >= maxtime)
        {
            cout << endl << "Max amount of time has exceeded: " << maxtime << " and equals: " << duration.count() << " for i = " << i << endl;
            break;
        }
    }
    cout << endl;


    cout << "Fibonacci Matrix" << endl;
    for (int i = 0; i < 200; i++)
    {
        start = chrono::system_clock::now();
        //cout << fibonacci_matrix(i) << " ";
        fibonacci_matrix(i);
        end = chrono::system_clock::now();

        duration = end - start;

        cout << duration.count() << endl;

        if (duration.count() >= maxtime)
        {
            cout << endl << "Max amount of time has exceeded: " << maxtime << " and equals: " << duration.count() << " for i = " << i << endl;
            break;
        }
    }
    cout << endl;

    return 0;
}