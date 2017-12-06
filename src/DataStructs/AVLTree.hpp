//
//  AVLTree.hpp
//  fnMath
//
//  Created by Steven Novak on 2/15/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//
//  Data structure representing a balenced binary tree (AVL)
//
//  Comparable objects should overload < and >
//
//  Routines inspired by
//  "Data Structures and Algorithm Analysis in C++"
//  by Mark Allen Weiss
//
//


#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <iostream>

namespace fnMath{
    
using namespace std;

template <typename Comparable>
class AVLNode
{
public:
    Comparable data;
    AVLNode* leftNode;
    AVLNode* rightNode;
    int height;
    
    AVLNode(const Comparable & theData, AVLNode* Left, AVLNode* Right, int Height=0): data(theData), leftNode(Left), rightNode(Right), height(Height) {};
    AVLNode(Comparable && theData, AVLNode* Left, AVLNode* Right, int Height=0): data(std::move(theData)), leftNode(Left), rightNode(Right), height(Height) {};
}; // end


template <typename Comparable>
class AVLTree
{
public:
    // -------------------- Constructors
    AVLTree();
    ~AVLTree();
    AVLTree(const AVLTree & rhs);
    AVLTree(AVLTree && rhs);
    
    // -------------------- Operators
    AVLTree<Comparable> & operator=(const AVLTree<Comparable> & rhs);
    AVLTree<Comparable> & operator=(AVLTree<Comparable> && rhs);
    
    // -------------------- Methods
    const Comparable& findMin() const;
    const Comparable& findMax() const;
    bool Contains(const Comparable & datum) const;
    bool IsEmpty() const;
    int Height(AVLNode<Comparable> * node);
    
    void EmptyList();
    void insert(const Comparable & item);
    void insert(Comparable && item);
    void remove(const Comparable & item);
    void print(ostream & stream = cout);
    
private:
    // -------------------- Private Methods
    AVLNode<Comparable>* root;
    AVLNode<Comparable>* findMin(AVLNode<Comparable>* node) const;
    AVLNode<Comparable>* findMax(AVLNode<Comparable>* node) const;
    bool contains(const Comparable& item, AVLNode<Comparable>* node);
    void makeEmpty(AVLNode<Comparable>* & node);
    void printBranch(AVLNode<Comparable>* node, ostream & out) const;
    AVLNode<Comparable>* Clone(AVLNode<Comparable>* node) const;
    void Balance(AVLNode<Comparable> * & node);
    void RotateLeft(AVLNode<Comparable> * & node);
    void DoubleLeft(AVLNode<Comparable> * & node);
    void RotateRight(AVLNode<Comparable> * & node);
    void DoubleRight(AVLNode<Comparable> * & node);
    
protected:
    // -------------------- Protected Members
    void virtual recursiveInsert(const Comparable & Item, AVLNode<Comparable>* & node);
    void virtual recursiveInsert(Comparable && Item, AVLNode<Comparable>* & node);
    void virtual recursiveRemove(const Comparable & Item, AVLNode<Comparable>* & node);
    
};
    
    
} // End namespace fnMath

#endif /* AVLTree_hpp */
