#ifndef __LIST_H // These two lines and the last line ensure
#define __LIST_H // So that this file can be imported in other files.

#include <cstdlib> // For memory management.
#include <iostream>
// This struct just holds a single data item, i.e., a node.
template <class T>
struct list_item {
    T value;
    list_item<T> *next;
    list_item<T> *prev; 

    // Constructor.
    list_item(T the_value) {
        this->value = the_value;
        this->next = NULL;
        this->prev = NULL;

        s();
        this->s();
    }
    void s()
    {

    }
};

// The generic Linked List class.
template <class T>
class linked_list {
private:
    list_item<T> *head;
    list_item<T> *tail;

public:

    // Constructor.
    linked_list();

    // Destructor.
    ~linked_list();

    // Insertion functions.
    void insert_head(T item);
    void insert_tail(T item);

    // Lookup functions.
    list_item<T> *get_head();
    list_item<T> *get_tail();

    int length();
    
    // Deletion functions.
    void delete_head();
    void delete_tail();

    // Utility functions.
    void print();
};

#endif

