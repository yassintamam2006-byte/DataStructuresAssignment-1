#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

// 1. Circular Array-Based Queue
class QueueArray {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count; // Tracks the number of elements to easily determine full/empty states

public:
    QueueArray(int size);
    ~QueueArray();

    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    bool isFull() const;
};

// 2. Linked List-Based Queue
class QueueLinkedList {
private:
    Node* front;
    Node* rear;

public:
    QueueLinkedList();
    ~QueueLinkedList();

    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    bool isFull() const; // Included per requirements, though LLs only get "full" if memory runs out
};

#endif#pragma once
