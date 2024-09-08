# Memory Allocation and Linked Lists

## Overview

This project explores memory allocation techniques and linked list implementations in C/C++.
It demonstrates the creation, manipulation, and management of linked lists, focusing on dynamic memory allocation.

## Usage

1. **Run the Executable:** Compile and run the executable to interact with the linked list functionalities.
   ```
   ./LinkedListExample
   ```

2. **Operations**

- **Add Node:** Add a new node to the linked list.
- **Delete Node:** Remove a node from the linked list.
- **Search Node:** Find a node within the linked list.
- **Print List:** Display all nodes in the linked list.

## Classes and Methods

### Node

- **Data Members:**
  - `int data`: The data stored in the node.
  - `Node* next`: Pointer to the next node in the linked list.

- **Constructor:**
  - `Node(int value)`: Initializes the node with a value and sets the next pointer to `nullptr`.

### LinkedList

- **Data Members:**
  - `Node* head`: Pointer to the first node in the linked list.

- **Methods:**
  - `LinkedList()`: Default constructor, initializes an empty list.
  - `void addNode(int value)`: Adds a new node with the specified value to the list.
  - `void deleteNode(int value)`: Deletes the first node with the specified value.
  - `bool searchNode(int value)`: Searches for a node with the specified value.
  - `void printList()`: Prints all nodes in the linked list.

## Memory Management

This project emphasizes proper memory management, including dynamic memory allocation and deallocation to avoid memory leaks.

## Conclusion

The project showcases essential techniques in memory management and linked list operations in C/C++.
It provides hands-on experience with dynamic memory allocation and linked list manipulation, which are fundamental concepts in system programming.
