#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList();
    ~LinkedList(); // Cleans up dynamically allocated memory

    void insertAtHead(int value);
    void insertAtEnd(int value);
    void deleteValue(int value);
    void display() const;
};

#endif#pragma once
