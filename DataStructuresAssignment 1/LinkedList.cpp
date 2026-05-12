#include "LinkedList.h"
#include <iostream>

// Constructor: Both markers start at nothing
LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

// Destructor: Delete every node to free memory
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Insert at Head: O(1) time
void LinkedList::insertAtHead(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode; // Only one node, so it's both head and tail
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

// Insert at End: O(1) time (Fast because we have a tail!)
void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode; // List was empty
    }
    else {
        tail->next = newNode; // Link current tail to new node
        tail = newNode;       // Move tail marker to the new end
    }
}

// Delete Value: Handles head, middle, and tail cases
void LinkedList::deleteValue(int value) {
    if (head == nullptr) return; // Case 0: List is empty

    // Case 1: Value is at the Head
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr; // List is now empty
        }
        delete temp;
        return;
    }

    // Case 2: Search for value in Middle or Tail
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) return; // Value not found

    // Unlink the node
    previous->next = current->next;

    // Special Tail Logic: If we deleted the last node, update tail pointer
    if (current == tail) {
        tail = previous;
    }

    delete current;
}

// Display: Walk through and print
void LinkedList::display() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr\n";
}
// if i dont use tail  
// 
// 
// 
//#include "LinkedList.h"
// #include 
//
// LinkedList::LinkedList() : head(nullptr) {}
//
// LinkedList::~LinkedList() {
//     Node* current = head;
//     while (current != nullptr) {
//         Node* nextNode = current->next;
//         delete current;
//         current = nextNode;
//     }
// }
//
// void LinkedList::insertAtHead(int value) {
//     Node* newNode = new Node(value);
//     newNode->next = head;
//     head = newNode;
// }
//
// void LinkedList::insertAtEnd(int value) {
//     Node* newNode = new Node(value);
//     if (head == nullptr) {
//         head = newNode;
//         return;
//     }
//     Node* current = head;
//     while (current->next != nullptr) {
//         current = current->next;
//     }
//     current->next = newNode;
// }
//
// void LinkedList::deleteValue(int value) {
//     if (head == nullptr) return;
//
//     // If the head node itself holds the value to be deleted
//     if (head->data == value) {
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         return;
//     }
//
//     // Search for the value, keeping track of the previous node
//     Node* current = head;
//     Node* previous = nullptr;
//     while (current != nullptr && current->data != value) {
//         previous = current;
//         current = current->next;
//     }
//
//     // If value was not present in the list
//     if (current == nullptr) return;
//
//     // Unlink the node from the linked list
//     previous->next = current->next;
//     delete current;
// }
//
// void LinkedList::display() const {
//     Node* current = head;
//     while (current != nullptr) {
//         std::cout << current->data << " -> ";
//         current = current->next;
//     }
//     std::cout << "nullptr\n";
// }