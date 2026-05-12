# Linear Data Structures in C++

## Overview
This project is an implementation of core linear data structures—Linked Lists, Stacks, and Queues—written in C++. The project demonstrates modular software architecture by separating declarations (`.h` files) from implementations (`.cpp` files).

## Features
* **Singly Linked List:** Supports dynamic insertion and deletion with careful pointer management to prevent memory leaks.
* **Stacks (LIFO):** 
  * Array-based implementation with overflow/underflow protection.
  * Linked List-based implementation featuring strictly **O(1)** time complexity.
* **Queues (FIFO):**
  * Circular Array implementation using modulo arithmetic for efficient space utilization.
  * Linked List-based implementation utilizing `front` and `rear` pointers for **O(1)** enqueue and dequeue operations.

## Memory Management
This project enforces strict memory management. Every dynamically allocated node or array is properly deallocated using class destructors to ensure zero memory leaks when objects go out of scope.

## How to Compile and Run
To compile the project, open your terminal and run the following command:

```bash
g++ main.cpp LinkedList.cpp Stack.cpp Queue.cpp -o dsa_test
