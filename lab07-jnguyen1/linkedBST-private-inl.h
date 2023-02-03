/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <utility>

#include "adts/list.h"
#include "adts/stlList.h"

using std::runtime_error;

template <typename K, typename V>
V LinkedBST<K, V>::findInSubtree(LinkedBSTNode<K, V>* current, K key) {
    if (current == nullptr){
        throw runtime_error("The key cannot be found! :(");
    }
    if (current->getKey() == key) {
        return current->getValue();
    }
    if (key < current->getKey()) {
        return findInSubtree(current->getLeft(), key);
    }
    else {
        return findInSubtree(current->getRight(), key);
    }
}

template <typename K, typename V>
bool LinkedBST<K, V>::containsInSubtree(LinkedBSTNode<K, V>* current, K key) {
    if (current == nullptr) {
        return false;
    }
    if (current->getKey() == key) {
        return true;
    }
    if (key < current->getKey()) {
        return containsInSubtree(current->getLeft(), key);
    }
    else {
        return containsInSubtree(current->getRight(), key);
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::updateInSubtree(LinkedBSTNode<K, V>* current, K key,
                                     V value) {
    if (current == nullptr) {
        throw runtime_error("The key cannot be found! :(");    
    }
    if (current->getKey() == key) {
        current->setValue(value);
        return;
    }
    if (key < current->getKey()) {
        return updateInSubtree(current->getLeft(), key, value);
    }
    else {
        return updateInSubtree(current->getRight(), key, value);
    }
}

template <typename K, typename V>
int LinkedBST<K, V>::getHeightInSubtree(LinkedBSTNode<K, V>* current) {
    int heightR = -1;
    int heightL = -1;

    if (current == nullptr) {
        return -1;
    }
    if (current->getLeft() == nullptr && current->getRight() == nullptr) {
        return 0;
    }
    if (current->getLeft() != nullptr) {
        heightL = getHeightInSubtree(current->getLeft());
    }
    if (current->getRight() != nullptr) {
        heightR = getHeightInSubtree(current->getRight());
    }
    if (heightR > heightL) {
        return heightR + 1;
    }
    else {
        return heightL + 1;
    }
}

template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMinInSubtree(LinkedBSTNode<K, V>* current) {
    if (current->getLeft() == nullptr) {
        pair <K, V> newpair(current->getKey(), current->getValue());
        return newpair;
    }
    else {
        return this->getMinInSubtree(current->getLeft());
    }
}

template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMaxInSubtree(LinkedBSTNode<K, V>* current) {
    if (current->getRight() == nullptr) {
        pair <K, V> newpair(current->getKey(), current->getValue());
        return newpair;
    }
    else {
        return this->getMaxInSubtree(current->getRight());
    }
}

template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::insertInSubtree(LinkedBSTNode<K, V>* current, K key, V value) {
    if (current == nullptr) {
        current = new LinkedBSTNode<K, V>(key, value);
        return current;
    }
    else if (key == current->getKey()) {
        throw runtime_error("No duplicate keys allowed!");
    }
    else if (key < current->getKey()) {
        current->setLeft(insertInSubtree(current->getLeft(), key, value));
        return current;
    }
    else if (key > current->getKey()) {
        current->setRight(insertInSubtree(current->getRight(), key, value));
        return current;
    }
    return current; 
}

template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::removeFromSubtree(LinkedBSTNode<K, V>* current, K key) {
    if (current == nullptr) {
        throw runtime_error("Key not found");
    }
    if (key < current->getKey()) {
        current->setLeft(removeFromSubtree(current->getLeft(), key));
        return current;
    }
    else if (key > current->getKey()) {
        current->setRight(removeFromSubtree(current->getRight(), key));
        return current;
    }
    else {
        if (current->getLeft()==nullptr && current->getRight()==nullptr) {
            delete current;
            current = nullptr;
            return current;
        }
        else if (current->getLeft()!=nullptr && current->getRight()!=nullptr) {
            pair<K, V> pred = getMaxInSubtree(current->getLeft());
            current->setKey(pred.first);
            current->setValue(pred.second);
            current->setLeft(removeFromSubtree(current->getLeft(), pred.first));
            return current;
        }
        else if (current->getLeft()==nullptr) {
            LinkedBSTNode<K, V>* temp = current->getRight();
            delete current;
            return temp;
        }
        else if (current->getRight()==nullptr) {
            LinkedBSTNode<K, V>* temp = current->getLeft();
            delete current;
            return temp;
        }
    }
    return current;
}

template <typename K, typename V>
void LinkedBST<K, V>::deleteSubtree(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        return;
    }
    else {
        deleteSubtree(current->getLeft());
        deleteSubtree(current->getRight());
        delete current;
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPreOrderTraversal(LinkedBSTNode<K, V>* current,
                                             List<pair<K, V>>* list) {
    if (current == nullptr) {
        return;
    }
    else {
        pair<K, V> node(current->getKey(), current->getValue());
        list->insertLast(node);
        buildPreOrderTraversal(current->getLeft(), list);
        buildPreOrderTraversal(current->getRight(), list);
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::buildInOrderTraversal(LinkedBSTNode<K, V>* current,
                                            List<pair<K, V>>* list) {
    if (current == nullptr) {
        return;
    }
    else {
        buildInOrderTraversal(current->getLeft(), list);
        pair<K, V> node(current->getKey(), current->getValue());
        list->insertLast(node);
        buildInOrderTraversal(current->getRight(), list);
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPostOrderTraversal(LinkedBSTNode<K, V>* current,
                                              List<pair<K, V>>* list) {    
    if (current == nullptr) {
        return;
    }
    else {
        buildPostOrderTraversal(current->getLeft(), list);
        buildPostOrderTraversal(current->getRight(), list);
        pair<K, V> node(current->getKey(), current->getValue());
        list->insertLast(node);
    }
}

template <typename K, typename V>
int LinkedBST<K, V>::countNodes(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        return 0;
    } else {
        return this->countNodes(current->getLeft()) +
               this->countNodes(current->getRight()) + 1;
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::verifyKeysBoundedBy(LinkedBSTNode<K, V>* current,
                                          bool minApplies, K minBound,
                                          bool maxApplies, K maxBound) {
    if (minApplies && current->getKey() < minBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a "
                            "right descendent with lesser key");
    }
    if (maxApplies && current->getKey() > maxBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a left "
                            "descendent with greater key");
    }
    if (current->getLeft() != nullptr) {
        verifyKeysBoundedBy(current->getLeft(), minApplies, minBound, true,
                            current->getKey());
    }
    if (current->getRight() != nullptr) {
        verifyKeysBoundedBy(current->getRight(), true, current->getKey(),
                            maxApplies, maxBound);
    }
}
