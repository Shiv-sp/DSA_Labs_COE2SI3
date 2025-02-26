#include "objPosSLinkedList.h"
#include <iostream>
using namespace std;

// Develop the objPos Singly Linked List WITHOUT DUMMY HEADER.  
// Use the Test cases Test.cpp to complete the Test-Driven Development

objPosSLinkedList::objPosSLinkedList()
{
    // Creates the head node
    listHead = nullptr;
    // Sets the persistent head to null
    persistHead = nullptr;

    // Sets the list size to 0
    listSize = 0;

}

objPosSLinkedList::~objPosSLinkedList()
{
    // Deletes all the nodes in the list
    while (!isEmpty())
    {
        removeHead();
    }

}

int objPosSLinkedList::getSize()
{
    // Returns the size of the list
    return listSize;


}

bool objPosSLinkedList::isEmpty()
{
    // Checks if the list is empty
    return listSize == 0;
   
}

void objPosSLinkedList::insertHead(const objPos &thisPos)
{
    // Inserts a new node at the head of the list
    SNode* newNode = new SNode();
    // Sets the data of the new node
    newNode->data = thisPos;
    // Connects the new node to the head
    newNode->next = listHead;

    // Sets the new node as the head
    listHead = newNode;

    // Increments the list size
    listSize++;
    
}

void objPosSLinkedList::insertTail(const objPos &thisPos)
{
    // Inserts a new node at the tail of the list
    SNode* newNode = new SNode();

    // Sets the data of the new node
    newNode->data = thisPos;

    // Sets the next pointer of the new node to null
    newNode->next = nullptr;

    // If the list is empty, the new node is the head
    SNode* currNode = listHead;


    // If the list is empty, the new node is the head
    if (isEmpty())
    {
        listHead = newNode;
    }

    else
    {
        // Finds the last node in the list
        while (currNode->next != nullptr)
        {
            // Moves to the next node
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }
    listSize++;
    
}

void objPosSLinkedList::insert(const objPos &thisPos, int index)
{
    // Inserts a new node at the specified index
    if (index <= 0)
    {
        insertHead(thisPos);
    }
    else if (index >= listSize)
    {
        insertTail(thisPos);
    }
    // If the index is in the middle of the list
    else
    {
        // Creates a new node
        SNode* newNode = new SNode();
        // Sets the data of the new node
        newNode->data = thisPos;
        SNode* currNode = listHead;

        // Finds the node before the specified index
        for (int i = 0; i < index - 1; i++)
        {
            // Moves to the next node
            currNode = currNode->next;
        }
        newNode->next = currNode->next;
        currNode->next = newNode;
        listSize++;
    }
    
}

objPos objPosSLinkedList::getHead() const
{
    // Returns the data of the head node
    if (listSize==0)
    {
        return objPos(-99, 0, 0, 0, 0);
    }
    else
    {
        return listHead->data;
    }

}

objPos objPosSLinkedList::getTail() const
{
    // Returns the data of the tail node
    if (listSize == 0)
    {
        return objPos(-99, 0, 0, 0, 0);
    }

    else
    {
        // Finds the last node in the list
        SNode* currNode = listHead;
        // Moves to the next node
        while (currNode->next != nullptr)
        {
            currNode = currNode->next;
        }
        return currNode->data;
    }

}

objPos objPosSLinkedList::get(int index) const
{
    // Returns the data of the node at the specified index
    if (index <= 0)
    {
        return getHead();
    }
    else if (index >= listSize)
    {
        return getTail();
    }
    else
    {
        // Finds the node at the specified index
        SNode* currNode = listHead;
        // Moves to the next node
        for (int i = 0; i < index; i++)
        {
            currNode = currNode->next;
        }
        return currNode->data;
    }

}

objPos objPosSLinkedList::getNext()
{
    // Returns the data of the next node
    if (persistHead == nullptr)
    {
        // Sets the persistent head to the head
        persistHead = listHead;
    }
    else
    {
        persistHead = persistHead->next;
    }
    if (persistHead == nullptr)
    {
        return objPos(-99, 0, 0, 0, 0);
    }
    else
    {
        return persistHead->data;
    }

}

void objPosSLinkedList::resetReadPos()
{
    // Resets the read position to the head
    persistHead = nullptr;

}

void objPosSLinkedList::set(const objPos &thisPos, int index)
{
    // Sets the data of the node at the specified index
    if (index < 0)
    {
        index = 0;
    }
    else if (index >= listSize)
    {
        index = listSize - 1;
    }
    SNode* currNode = listHead;
    for (int i = 0; i < index; i++)
    {
        currNode = currNode->next;
    }
    currNode->data = thisPos;

}


objPos objPosSLinkedList::removeHead()
{
    // Removes the head node
    if (isEmpty())
    {
        return objPos(-99, 0, 0, 0, 0);
    }
    else
    {
        SNode* currNode = listHead;
        objPos data = currNode->data;
        listHead = listHead->next;
        delete currNode;
        listSize--;
        return data;
    }

}

objPos objPosSLinkedList::removeTail()
{
    // Removes the tail node
    if (isEmpty())
    {
        return objPos(-99, 0, 0, 0, 0);
    }
    else
    {
        SNode* currNode = listHead;
        SNode* prevNode = nullptr;
        while (currNode->next != nullptr)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        objPos data = currNode->data;
        if (prevNode == nullptr)
        {
            listHead = nullptr;
        }
        else
        {
            prevNode->next = nullptr;
        }
        delete currNode;
        listSize--;
        return data;
    }
  
}

objPos objPosSLinkedList::remove(int index)
{
    // Removes the node at the specified index
    if (index <= 0)
    {
        return removeHead();
    }
    else if (index >= listSize)
    {
        return removeTail();
    }
    else
    {
        // Removes the node at the specified index
        SNode* currNode = listHead;
        SNode* prevNode = nullptr;
        // Finds the node before the specified index
        for (int i = 0; i < index; i++)
        {
            //  Moves to the next node
            prevNode = currNode;
            currNode = currNode->next;
        }

        // Returns the data of the removed node
        objPos data = currNode->data;
        
        // Connects the previous node to the next node
        prevNode->next = currNode->next;
        delete currNode;
        listSize--;
        return data;
    }

}

void objPosSLinkedList::printList() const
{ 

}

