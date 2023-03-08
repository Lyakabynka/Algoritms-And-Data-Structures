#include "WindGauge.cpp"
#include <iostream>
using namespace std;

void dump(WindGauge wg)
{
    cout << "Highest speed: " << wg.highest() << endl;
    cout << "Lowest speed: " << wg.lowest() << endl;
    cout << "Average speed: " << wg.average() << endl;
}

int main()
{
    WindGauge wg(12);
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(12);
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(15);
    dump(wg);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(17);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(20);
    wg.currentWindSpeed(17);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(20);
    dump(wg);
    return 0;
}