//
//  Set.h
//  CS32_Project_2
//
//  Created by Zegao Liu on 16/4/18.
//  Copyright © 2016年 Zegao Liu. All rights reserved.
//

#ifndef newSet_h
#define newSet_h
#include <iostream>
#include <String>

typedef unsigned long ItemType;

class Set
{
public:
    Set(int size);         // Create a set with a size.
    
    
    //Default Constructor
    Set(); //Creat a empty set
    
    //Destructor
    ~Set();
    
    //Operator =
    Set& operator=(const Set &src);
    
    bool empty() const;  // Return true if the set is empty, otherwise false.
    
    int size() const;    // Return the number of items in the set.
    
    bool insert(const ItemType& value);
    // Insert value into the set if it is not already present.  Return
    // true if the value was actually inserted.  Leave the set unchanged
    // and return false if the value was not inserted (perhaps because it
    // is already in the set or because the set has a fixed capacity and
    // is full).
    
    bool erase(const ItemType& value);
    // Remove the value from the set if present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.
    
    bool contains(const ItemType& value) const;
    // Return true if the value is in the set, otherwise false.
    
    bool get(int i, ItemType& value) const;
    // If 0 <= i < size(), copy into value an item in the set and
    // return true.  Otherwise, leave value unchanged and return false.
    // (See below for details about this function.)
    
    void swap(Set& other);
    // Exchange the contents of this set with the other one
    
    
    
private:
    //exam: Can we put Node impelmentation in prviate data member?
    //exam: Do we need write a destructor for Node?
    struct Node
    {
        //Double Link Structure
        ItemType data;
        Node* prev;
        Node* next;
        //Intialize node with a input and set m_Setcheck as false
        Node(ItemType Input) : data(Input) {}
    
        
        //exam: Can I do this?
    };
    
    // instantiation
    Node* head = nullptr;
    
    // Find was made private because we want to return Nodes, which are private
    // plus, we will only be using it as a helper for implementing our public functions
    Node* find(ItemType data) {
        
        //exam: Can we add implementation in praivate data member?????
        //exam: delete this comment since they are from TA
        // Since we have a dummy ndoe, this iteration strategy works for any list case
        // (empty, single element, etc...)
    
        for (Node* n = head->next; n != head; n = n->next) {
            if (n->data == data)
                return n;
        }
        return nullptr;
    }


//////////////////////////////////////////////////////////////////////////////////////
//exam: Old data member in HW1
//////////////////////////////////////////////////////////////////////////////////////
    
    //Maximum size ??How do I make it always equals the maximum m_Set? HW1
    //const int m_DEFAULT_MAX_ITEMS = 100;
    
    //m_Setcheck checks if a specific entry in the array is valid HW1
    //bool* m_Setcheck;
    
    //Pointer HW1
    //ItemType* m_Set;
    
    //This one is the max size
    //int m_Setsize;
    
//////////////////////////////////////////////////////////////////////////////////////
//exam: Old data member in HW1
//////////////////////////////////////////////////////////////////////////////////////

    
    
};

void unite(const Set& s1, const Set& s2, Set& result);

void subtract(const Set& s1, const Set& s2, Set& result);



#endif /* newSet_h */
