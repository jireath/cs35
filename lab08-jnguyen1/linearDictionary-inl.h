/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <iostream>
#include <utility>
#include <vector>
#include "linearDictionary.h"


template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {
}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {
}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    return vect.size();
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
    if (vect.size()>0) {
        return false;
    }
    else {
        return true;
    }
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
    for (int i=0; i<vect.size(); i++) {
        if (vect[i].first==key) {
            throw std::runtime_error("Key is a duplicate >:(");
        }
    }
    vect.push_back(pair<K,V>(key, value));
}

template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
    for (int i = 0; i<vect.size(); i++) {
        if (vect[i].first == key) {
            vect[i].second = value;
            return;
        }
    }
    throw std::runtime_error("Key cannot be found :(!");
}

template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
    for (int i = 0; i<vect.size(); i++) {
        if (vect[i].first == key) {
            return vect[i].second;
        }
    }
    throw std::runtime_error("Key cannot be found :(");
}


template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
    for (int i=0; i < vect.size(); i++) {
        if (vect[i].first == key) {
            return true;
        }
    }
    return false;
}

template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
    for (int i=0; i < vect.size(); i++) {
        if (vect[i].first == key) {
            vect.erase(vect.begin()+i, vect.begin()+i+1);
            return;
        }
    }
    throw std::runtime_error("Key cannot be found");
}   

template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
    vector<K> keyVect;
    for (int i=0; i < vect.size(); i++) {
        keyVect.push_back(vect[i].first);
    }
    return keyVect;
    }

template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
    vector<pair<K,V>> items;
    for (int i=0; i < vect.size(); i++) {
        items.push_back(vect[i]);
    }
    return items;
}
