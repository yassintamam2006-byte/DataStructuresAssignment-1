#include "Stack.h"
#include <iostream>

// ================= StackArray Implementation =================
StackArray::StackArray(int size) : capacity(size), topIndex(-1) {
    arr = new int[capacity];
}

StackArray::~StackArray() {
    delete[] arr;
}

bool StackArray::isFull() const {
    return topIndex == capacity - 1;
}

bool StackArray::isEmpty() const {
    return topIndex == -1;
}

void StackArray::push(int value) {
    if (isFull()) {
        std::cerr << "Stack Overflow! Cannot push " << value << "\n";
        return;
    }
    arr[++topIndex] = value;
}

int StackArray::pop() {
    if (isEmpty()) {
        std::cerr << "Stack Underflow! Stack is empty.\n";
        return -1;
    }
    return arr[topIndex--];
}

int StackArray::peek() const {
    if (isEmpty()) {
        std::cerr << "Stack is empty.\n";
        return -1;
    }
    return arr[topIndex];
}


// ================= StackLinkedList Implementation =================
StackLinkedList::StackLinkedList() : top(nullptr) {}

StackLinkedList::~StackLinkedList() {
    while (!isEmpty()) {
        pop();
    }
}

bool StackLinkedList::isEmpty() const {
    return top == nullptr;
}

void StackLinkedList::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode; // O(1) time complexity
}

int StackLinkedList::pop() {
    if (isEmpty()) {
        std::cerr << "Stack Underflow! Stack is empty.\n";
        return -1;
    }
    Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    delete temp; // O(1) time complexity
    return poppedValue;
}

int StackLinkedList::peek() const {
    if (isEmpty()) {
        std::cerr << "Stack is empty.\n";
        return -1;
    }
    return top->data;
}