//
//  Heap.cpp
//  fnMath
//
//  Created by Steven Novak on 2/16/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//

#ifndef Heap_cpp
#define Heap_cpp

#include "Heap.hpp"

namespace fnMath{
    
#pragma mark Constructors
// ---------------------------------------- Constructors


    
#pragma mark Accessors
// ---------------------------------------- Accessors


    
#pragma mark Public Methods
// ---------------------------------------- Public Methods

template <typename Comparable>
void Heap<Comparable>::Insert(const Comparable & item)
{
    if(currentSize == data.size() -1)
        data.resize(data.size() * 2);
    
    int hole = ++currentSize;
    Comparable copy = item;
    
    data[0] = std::move(copy);
    
    for(; item<data[hole / 2]; hole /=2)
        data[hole] = std::move(data[hole/2]);
    
    data[hole] = std::move(data[0]);
}

/*
 * Need to fix this to optimize move symantics
 *
 *
 */
template <typename Comparable>
void Heap<Comparable>::Insert(Comparable && item)
{
    if(currentSize == data.size() -1)
        data.resize(data.size() * 2);
    
    int hole = ++currentSize;
    Comparable copy = item;
    
    data[0] = std::move(copy);
    
    for(; item<data[hole / 2]; hole /=2)
        data[hole] = std::move(data[hole/2]);
    
    data[hole] = std::move(data[0]);
}
   
template <typename Comparable>
void Heap<Comparable>::DeleteMin()
{
    if(IsEmpty())
        throw;
    
    data[1] = std::move(data[currentSize--]);
    PercolateDown(1);
}

    
template <typename Comparable>
void Heap<Comparable>::DeleteMin(Comparable & item)
{
    if(IsEmpty())
        throw;
    
    item = std::move(data[1]);
    data[1] = std::move(data[currentSize--]);
    PercolateDown(1);
}
    
    
#pragma mark Private Methods
// ---------------------------------------- Private Methods

template <typename Comparable>
void Heap<Comparable>::PercolateDown(int hole)
{
    int child;
    Comparable temp = std::move(data[hole]);
    for(;hole*2 <= currentSize; hole = child)
    {
        child = hole*2;
        if(child != currentSize && data[child +1] < data[child])
            child++;
        if(data[child] < temp)
            data[hole] = std::move(data[child]);
        else
            break;
        
    }
    data[hole] = std::move(temp);
}
    
    
} // End fnMath namespace

#endif
