//
//  Set.cpp
//  CS32_Project_2
//
//  Created by Zegao Liu on 16/4/18.
//  Copyright © 2016年 Zegao Liu. All rights reserved.
//

#include <iostream>
#include "Set.h"


void unite(const Set& s1, const Set& s2, Set& result)
{
    //Initialize result with a new Set
    Set Newresult;
    result.swap(Newresult);
    
    //exam:Is it ok not to initialize it?
    ItemType temp;
    
    //Add s1 into result
    for(int i =0 ; i < s1.size(); i++)
    {
        s1.get(i,temp);
        result.insert(temp);
    }
    
    //Add s2 into result
    for(int i =0 ; i < s2.size(); i++)
    {
        s2.get(i,temp);
        result.insert(temp);
    }
}

//exam: check if it works with 0 set
void subtract(const Set& s1, const Set& s2, Set& result)
{
    //Initialize result with a new Set
    Set Newresult;
    result.swap(Newresult);
    
    ItemType temp1;
    ItemType temp2;
    int number=0;
    
    for(int i =0 ; i < s1.size(); i++)
    { number =0;
        for(int j =0 ; j < s2.size(); j++)
        {
        
            s1.get(i,temp1);
            s2.get(j,temp2);
            
            //If the value in s1 is found in s2, breaks
            if(temp1 == temp2)
                break;
            //If it is not break and it reachs the end of search, insert the value of s1
            if(number == s2.size()-1)
                result.insert(temp1);
            
            //exam: the position of number, is it supposed to be before if(number...) or after
            number ++;
            
            
        }
    }
            
            
}


Set::Set()
{
    //Creat a dummy node as the head
    
    //exam: ????? How to initialize the value of head????? can i just add a default constructor for Node and initialize it with Node(), what will be the value of data then?
    head = new Node(0);
    head->next = head;
    head->prev = head;
    
  
}

Set::~Set()
{
    //Violently delete everything that is not head
    //exam: Does it actually works?
    Node* n = head->next;
    if( n == head)
        delete head;
    else
    {for (n= head->next; n != head; n = n->next)
    {
            delete n;
    }
    //Delete head
    delete head;
    }
}

//Operator =
Set& Set::operator=(const Set &src)
{
    //Violently delete everything that is not head
    
    for (Node* n = head->next; n != head; n = n->next)
    {
        delete n;
    }
    
    //
    head->next = head;
    head->prev = head;
    
    for (Node* n = src.head->next; n != src.head; n = n->next)
    {
        insert(n->data);
    }
    
    return(*this);
}


// Return true if the set is empty, otherwise false.
bool Set::empty() const
{
    //n refer to the next one after head
    Node* n = head->next;
    if (n != head)
        return false;
    return true;
}

// Return the number of items in the set.
int Set::size() const
{
    int size = 0;
    
    //Size++ until n reachs head again
    for (Node* n = head->next; n != head; n = n->next)
    {
        size ++;
    }
    return size;
}

// Insert value into the set if it is not already present.  Return
// true if the value was actually inserted.  Leave the set unchanged
// and return false if the value was not inserted (perhaps because it
// is already in the set or because the set has a fixed capacity and
// is full).

//exam: Am I supposed to insert the new Node between the last Node and the head?
bool Set::insert(const ItemType& data)
{
    //Check if data has already in the Set
    for (Node* n = head->next; n != head; n = n->next) {
        if (n->data == data)
            return false;
    }
    
    //exam: Is it ok to just call it n?
    Node* n = new Node(data);
    
    // attach the node to the list
    n->prev = head->prev;
    n->next = head;
    
    // attach the list to the node
    head->prev->next = n;
    head->prev = n;
    return true;
}

// Remove the value from the set if present.  Return true if the
// value was removed; otherwise, leave the set unchanged and
// return false.
bool Set::erase(const ItemType& data)
{
    if( find(data) == nullptr)
        return false;
    
    Node* n = find(data);
    
    // attach previous and next nodes to each other
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    
    return true;
}

// Return true if the value is in the set, otherwise false.
bool Set::contains(const ItemType& data) const
{
    //Go trough the double list until it reachs head again
    for (Node* n = head->next; n != head; n = n->next)
        //if it find data, return true
        if (n->data == data)
            return true;
    
        //Otherwise, return false in any case
        return false;
}


// If 0 <= i < size(), copy into value an item in the set and
// return true.  Otherwise, leave value unchanged and return false
// (See below for details about this function.)
bool Set::get(int i, ItemType& data) const
{
    if( i<0 || i>= this->size())
        return false;
    
    //K represent the position of the node
    int k =0;
    for (Node* n = head->next; n != head; n = n->next)
    {
        //If the position of the node is 1, make them the same
        if( k== i)
            data = n->data;
        k++;
    }
    return true;
}

// Exchange the contents of this set with the other one
void Set::swap(Set& other)
{
    Node* temphead = this->head;
    
    this->head = other.head;
    other.head->prev->next = this->head;
    other.head->next->prev = this->head;
    
    other.head = temphead;
    temphead->prev->next = other.head;
    temphead->next->prev = other.head;
}





