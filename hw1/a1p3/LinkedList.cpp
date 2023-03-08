#ifndef __LIST_CPP
#define __LIST_CPP

#include "LinkedList.h"
using namespace std; // Makes writing code easier for this example.

// Constructor; set both head and tail to NULL.
template <class T>
linked_list<T>::linked_list() {
	head = NULL;
	tail = NULL;
}

// Destructor; memory management. VERY IMPORTANT.
template <class T>
linked_list<T>::~linked_list() {
    for(int i = 0; i < length(); i++) {
        delete_head();
    }
}

// Insert elements to the head (left) of the list.
template <class T>
void linked_list<T>::insert_head(T item) {
	if(head == NULL) {
        head = new list_item<T>(item);
        tail = head;
        return;
    }
    list_item<T> *Node = new list_item<T>(item);
    head->prev = Node;
    Node->next = head;
    head = Node;
}

// Insert elements to the tail (right) of the list.
template <class T>
void linked_list<T>::insert_tail(T item) {
	if(tail == NULL) {
        tail = new list_item<T>(item);
        head = tail;
        return;
    }
    list_item<T> *Node = new list_item<T>(item);
    tail->next = Node;
    Node->prev = tail;
    tail = Node;
}

// Used for checking purposes.
template <class T>
list_item<T>* linked_list<T>::get_head() {
	return head;
}

// Used for checking purposes.
template <class T>
list_item<T>* linked_list<T>::get_tail() {
	return tail;
}

// Used for the destructor.
template <class T>
void linked_list<T>::delete_head() {
	if(head == NULL) {
        return;
    }
    else if(head->next == NULL) {
    	delete head;
        head = NULL;
        tail = NULL;
    }
    else {
        list_item<T> *current = head->next;
        delete head;
        head = current;
        head->prev = NULL;
    }
}

// Good to have.
template <class T>
void linked_list<T>::delete_tail() {
	if(head == NULL) {
        return;
    }
    else if(head->next == NULL) {
    	delete head;
        head = NULL;
        tail = NULL;
    }
    else {
        list_item<T> *current = tail->prev;
        delete tail;
        tail = current;
        tail->next = NULL;
    }
}

// For the destructor.
template <class T>
int linked_list<T>::length() {
	int count = 0;
    if(head == NULL) {
        return count;
    }
    else {
        list_item<T> *current = head;
        while(current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }
}

// For demonstration purposes.
template <class T>
void linked_list<T>::print() {
    if(head == NULL) {
        cout << "empty list";
    } else {
        list_item<T> *current = head;
        while(current != NULL) {
            if(current->next != NULL) {
                cout << current->value << " <=> ";
            } else {
                cout << current->value;
            }
            current = current->next;
        }
    }
}

#endif