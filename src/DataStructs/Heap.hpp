//
//  Heap.hpp
//  fnMath
//
//  Created by Steven Novak on 2/16/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//
//  Comparable objects should overload < and >
//
//  Routines inspired by
//  "Data Structures and Algorithm Analysis in C++"
//  by Mark Allen Weiss
//
//

#ifndef Heap_hpp
#define Heap_hpp

#include <vector>

using namespace std;

namespace fnMath {
    
template <typename Comparable>
class Heap
{
public:
    // -------------------- Constructors
    explicit Heap(int Capacity = 100);
    explicit Heap(const vector<Comparable> & items);
    
    // -------------------- Accessors
    bool IsEmpty() const;
    const Comparable & findMin() const;
    
    // -------------------- Public Methods
    void Insert(const Comparable & item);
    void Insert(Comparable && item);
    void DeleteMin();
    void DeleteMin(Comparable & item);
    void MakeEmpty();
    
    
private:
    // -------------------- Private Members
    int currentSize;
    vector<Comparable> data;
    
    // -------------------- Private Methods
    void BuildHeap();
    void PercolateDown(int hole);
    
};
    
    
} // End fnMath namespace


#endif /* Heap_hpp */
