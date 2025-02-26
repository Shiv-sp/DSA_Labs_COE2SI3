#include "objPosDLinkedList.h"
#include <iostream>
using namespace std;

// Develop the objPos Doubly Linked List WITH DUMMY HEADER here.  
// Use the Test cases Test.cpp to complete the Test-Driven Development

objPosDLinkedList::objPosDLinkedList()
{

    // Creates dummy header and tail nodes
    listHead = new DNode();
    listTail = new DNode();

    // Connects the dummy header and tail nodes
    listHead->next = listTail;
    listTail->prev = listHead;


    // Sets the persistent head to the dummy header
    persistHead = listHead;

    // Sets the list size to 0
    listSize = 0;

}

objPosDLinkedList::~objPosDLinkedList()
{
    DNode* currNode = listHead;

    while (currNode) 
    {
        DNode* nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }


    delete currNode;

    listHead = nullptr;
    listTail = nullptr;
    persistHead = nullptr;
    listSize = 0;
}

int objPosDLinkedList::getSize()
{
    // Returns the size of the list
    return listSize;
}

bool objPosDLinkedList::isEmpty()
{
    // Checks if the list is empty
    if (listSize == 0)
    {
        return true;
    }
    else
    {
        return false;        
    };  
}

void objPosDLinkedList::insertHead(const objPos &thisPos)
{
    // Creates a new node
    DNode* newNode = new DNode();
    newNode->data = thisPos;

    // Connects the new node to the dummy header
    newNode->next = listHead->next;
    newNode->prev = listHead;
    listHead->next->prev = newNode;  // Ensure this is not null
    listHead->next = newNode;


    // Increases the list size
    listSize++;   
}

void objPosDLinkedList::insertTail(const objPos &thisPos)
{
    // Creates a new node
    DNode* newNode = new DNode();
    newNode->data = thisPos;

    // Connects the new node to the dummy tail
    newNode->prev = listTail->prev;
    listTail->prev->next = newNode;
    listTail->prev = newNode;
    newNode->next = listTail;

    // Increases the list size
    listSize++;
   
    
}

void objPosDLinkedList::insert(const objPos &thisPos, int index)
{
    // Inserts a new node at the specified index
    if (index <= 0)
    {
        insertHead(thisPos);
    }
    else if (index >= (listSize-1))
    {
        insertTail(thisPos);
    }
    // Inserts a new node at the specified index
    else
    {
        DNode* currNode = new DNode();
        for (int i = 0; i < index; i++)
        {
            currNode = currNode->next;
        }

        DNode* newNode = new DNode();
        newNode->data = thisPos;

        newNode->next = currNode->next;
        currNode->next->prev = newNode;
        currNode->next = newNode;
        newNode->prev = currNode;

        listSize++;
    }

    
}

objPos objPosDLinkedList::getHead() const
{
    // Returns the data of the first node
    return listHead->next->data;

}

objPos objPosDLinkedList::getTail() const
{
    // Returns the data of the last node
    return listTail->prev->data;

}

objPos objPosDLinkedList::get(int index) const
{
    // Returns the data of the node at the specified index
    if (index <= 0)
    {
        return getHead();
    }
    else if (index >= (listSize-1))
    {
        return getTail();
    }
    else
    {
        DNode* currNode = listHead->next;

        for (int i = 0; i < index; i++)
        {
            currNode = currNode->next;
        }

        return currNode->data;
    }

}

objPos objPosDLinkedList::getNext()
{
    // Returns the data of the next node
    persistHead = persistHead->next;
    
    if (persistHead->next == nullptr)
    {
        return objPos(0,0,0,0,0);
    }
    else
    {
        return persistHead->data;
    }

}

void objPosDLinkedList::resetReadPos()
{
    // Resets the persistent head to the dummy header
    persistHead = listHead;

}

void objPosDLinkedList::set(const objPos &thisPos, int index)
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

    // Sets the data of the node at the specified index
    DNode* currNode = listHead->next;

    for (int i = 0; i < index; i++)
    {
        currNode = currNode->next;
    }

    currNode->data = thisPos;


}


objPos objPosDLinkedList::removeHead()
{
    // Removes the first node
    DNode* currNode = listHead->next;
    listHead->next = currNode->next;
    currNode->next->prev = listHead;

    objPos data = currNode->data;
    delete currNode;

    currNode = nullptr;

    listSize--;

    return data;

}

objPos objPosDLinkedList::removeTail()
{
    // Removes the last node
    DNode* currNode = listTail->prev;
    listTail->prev = currNode->prev;
    currNode->prev->next = listTail;

    // Returns the data of the removed node
    objPos data = currNode->data;
    delete currNode;

    // Deletes the node
    currNode = nullptr;

    listSize--;

    return data;
  
}

objPos objPosDLinkedList::remove(int index)
{
    // Removes the node at the specified index
    if (index <= 0)
    {
        return removeHead();
    }

    else if (index >= (listSize-1))
    {
        return removeTail();
    }

    else
    {
        // Removes the node at the specified index
        DNode* currNode = listHead->next;
        for (int i = 0; i < index; i++)
        {
            currNode = currNode->next;
        }

        // Connects the previous and next nodes
        objPos data = currNode->data;

        // Connects the previous and next nodes
        currNode->prev->next = currNode->next;
        currNode->next->prev = currNode->prev;

        // Deletes the node
        delete currNode;
        currNode = nullptr;

        // Decreases the list size
        listSize--;
        
        // Returns the data of the removed node
        return data;
    }

}

void objPosDLinkedList::printList() const
{
    return; 

}


