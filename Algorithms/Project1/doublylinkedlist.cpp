// ============================================
// FILE: doublylinkedlist.cpp
// ============================================
// University of Arkansas at Little Rock
// Department of Computer Science
// CPSI 28003 - 01 and 9S1: Algorithms
// Fall 2025
// Project 1: Doubly Linked List
// Due Date: September 30, 2025, 10:50 AM, Tuesday
// Name: [Student Name]
// Student-ID (Last 4 Digits): [XXXX]
// Description of the Program: Implementation of a doubly linked list with
// methods to draw the list pictorially, check for palindromes, and split into sublists.
// Date Written: September 2025
// Date Revised: September 2025

#include "doublylinkedlist.h"

DoublyLinkedList::DoublyLinkedList()
{
    head = NULL;
    tail = NULL;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::addNewNodeToFront(Node * newNode) {
    if(head == NULL && tail == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void DoublyLinkedList::addNewNodeToBack(Node * newNode) {
    if(head == NULL && tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

Node* DoublyLinkedList::removeNodeFromFront()
{
    Node *tempNode;
    tempNode = head;
    head = head->next;
    return tempNode;
}

void DoublyLinkedList::removeNodeFromBack()
{

}

void DoublyLinkedList::displayDoublyLinkedList()
{
    Node *tempNode;
    tempNode = head;
    while (tempNode != NULL)
    {
        cout << tempNode->value << " ";
        tempNode = tempNode->next;
    }
}

// Method 1: Draw pictorial view of doubly linked list (30 points)
void DoublyLinkedList::drawDoublyLinkedList()
{
    // check if list empty
    if (head == NULL) {
        cout << "Empty list" << endl;
        return;
    }
    
    Node *tempNode = head;
    
    
    while (tempNode != NULL) {
        // value + address
        cout << tempNode->value << " " << tempNode << endl;
        
        cout << tempNode->prev;
        
        if (tempNode->prev == NULL) {
            cout << " (0)";
        }
        cout << endl;
        
        // next
        cout << tempNode->next;
        if (tempNode->next == NULL) {
            cout << " (0)";
        }
        cout << endl;
        cout << endl;
        
        // move to next and start over
        tempNode = tempNode->next;
    }
}

// Method 2: Check if the list is a palindrome (30 points)
bool DoublyLinkedList::isPalindrome()
{
    // An empty list is considered a palindrome
    if (head == NULL) {
        return true;
    }
    
    // Single node is also a palindrome
    if (head->next == NULL) {
        return true;
    }
    
    // Use two pointers: one from head and one from tail
    Node *frontPtr = head;
    Node *backPtr = tail;
    
    // Compare values from both ends moving towards the center
    while (frontPtr != backPtr && frontPtr->prev != backPtr) {
        if (frontPtr->value != backPtr->value) {
            return false;  // Not a palindrome
        }
        frontPtr = frontPtr->next;
        backPtr = backPtr->prev;
    }
    
    return true;  // It's a palindrome
}

// Method 3: Split the list into n equal parts (40 points)
void DoublyLinkedList::split(int n)
{
    // Check if n is less than 1
    if (n < 1) {
        cout << "cannot be processed." << endl;
        return;
    }
    
    // Count the total number of nodes in the list
    int count = 0;
    Node *tempNode = head;
    while (tempNode != NULL) {
        count++;
        tempNode = tempNode->next;
    }
    
    // Check if n exceeds the size of the list
    if (n > count) {
        cout << "cannot be processed." << endl;
        return;
    }
    
    // Check if the list can be evenly divided by n
    if (count % n != 0) {
        cout << "cannot be processed." << endl;
        return;
    }
    
    // Calculate the size of each sublist
    int sublistSize = count / n;
    
    // Display the sublists
    tempNode = head;
    for (int i = 0; i < n; i++) {
        cout << "Sublist " << (i + 1) << ": ";
        
        // Display nodes for this sublist
        for (int j = 0; j < sublistSize; j++) {
            cout << tempNode->value;
            if (j < sublistSize - 1) {
                cout << " ";
            }
            tempNode = tempNode->next;
        }
        cout << endl;
    }
}