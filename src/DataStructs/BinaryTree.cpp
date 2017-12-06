//
//  BinaryTree.cpp
//  fnMath
//
//  Created by Steven Novak on 2/2/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//


#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include "BinaryTree.hpp"

namespace fnMath{
    
#pragma mark Constructors
// ---------------------------------------- Constructors
template <typename Comparable>
BinaryTree<Comparable>::BinaryTree()
{
    #ifdef __DEBUG__
        cout << "Generic Constructor\n";
    #endif
    
    root = nullptr;
}

template <typename Comparable>
BinaryTree<Comparable>::BinaryTree(const BinaryTree & rhs)
{
    #ifdef __DEBUG__
        cout << "Copy Constructor\n";
    #endif
    
    root = Clone(rhs.root);
}

template <typename Comparable>
BinaryTree<Comparable>::BinaryTree(BinaryTree && rhs)
{
    #ifdef __DEBUG__
        cout << "Move Constructor\n";
    #endif
    
    root = std::move(rhs.root);
}

template <typename Comparable>
BinaryTree<Comparable>::~BinaryTree()
{
    EmptyList();
}
    
   
#pragma mark Operators
// ---------------------------------------- Operators
template <typename Comparable>
BinaryTree<Comparable> & BinaryTree<Comparable>::operator=(const BinaryTree & rhs)
{
    #ifdef __DEBUG__
        cout << "Copy Assignment\n";
    #endif
    Clone(rhs.root);
    return *this;
}

template <typename Comparable>
BinaryTree<Comparable> & BinaryTree<Comparable>::operator=(BinaryTree && rhs)
{
    #ifdef __DEBUG__
        cout << "Move Assignment\n";
    #endif
    root = std::move(rhs.root);
    return *this;
}
    

#pragma mark Public Methods
// ---------------------------------------- Public Methods
template <typename Comparable>
const Comparable & BinaryTree<Comparable>::findMin() const
{
    return findMin(root)->data;
}

template <typename Comparable>
const Comparable& BinaryTree<Comparable>::findMax() const
{
    return findMax(root)->data;
}

template <typename Comparable>
bool BinaryTree<Comparable>::Contains(const Comparable & datum) const
{
    return contains(datum, root);
}

template <typename Comparable>
bool BinaryTree<Comparable>::IsEmpty() const
{
    if(root == nullptr)
        return true;
    else
        return false;
}

template <typename Comparable>
void BinaryTree<Comparable>::EmptyList()
{
    makeEmpty(root);
}

template <typename Comparable>
void BinaryTree<Comparable>::insert(const Comparable & item)
{
    recursiveInsert(item, root);
}

template <typename Comparable>
void BinaryTree<Comparable>::insert(Comparable && item)
{
    recursiveInsert(item, root);
}

template <typename Comparable>
void BinaryTree<Comparable>::remove(const Comparable & item)
{
    recursiveRemove(item, root);
}

template <typename Comparable>
void BinaryTree<Comparable>::print(ostream & stream)
{
    printBranch(root, stream);
}

#pragma mark Private Methods
// ---------------------------------------- Private Methods

template <typename Comparable>
void BinaryTree<Comparable>::recursiveInsert(const Comparable & item, BinaryNode<Comparable> * & node)
{
    #ifdef __DEBUG__
        cout << item << endl;
    #endif
    
    if(node == nullptr)
        node = new BinaryNode<Comparable>(item, nullptr, nullptr);
    else if(item < node->data)
        recursiveInsert(item, node->leftNode);
    else if(item > node->data)
        recursiveInsert(item, node->rightNode);
    else
        return; // Already Exists
    
}

template <typename Comparable>
void BinaryTree<Comparable>::recursiveInsert(Comparable && item, BinaryNode<Comparable>* & node)
{
    #ifdef __DEBUG__
        cout << item << endl;
    #endif
    
    if(node == nullptr)
        node = BinaryNode<Comparable>(std::move(item), nullptr, nullptr);
    else if(item < node->data)
        recursiveInsert(std::move(item), node->leftNode);
    else if(item > node->data)
        recursiveInsert(std::move(item), node->rightNode);
    else
        return; // Already Exists
}
    
template <typename Comparable>
void BinaryTree<Comparable>::recursiveRemove(const Comparable & Item, BinaryNode<Comparable>* & node)
{
    
    #ifdef __DEBUG__
        cout << "Looking at branch "<< node->item << endl;
    #endif

    
    if(node == nullptr)
        return;
    
    if(Item < node->data)
        recursiveRemove(Item, node->leftNode);
    else if(Item > node->data)
        recursiveRemove(Item, node->rightNode);
    else if (node->rightNode != nullptr && node->leftNode != nullptr)
    {
        #ifdef __DEBUG__
                cout << "Node has 2 children " << endl;
        #endif

        node->data = findMin(node->rightNode)->data;
        recursiveRemove(node->data, node->rightNode);
    }
    else
    {
        #ifdef __DEBUG__
                cout << "Looking at branch "<< node->item << endl;
        #endif

        BinaryNode<Comparable> *oldNode = node;
        if(node->leftNode != nullptr)
            node = node->leftNode;
        else
            node = node->rightNode;
        delete oldNode;
    }
    
}
    
template <typename Comparable>
BinaryNode<Comparable>* BinaryTree<Comparable>::findMin(BinaryNode<Comparable>* node) const
{    
    if(node == nullptr)
        return nullptr;
    if (node->leftNode == nullptr)
        return node;
    
    return (findMin(node->leftNode));
}
    
template <typename Comparable>
BinaryNode<Comparable>* BinaryTree<Comparable>::findMax(BinaryNode<Comparable>* node) const
{
    if(node != nullptr)
        while (node->rightNode != nullptr)
            node = node->rightNode;
    return node;
}
    
template <typename Comparable>
bool BinaryTree<Comparable>::contains(const Comparable& item, BinaryNode<Comparable>* node)
{
    if(node == nullptr)
        return false;
    else if(item < node->data)
        return contains(item, node->leftNode);
    else if(item > node->data)
        return contains(item, node->rightNode);
    else
        return true;
}

template <typename Comparable>
void BinaryTree<Comparable>::makeEmpty(BinaryNode<Comparable>* & node)
{
    if(node != nullptr)
    {
        makeEmpty(node->leftNode);
        makeEmpty(node->rightNode);
        delete node;
    }
    node = nullptr;
}
    
template <typename Comparable>
void BinaryTree<Comparable>::printBranch(BinaryNode<Comparable>* node, ostream & out) const
{
    if(node != nullptr)
    {
        printBranch(node->leftNode, out);
        out << node->data << endl;
        printBranch(node->rightNode, out);
    }
}

template <typename Comparable>
BinaryNode<Comparable>* BinaryTree<Comparable>::Clone(BinaryNode<Comparable>* node) const
{
    if(node == nullptr)
        return nullptr;
    else
        return new BinaryNode<Comparable>{node->data, Clone(node->leftNode), Clone(node->rightNode) };
}
    
} // End fnMath Namespace

#endif

