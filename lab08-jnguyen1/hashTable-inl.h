/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#include "hashFunctions.h"

using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> HashTable<K, V>::HashTable() {
    this->buckets = new LinearDictionary<K,V>[10];
    this->size = 0;
    this->capacity = 10;
    this->MaxLoadFactor = 0.75;
}

template <typename K, typename V>
HashTable<K, V>::HashTable(float maxLoadFactor) {
    this->buckets = new LinearDictionary<K,V>[10];
    this->size = 0;
    this->capacity = 10;
    this->MaxLoadFactor = maxLoadFactor;
}

template <typename K, typename V> HashTable<K, V>::~HashTable() {
    delete[] this->buckets;
}

template <typename K, typename V> int HashTable<K, V>::getSize() {
    return this->size;
}

template <typename K, typename V> bool HashTable<K, V>::isEmpty() {
    if (size > 0) {
        return false;
    }
    else {
        return true;
    }
}

template <typename K, typename V> void HashTable<K, V>::insert(K key, V value) {
    int index = hash(key, this->capacity);
    buckets[index].insert(key, value);
    this->size++;
    ensureCapacity();
}

template <typename K, typename V> void HashTable<K, V>::update(K key, V value) {
    int index = hash(key, this->capacity);
    buckets[index].update(key, value);
}

template <typename K, typename V> V HashTable<K, V>::get(K key) {
    int index = hash(key, this->capacity);
    return buckets[index].get(key);
}

template <typename K, typename V> bool HashTable<K, V>::contains(K key) {
    int index = hash(key, this->capacity);
    return buckets[index].contains(key);
}

template <typename K, typename V> void HashTable<K, V>::remove(K key) {
    int index = hash(key, this->capacity);
    buckets[index].remove(key);
    this->size--;
}

template <typename K, typename V> vector<K> HashTable<K, V>::getKeys() {
    vector<K> items;
    for (int i=0; i<this->capacity; i++) {
        if (buckets[i].getSize() > 0) {
            vector<K> tempVect = buckets[i].getKeys();
            for (int j=0; j<tempVect.size(); j++) {
                items.push_back(tempVect[j]);
            }
        }
    }
    return items;
}

template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getItems() {
    vector<pair<K, V>> items;
    for (int i=0; i<this->capacity; i++) {
        if (buckets[i].getSize() > 0) {
            vector<pair<K,V>> tempVect = this->buckets[i].getItems();
            for (int j=0; j<tempVect.size(); j++) {
                items.push_back(tempVect[j]);
            }
        }
    }
    return items;
}

template <typename K, typename V> void HashTable<K,V>::ensureCapacity() {
    if ((float(this->size)/this->capacity) > this->MaxLoadFactor) {
        LinearDictionary<K,V>* newArray = 
                new LinearDictionary<K,V>[this->capacity*2];        
        vector<pair<K, V>> items = this->getItems();
        for (int i=0; i<items.size(); i++) {
            int index = hash(items[i].first, this->capacity*2);
            newArray[index].insert(items[i].first, items[i].second);
        }
        this->capacity = this->capacity*2;
        delete[] this->buckets;
        this->buckets = newArray;
    }
}
