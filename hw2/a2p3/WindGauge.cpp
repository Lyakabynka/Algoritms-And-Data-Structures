#include "WindGauge.h"
using namespace std;

WindGauge::WindGauge(int period = 12)
{
    this->period = period;
}
void WindGauge::currentWindSpeed(int speed)
{
    if (windspeeds.size() >= this->period)
    {
        windspeeds.pop_back();
    }
    windspeeds.push_front(speed);
}
int WindGauge::highest() const
{
    if (windspeeds.empty())
    {
        return -1;
    }

    int max = windspeeds[0];
    for (auto it : windspeeds)
    {
        if (it > max) max = it;
    }
    return max;
}
int WindGauge::lowest() const
{
    if (windspeeds.empty())
    {
        return -1;
    }

    int min = windspeeds[0];
    for (auto it : windspeeds)
    {
        if (it < min) min = it;
    }
    return min;
}
int WindGauge::average() const
{
    if (windspeeds.empty())
    {
        return -1;
    }

    int sum = 0;
    for (auto it : windspeeds)
    {
        sum += it;
    }
    return sum / windspeeds.size();
}

