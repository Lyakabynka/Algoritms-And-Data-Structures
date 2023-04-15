#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct StackNode { // linked list
public:
    T data;
    StackNode<T>* next;
};

template<class T>
class Stack
{
protected:
    struct StackNode<T>* top; // top of stack
    int size; // -1 if not set, value otherwise
    int current_size; // unused if size = -1
public:
    void push(T elem)
    {
        if(size != -1)
        {
            //overflow
            if(current_size == size)
                return;
        }
        
        StackNode<T>* new_node = new StackNode<T>();
        new_node->data = elem;
           
        new_node->next = this->top;
        top = new_node;

        current_size++;
    } // if size set, check for overflow
    T pop()
    {
        if(isEmpty())
            return NULL;

        struct StackNode<T>* temp = top;
        top = top->next;

        T data = temp->data;
        
        delete temp;
        current_size--;

        return data;
    } // return element if not in underflow
    bool isEmpty()
    {
        return current_size == 0;
    } // true if empty, false otherwise
    Stack(int new_size)
    {
        size = new_size;
    }
    Stack() : Stack(-1)
    {
        current_size = 0;
        top = nullptr;
    }
};
