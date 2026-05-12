#include "Queue.h"
#include <iostream>

// ================= QueueArray (Circular) Implementation =================
QueueArray::QueueArray(int size) : capacity(size), front(0), rear(0), count(0) {
    arr = new int[capacity];
}

QueueArray::~QueueArray() {
    delete[] arr;
}

bool QueueArray::isEmpty() const {
    return count == 0;
}

bool QueueArray::isFull() const {
    return count == capacity;
}

void QueueArray::enqueue(int value) {
    if (isFull()) {
        std::cerr << "Queue is Full! Cannot enqueue " << value << "\n";
        return;
    }
    arr[rear] = value;
    // Circular logic: wrap around to index 0 if we hit the end of the array
    rear = (rear + 1) % capacity;
    count++;
}

int QueueArray::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is Empty! Cannot dequeue.\n";
        return -1;
    }
    int dequeuedValue = arr[front];
    // Circular logic: wrap around to index 0 if we hit the end of the array
    front = (front + 1) % capacity;
    count--;
    return dequeuedValue;
}


// ================= QueueLinkedList Implementation =================
QueueLinkedList::QueueLinkedList() : front(nullptr), rear(nullptr) {}

QueueLinkedList::~QueueLinkedList() {
    while (!isEmpty()) {
        dequeue();
    }
}

bool QueueLinkedList::isEmpty() const {
    return front == nullptr;
}

bool QueueLinkedList::isFull() const {
    // A linked list queue is technically never full unless memory is exhausted
    return false;
}

void QueueLinkedList::enqueue(int value) {
    Node* newNode = new Node(value);
    if (rear == nullptr) { // If the queue is empty we can use  if (isEmpty())
        front = rear = newNode;
        return;
    }
    // Add the new node to the end and update the rear pointer (O(1) operation)
    rear->next = newNode;
    rear = newNode;
}

int QueueLinkedList::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is Empty! Cannot dequeue.\n";
        return -1;
    }
    Node* temp = front;
    int dequeuedValue = temp->data;
    front = front->next; // Move front to the next node (O(1) operation)

    // If front becomes null, rear must also become null
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    return dequeuedValue;
}