//
//  main.cpp
//  CS32_Project_2
//
//  Created by Zegao Liu on 16/4/18.
//  Copyright © 2016年 Zegao Liu. All rights reserved.
//
#include "Set.h"
#include <iostream>
#include <cassert>
using namespace std;

void test()
{
    Set uls;
    assert(uls.insert(10));
    assert(uls.insert(20));
    assert(uls.size() == 2);
    assert(uls.contains(20));
    ItemType x = 30;
    assert(uls.get(0, x)  &&  (x == 10  ||  x == 20));
}

int main()
{
    test();
    cout << "Passed all tests" << endl;
}