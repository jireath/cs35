/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include "keywordSearcher.h"

#include <fstream>
#include <stdexcept>

using namespace std;

KeywordSearcher::KeywordSearcher() {
    this->wordTable = new HashTable<string,HashTable<int,int>*>;
}

KeywordSearcher::~KeywordSearcher() {
    vector<string> words = this->wordTable->getKeys();

    for (int i = 0; i < words.size(); i++) {
        string deleteWords = words[i];
        delete this->wordTable->get(deleteWords);
    }    
    delete this->wordTable;
}

void KeywordSearcher::loadWords(string filename) {
    int pageNumber = 0;
    int occurences;
    string word;

    ifstream myFile;
    myFile.open(filename);
    if(!myFile.is_open()) {
        throw runtime_error("file has failed to open.");
    }

    myFile >> word;
    while(!myFile.eof()) {
        if(word == "$$@@$$PAGE:") {
            myFile >> word;
            pageNumber = stoi(word);
        }
        else if (this->wordTable->contains(word) == false){
            HashTable<int,int>* pageTable = new HashTable<int,int>;
            pageTable->insert(pageNumber, 1);
            this->wordTable->insert(word, pageTable);
        }
        else if (this->wordTable->contains(word) == true) {
            HashTable<int,int>* pageTable = this->wordTable->get(word);
            if (pageTable->contains(pageNumber) == true) {
                occurences = pageTable->get(pageNumber);
                pageTable->update(pageNumber, occurences + 1);
            }
            else {
                pageTable->insert(pageNumber, 1);
            }
        }
        myFile >> word;
    }
    myFile.close();
}

vector<pair<int, int>> KeywordSearcher::search(string word) {
    vector<pair<int, int>> items;

    if(!this->wordTable->contains(word)) {
        return items;
    }

    items = this->wordTable->get(word)->getItems();

    //swapping vector pairs
    int i, temp1, temp2;
    vector<pair<int, int>> items2;
    for (i = 0; i < items.size(); i++) {
        temp1 = items[i].first;
        temp2 = items[i].second;
        pair<int,int> changedPair;
        changedPair.first = temp2;
        changedPair.second = temp1;
        items2.push_back(changedPair);
    }

    //creation of max priority queue
    STLMaxPriorityQueue<int,int> prioQueue(items2);

    vector<pair<int, int>> topTen;
    int occurences, pageNumber;

    //getting top ten
    if (prioQueue.getSize() > 10) {
        for (i = 0; i < 10; i++) {
            occurences = prioQueue.peekPriority();
            pageNumber = prioQueue.remove();
            pair<int, int> pageOccurence;
            pageOccurence.first = pageNumber;
            pageOccurence.second = occurences;
            topTen.push_back(pageOccurence);
        }
    }
    else {
        while (!prioQueue.isEmpty()) {
            occurences = prioQueue.peekPriority();
            pageNumber = prioQueue.remove();
            pair<int, int> pageOccurence;
            pageOccurence.first = pageNumber;
            pageOccurence.second = occurences;
            topTen.push_back(pageOccurence);
        }
    }
    return topTen;
}
