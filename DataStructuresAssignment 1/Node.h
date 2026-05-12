#pragma once
#ifndef NODE_H
#define NODE_H

// Shared Node structure for Linked List, Stack, and Queue implementations
struct Node {
    int data;
    Node* next;

    // Constructor for easy node initialization
    Node(int val) : data(val), next(nullptr) {}
};

#endif