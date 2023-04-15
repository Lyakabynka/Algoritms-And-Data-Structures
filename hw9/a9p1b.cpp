#include <iostream>
#include "a9p1a.cpp"

using namespace std;

template<class T>
class Queue
{
private:
    Stack<T>* inbox = new Stack<T>();
    Stack<T>* outbox = new Stack<T>();

public:
    void queue(T item) {
        inbox->push(item);
    }

    T dequeue() {
        T val;
        if (outbox->isEmpty()) {
            while (!inbox->isEmpty()) 
            {
                outbox->push(inbox->pop());
            }
        }
        
        return outbox->pop();
    }

};


int main()
{
    Queue<int> s;
    s.queue(1);
    s.queue(2);
    s.queue(3);

    cout << s.dequeue() << " ";
    cout << s.dequeue() << " ";
    cout << s.dequeue() << " ";
    cout << s.dequeue() << " ";
    
    return 0;
}