// A class template for holding a linked list.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:
    // Declare a structure for the list
    struct ListNode
    {
        T value;                // The value in this node
        struct ListNode *next;  // To point to the next node
    };

    ListNode *head;   // List head pointer

public:
    // Constructor
    LinkedList()
    { head = nullptr; }

    // Destructor
    ~LinkedList();

    // Linked list operations
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    void displayList() const;

    //more functions
    T getTotal();
    int getCount();
    T getElementAt(int);
    T getAverage();
    T getMaximum();
    T getMinimun();
    T getMinimunIndex();
    T getMaximunIndex();
};


//**************************************************
// appendNode appends a node containing the value  *
// pased into newValue, to the end of the list.    *
//**************************************************
template <class T>
T LinkedList<T>::getElementAt(int index)
{
 int currentIndex =0;
 ListNode* current =head;
 while (current != nullptr)
 {
     if (currentIndex == index)
     {
         return current -> value;
     }
     current = current-> next;
     currentIndex++;
 }

}

template<class T>
T LinkedList<T>::getMinimun()
{
    ListNode *nodePtr = head;
    T minimum = nodePtr->value;
    while (nodePtr != nullptr) {
        if (minimum > nodePtr->value) {
            minimum = nodePtr->value;
        }
        nodePtr = nodePtr->next;
    }
    return minimum;
}

template<class T>
T LinkedList<T>::getMinimunIndex()
{
    ListNode *nodePtr = head;
    T minimum = nodePtr->value;
    int minimumIndex =1;
    int currentIndex= 1;
    while (nodePtr != nullptr) {
        if (minimum > nodePtr->value) {
            minimum = nodePtr->value;
            minimumIndex = currentIndex;
        }
        nodePtr = nodePtr->next;
        currentIndex++;
    }
    return minimumIndex;
}



template<class T>
T LinkedList<T>::getMaximum()
{
    ListNode* nodePtr = head;
    T maximum = nodePtr->value;

    int currentIndex =0;
    while (nodePtr!= nullptr) {
        if (maximum < nodePtr->value) {
            maximum = nodePtr->value;

        }
        nodePtr = nodePtr->next;
    }
    return maximum;
}

template<class T>
T LinkedList<T>::getMaximunIndex()
{
    ListNode* nodePtr = head;
    T maximum = nodePtr->value;
    int maxIndex =1;
    int currentIndex =1;
    while (nodePtr!= nullptr)
    {
        if (maximum < nodePtr ->value)
        {
            maximum = nodePtr ->value;
            maxIndex= currentIndex;
        }
        nodePtr= nodePtr->next;
        currentIndex++;
    }
return maxIndex;
}

template<class T>
T LinkedList<T>::getTotal()
{
    T total = 0;
    ListNode* nodePtr = nullptr;
    nodePtr= head; // points to the head of the linked list
    while (nodePtr!= nullptr)
    {
        total = total + nodePtr-> value;
        nodePtr =nodePtr-> next;
    }
    return total;
}


template<class T>
int LinkedList<T>::getCount()
{
    int count =0;
    ListNode* nodePtr = head;

    while(nodePtr!= nullptr)
    {
        count++;
        nodePtr = nodePtr ->next;
    }
    return count;
}

template<class T>
T LinkedList<T>::getAverage()
{
    T total = getTotal();
    int count = getCount();
    T average = total / count;

    return average;
}

template <class T>
void LinkedList<T>::appendNode(T newValue)
{
    ListNode *newNode;  // To point to a new node
    ListNode *nodePtr;  // To move through the list

    // Allocate a new node and store newValue there.
    newNode = new ListNode;
    newNode->value = newValue;
    newNode->next = nullptr;

    // If there are no nodes in the list
    // make newNode the first node.
    if (!head)
        head = newNode;
    else  // Otherwise, insert newNode at end.
    {
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Find the last node in the list.
        while (nodePtr->next)
            nodePtr = nodePtr->next;

        // Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

template <class T>
void LinkedList<T>::displayList() const
{
    ListNode *nodePtr;  // To move through the list

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, traverse
    // the list.
    while (nodePtr)
    {
        // Display the value in this node.
        cout << nodePtr->value << endl;

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
}

//**************************************************
// The insertNode function inserts a node with     *
// newValue copied to its value member.            *
//**************************************************

template <class T>
void LinkedList<T>::insertNode(T newValue)
{
    ListNode *newNode;					// A new node
    ListNode *nodePtr;					// To traverse the list
    ListNode *previousNode = nullptr;	// The previous node

    // Allocate a new node and store newValue there.
    newNode = new ListNode;
    newNode->value = newValue;

    // If there are no nodes in the list
    // make newNode the first node
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else  // Otherwise, insert newNode
    {
        // Position nodePtr at the head of list.
        nodePtr = head;

        // Initialize previousNode to nullptr.
        previousNode = nullptr;

        // Skip all nodes whose value is less than newValue.
        while (nodePtr != nullptr && nodePtr->value < newValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else  // Otherwise insert after the previous node.
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

//*****************************************************
// The deleteNode function searches for a node        *
// with searchValue as its value. The node, if found, *
// is deleted from the list and from memory.          *
//*****************************************************

template <class T>
void LinkedList<T>::deleteNode(T searchValue)
{
    ListNode *nodePtr;       // To traverse the list
    ListNode *previousNode;  // To point to the previous node

    // If the list is empty, do nothing.
    if (!head)
        return;

    // Determine if the first node is the one.
    if (head->value == searchValue)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to head of list
        nodePtr = head;

        // Skip all nodes whose value member is
        // not equal to num.
        while (nodePtr != nullptr && nodePtr->value != searchValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list,
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

template <class T>
LinkedList<T>::~LinkedList()
{
    ListNode *nodePtr;   // To traverse the list
    ListNode *nextNode;  // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}
#endif