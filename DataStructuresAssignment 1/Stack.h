#pragma once
#ifndef STACK_H
#define STACK_H
#include "Node.h"

// 1. Array-Based Stack
class StackArray {
private:
    int* arr;
    int capacity;
    int topIndex;

public:
    StackArray(int size);
    ~StackArray();

    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
};

// 2. Linked List-Based Stack
class StackLinkedList {
private:
    Node* top;

public:
    StackLinkedList();
    ~StackLinkedList(); // Must free all nodes

    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;
};

#endif