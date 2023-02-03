/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

using std::runtime_error;

// This file defines the methods for two classes: LinkedListNode and LinkedList.
// The LinkedListNode methods have been defined for you.  You are responsible
// for defining the LinkedList methods.

// //////// LinkedListNode /////////////////////////////////////////////////////

template <typename T>
LinkedListNode<T>::LinkedListNode(T val, LinkedListNode<T>* next) {
    this->value = val;
    this->next = next;
}

// //////// LinkedList /////////////////////////////////////////////////////////

template <typename T> LinkedList<T>::LinkedList() {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T> LinkedList<T>::~LinkedList() {
    if (size > 0) {
        LinkedListNode<T>* current = this->head;
        LinkedListNode<T>* next = this->head->next;
        while (current->next != nullptr) {
            delete current;
            current = next;
            next = current->next;
        }
        delete current;
    }
}

template <typename T> void LinkedList<T>::checkInvariants() {
    if (this->size == 0) {
        if (this->head != nullptr || this->tail != nullptr) {
            throw runtime_error("checkInvariants: Size = 0, but either head"
                " or tail does not equal nullptr.");
        }
    }
    LinkedListNode<T>* current = this->head;
    int count = 0;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    if (count != this->size) {
        throw runtime_error("checkInvariants: Number of items in list does"
            " not equal size!!");
    }
}

template <typename T> int LinkedList<T>::getSize() {
    return this->size;
}

template <typename T> bool LinkedList<T>::isEmpty() {
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T> T LinkedList<T>::getFirst() {
    if (this->head != nullptr) {
        return this->head->value;
    }
    else {
        throw runtime_error("Can't getFirst()... list is empty.");
    }
}

template <typename T> T LinkedList<T>::getLast() {
    if (this->tail != nullptr) {
        return this->tail->value;
    }
    else {
        throw runtime_error("Can't getLast()... list is empty.");
    }
}

template <typename T> T LinkedList<T>::get(int index) {
    if (index < 0) {
        throw runtime_error("Can't get(), the index given is out of range.");
    }
    else if (index > this->size-1) {
        throw runtime_error("Can't get(), the index given is out of range.");
    }
    
    LinkedListNode<T>* current = this->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

template <typename T> void LinkedList<T>::insertFirst(T value) {
    LinkedListNode<T>* first = new LinkedListNode<T>(value, this->head);
    this->head = first;
    if (this->size == 0) {
        this->tail = first;
    }
    this->size++;
}

template <typename T> void LinkedList<T>::insertLast(T value) {
    LinkedListNode<T>* last = new LinkedListNode<T>(value, nullptr);
    if (this->size == 0) {
        this->head = last;
        this->tail = last;
    }

    else {
        this->tail->next = last;
        this->tail = last;
    }
    this->size++;
}

template <typename T> T LinkedList<T>::removeFirst() {
    if (this->size == 0) {
        throw runtime_error("Can't removeFirst()... list is empty.");
    }
    T val = this->head->value;
    if (this->size == 1) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else{
        LinkedListNode<T>* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    this->size--;
    return val;
}

template <typename T> T LinkedList<T>::removeLast() {
    if (this->size == 0) {
        throw runtime_error("Can't removeLast()... list is empty.");
    }
    T val = this->tail->value;
    if (this->size == 1) {
        delete this->tail;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else{
        LinkedListNode<T>* current = this->head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        current->next = nullptr;
        delete this->tail;
        this->tail = current;
    }
    this->size--;
    return val;
}
