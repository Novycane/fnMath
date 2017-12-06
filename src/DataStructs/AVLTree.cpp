//
//  AVLTree.cpp
//  fnMath
//
//  Created by Steven Novak on 2/15/17.
//  Copyright © 2017 Steven Novak. All rights reserved.
//


#ifndef AVLTREE_CPP
#define AVLTREE_CPP

#include "AVLTree.hpp"

namespace fnMath{
    
#pragma mark Constructors
// ---------------------------------------- Constructors
template <typename Comparable>
AVLTree<Comparable>::AVLTree()
{
    root = nullptr;
}

template <typename Comparable>
AVLTree<Comparable>::AVLTree(const AVLTree & rhs)
{
    root = Clone(rhs.root);
}

template <typename Comparable>
AVLTree<Comparable>::AVLTree(AVLTree && rhs)
{
    root = std::move(rhs.root);
}

template <typename Comparable>
AVLTree<Comparable>::~AVLTree()
{
    EmptyList();
}


#pragma mark Operators
// ---------------------------------------- Operators
template <typename Comparable>
AVLTree<Comparable> & AVLTree<Comparable>::operator=(const AVLTree & rhs)
{
    Clone(rhs.root);
    return *this;
}

template <typename Comparable>
AVLTree<Comparable> & AVLTree<Comparable>::operator=(AVLTree && rhs)
{
    root = std::move(rhs.root);
    return *this;
}


#pragma mark Public Methods
// ---------------------------------------- Public Methods
template <typename Comparable>
const Comparable & AVLTree<Comparable>::findMin() const
{
    return findMin(root)->data;
}

template <typename Comparable>
const Comparable& AVLTree<Comparable>::findMax() const
{
    return findMax(root)->data;
}

template <typename Comparable>
bool AVLTree<Comparable>::Contains(const Comparable & datum) const
{
    return contains(datum, root);
}

template <typename Comparable>
bool AVLTree<Comparable>::IsEmpty() const
{
    if(root == nullptr)
        return true;
    else
        return false;
}

template <typename Comparable>
void AVLTree<Comparable>::EmptyList()
{
    makeEmpty(root);
}

template <typename Comparable>
void AVLTree<Comparable>::insert(const Comparable & item)
{
    recursiveInsert(item, root);
}

template <typename Comparable>
void AVLTree<Comparable>::insert(Comparable && item)
{
    recursiveInsert(item, root);
}

template <typename Comparable>
void AVLTree<Comparable>::remove(const Comparable & item)
{
    recursiveRemove(item, root);
}

template <typename Comparable>
void AVLTree<Comparable>::print(ostream & stream)
{
    printBranch(root, stream);
}

template <typename Comparable>
int AVLTree<Comparable>::Height(AVLNode<Comparable> * node)
{
    if(node == nullptr)
        return -1;
    else
        return node->height;
}

#pragma mark Private Methods
// ---------------------------------------- Private Methods

template <typename Comparable>
void AVLTree<Comparable>::recursiveInsert(const Comparable & item, AVLNode<Comparable> * & node)
{
    if(node == nullptr)
        node = new AVLNode<Comparable>(item, nullptr, nullptr);
    else if(item < node->data)
        recursiveInsert(item, node->leftNode);
    else if(item > node->data)
        recursiveInsert(item, node->rightNode);
    
    Balance(node);
}

template <typename Comparable>
void AVLTree<Comparable>::recursiveInsert(Comparable && item, AVLNode<Comparable>* & node)
{
    if(node == nullptr)
        node = new AVLNode<Comparable>(std::move(item), nullptr, nullptr);
    else if(item < node->data)
        recursiveInsert(std::move(item), node->leftNode);
    else if(item > node->data)
        recursiveInsert(std::move(item), node->rightNode);

    Balance(node);
}

template <typename Comparable>
void AVLTree<Comparable>::recursiveRemove(const Comparable & Item, AVLNode<Comparable>* & node)
{
    if(node == nullptr)
        return;
    
    if(Item < node->data)
        recursiveRemove(Item, node->leftNode);
    else if(Item > node->data)
        recursiveRemove(Item, node->rightNode);
    else if (node->rightNode != nullptr && node->leftNode != nullptr)
    {
        node->data = findMin(node->rightNode)->data;
        recursiveRemove(node->data, node->rightNode);
    }
    else
    {
        AVLNode<Comparable> *oldNode = node;
        if(node->leftNode != nullptr)
            node = node->leftNode;
        else
            node = node->rightNode;
        delete oldNode;
    }
    Balance(node);
}

template <typename Comparable>
AVLNode<Comparable>* AVLTree<Comparable>::findMin(AVLNode<Comparable>* node) const
{
    if(node == nullptr)
        return nullptr;
    if (node->leftNode == nullptr)
        return node;
    
    return (findMin(node->leftNode));
}

template <typename Comparable>
AVLNode<Comparable>* AVLTree<Comparable>::findMax(AVLNode<Comparable>* node) const
{
    if(node != nullptr)
        while (node->rightNode != nullptr)
            node = node->rightNode;
    return node;
}

template <typename Comparable>
bool AVLTree<Comparable>::contains(const Comparable& item, AVLNode<Comparable>* node)
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
void AVLTree<Comparable>::makeEmpty(AVLNode<Comparable>* & node)
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
void AVLTree<Comparable>::printBranch(AVLNode<Comparable>* node, ostream & out) const
{
    if(node != nullptr)
    {
        printBranch(node->leftNode, out);
        out << node->data << endl;
        printBranch(node->rightNode, out);
    }
    /*
    if(node != nullptr)
    {
        printBranch(node->leftNode, out << "-");
        out << node->data << "\t\t" << node->height << endl;
        printBranch(node->rightNode, out << "-");
    }
    */
}

template <typename Comparable>
AVLNode<Comparable>* AVLTree<Comparable>::Clone(AVLNode<Comparable>* node) const
{
    if(node == nullptr)
        return nullptr;
    else
        return new AVLNode<Comparable>{node->data, Clone(node->leftNode), Clone(node->rightNode) };
}
    
template <typename Comparable>
void AVLTree<Comparable>::Balance(AVLNode<Comparable> * & node)
{
    if(node == nullptr)
        return;
    
    if(Height(node->leftNode) - Height(node->rightNode) > 1)
    {
        if(Height(node->leftNode->leftNode) >= Height(node->leftNode->rightNode))
            RotateLeft(node);
        else
            DoubleLeft(node);
    }
    else
        if(Height(node->rightNode) - Height(node->leftNode) > 1)
        {
            if(Height(node->rightNode->rightNode) >= Height(node->rightNode->leftNode))
                RotateRight(node);
            else
                DoubleRight(node);
        }
    
    node->height = max(Height(node->rightNode), Height(node->leftNode)) + 1;
}


template <typename Comparable>
void AVLTree<Comparable>::RotateLeft(AVLNode<Comparable> * & node)
{
    AVLNode<Comparable> * temp = node->leftNode;
    node->leftNode = temp->rightNode;
    temp->rightNode = node;
    node->height = max(Height(node->leftNode), Height(node->rightNode)) + 1;
    temp->height = max(Height(temp->leftNode), node->height) + 1;
    node = temp;
}


template <typename Comparable>
void AVLTree<Comparable>::DoubleLeft(AVLNode<Comparable> * & node)
{
    RotateRight(node->leftNode);
    RotateLeft(node);
}


template <typename Comparable>
void AVLTree<Comparable>::RotateRight(AVLNode<Comparable> * & node)
{
    AVLNode<Comparable> * temp = node->rightNode;
    node->rightNode = temp->leftNode;
    temp->leftNode = node;
    node->height = max(Height(node->rightNode), Height(node->leftNode)) + 1;
    temp->height = max(Height(temp->rightNode), node->height) + 1;
    node = temp;
}


template <typename Comparable>
void AVLTree<Comparable>::DoubleRight(AVLNode<Comparable> * & node)
{
    RotateLeft(node->rightNode);
    RotateRight(node);
}
    
    
    
} // End fnMath Namespace

#endif

