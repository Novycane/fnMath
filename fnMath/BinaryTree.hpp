//
//  BinaryTree.hpp
//  fnMath
//
//  Created by Steven Novak on 2/2/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//
//  Data structure representing a binary tree
//
//  Comparable objects should overload < and >
//
//  Routines inspired by
//  "Data Structures and Algorithm Analysis in C++"
//  by Mark Allen Weiss
//
//


#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>

namespace fnMath{

using namespace std;

template <typename Comparable>
class BinaryNode
{
public:
    Comparable data;
    BinaryNode* leftNode;
    BinaryNode* rightNode;
    
    BinaryNode(const Comparable & theData, BinaryNode* Left, BinaryNode* Right): data(theData), leftNode(Left), rightNode(Right) {};
    BinaryNode(Comparable && theData, BinaryNode* Left, BinaryNode* Right): data(std::move(theData)), leftNode(Left), rightNode(Right) {};
}; // end

    
template <typename Comparable>
class BinaryTree
{
public:
    // -------------------- Constructors
    BinaryTree();
    ~BinaryTree();
    BinaryTree(const BinaryTree & rhs);
    BinaryTree(BinaryTree && rhs);

    // -------------------- Operators
    BinaryTree<Comparable> & operator=(const BinaryTree<Comparable> & rhs);
    BinaryTree<Comparable> & operator=(BinaryTree<Comparable> && rhs);
    
    // -------------------- Methods
    const Comparable& findMin() const;
    const Comparable& findMax() const;
    bool Contains(const Comparable & datum) const;
    bool IsEmpty() const;

    void EmptyList();
    void insert(const Comparable & item);
    void insert(Comparable && item);
    void remove(const Comparable & item);
    void print(ostream & stream = cout);

private:
    
    void recursiveInsert(const Comparable & Item, BinaryNode<Comparable>* & node);
    void recursiveInsert(Comparable && Item, BinaryNode<Comparable>* & node);
    void recursiveRemove(const Comparable & Item, BinaryNode<Comparable>* & node);
    BinaryNode<Comparable>* findMin(BinaryNode<Comparable>* node) const;
    BinaryNode<Comparable>* findMax(BinaryNode<Comparable>* node) const;
    bool contains(const Comparable& item, BinaryNode<Comparable>* node);
    void makeEmpty(BinaryNode<Comparable>* & node);
    void printBranch(BinaryNode<Comparable>* node, ostream & out) const;
    BinaryNode<Comparable>* Clone(BinaryNode<Comparable>* node) const;

protected:
    BinaryNode<Comparable>* root;

};
    
    
} // End namespace fnMath
    
#endif /* BinaryTree_hpp */
