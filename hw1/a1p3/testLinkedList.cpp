#include "LinkedList.h"
using namespace std;


int main() {
    //just simple test
    linked_list<int> s;
    s.insert_tail(1);
    s.insert_head(10);
    s.insert_head(123123);
    s.print();
}