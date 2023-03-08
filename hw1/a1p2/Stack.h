#include <iostream>
#include <string>

using namespace std;

#define SIZE 10

template <class T>
class Stack
{
public:
    Stack();
    Stack(const Stack<T>&);
    ~Stack();

    bool push(T k);

    bool pop(T&);

    T back();

    bool isFull();

    bool isEmpty();

    int getNumEntries();
private:
    int top;

    T st[SIZE];
};

// initialize top to
// -1(default constructor)
template <class T>
Stack<T>::Stack()
{
    top = -1;
}

template <class T>
Stack<T>::~Stack() {}

template <class T>
Stack<T>::Stack(const Stack<T>& stack)
{
    this->top = stack.top;
    for (int i = 0; i <= this->top; i++)
    {
        this->st[i] = stack.st[i];
    }
}

template <class T>
bool Stack<T>::push(T k)
{
    // if stack is full
    if (isFull())
    {
        return false;
    }

    top = top + 1;

    st[top] = k;

    return true;
}

// checks if the stack is empty
template <class T>
bool Stack<T>::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

template <class T>
bool Stack<T>::isFull()
{
    // checks if top is less then size-1 ( if array is full )
    if (top == (SIZE - 1))
        return 1;
    else
        return 0;
}

//pops the last elem
template <class T>
bool Stack<T>::pop(T& out)
{
    // check for emptiness
    if (isEmpty())
    {
        return false;
    }

    out = st[top];

    top--;

    return true;
}

template <class T>
T Stack<T>::back()
{
    if (isEmpty())
        return 0;
    return st[top];
}

template <class T>
int Stack<T>::getNumEntries()
{
    return top;
}
