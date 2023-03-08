#include <deque>
#include <iostream>
using namespace std;
class WindGauge {
public:
    WindGauge(int period);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
private:
    deque<int> windspeeds;
    unsigned int period;
};

