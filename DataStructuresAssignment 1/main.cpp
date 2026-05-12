
#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

int main() {
    std::cout << "========== TESTING LINKED LIST ==========\n";
    LinkedList list;
    list.insertAtHead(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtHead(5);
    list.display(); // Expected: 5 -> 10 -> 20 -> 30 -> nullptr

    list.deleteValue(20);
    std::cout << "After deleting 20: ";
    list.display(); // Expected: 5 -> 10 -> 30 -> nullptr

    std::cout << "\n========== TESTING STACK (ARRAY) ==========\n";
    StackArray stackArr(3);
    stackArr.push(1);
    stackArr.push(2);
    stackArr.push(3);
    stackArr.push(4); // Expected: Overflow error
    std::cout << "Popped: " << stackArr.pop() << "\n"; // Expected: 3

    std::cout << "\n========== TESTING STACK (LINKED LIST) ==========\n";
    StackLinkedList stackLL;
    stackLL.push(100);
    stackLL.push(200);
    std::cout << "Top element is: " << stackLL.peek() << "\n"; // Expected: 200
    std::cout << "Popped: " << stackLL.pop() << "\n"; // Expected: 200
    std::cout << "Popped: " << stackLL.pop() << "\n"; // Expected: 100
    stackLL.pop(); // Expected: Underflow error

    std::cout << "\n========== TESTING QUEUE (CIRCULAR ARRAY) ==========\n";
    QueueArray queueArr(3);
    queueArr.enqueue(10);
    queueArr.enqueue(20);
    queueArr.enqueue(30);
    queueArr.enqueue(40); // Expected: Full error
    std::cout << "Dequeued: " << queueArr.dequeue() << "\n"; // Expected: 10
    queueArr.enqueue(40); // Should wrap around using circular logic
    std::cout << "Dequeued: " << queueArr.dequeue() << "\n"; // Expected: 20

    std::cout << "\n========== TESTING QUEUE (LINKED LIST) ==========\n";
    QueueLinkedList queueLL;
    queueLL.enqueue(500);
    queueLL.enqueue(600);
    std::cout << "Dequeued: " << queueLL.dequeue() << "\n"; // Expected: 500
    std::cout << "Dequeued: " << queueLL.dequeue() << "\n"; // Expected: 600
    queueLL.dequeue(); // Expected: Empty error

    std::cout << "\nAll data structures tested successfully. Memory will be cleaned up by destructors.\n";
    return 0;
}