/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <vector>
#include <algorithm>
#include "adts/stlQueue.h"
#include "adts/stlStack.h"
#include "adts/stlMinPriorityQueue.h"
#include "adts/stlHashTable.h"

using namespace std;

template <typename V, typename E, typename W>
bool reachableDFS(V src, V dest, Graph<V, E, W>* g) {
    STLStack<V> stack;
    STLHashTable<V,V> previous;
    stack.push(src);
    previous.insert(src, src);

    while (!stack.isEmpty()) {
        V current = stack.pop();
        if (current == dest) {
            return true;
        }
        else {
            vector<V> neighbors = g->getNeighbors(current);
            for (V neighbor : neighbors) {
                if (!previous.contains(neighbor)) {
                    stack.push(neighbor);
                    previous.insert(neighbor, current);
                }
            }
        }
    }
    return false;
}

template <typename V, typename E, typename W>
vector<V> shortestLengthPathBFS(V src, V dest, Graph<V, E, W>* g) {
    vector<V> path;
    STLQueue<V> queue;
    STLHashTable<V,V> previous;
    queue.enqueue(src);
    previous.insert(src, src);
    
    while (!queue.isEmpty()) {
        V current = queue.dequeue();
        if (current == dest) {
            V pathVert = dest;
            while (pathVert != src) { 
                path.push_back(pathVert);
                pathVert = previous.get(pathVert);
            }
            path.push_back(pathVert);
            reverse(path.begin(), path.end());
            return path;
        }
        else {
            vector<V> neighbors = g->getNeighbors(current);
            for (V neighbor : neighbors) {
                if (!previous.contains(neighbor)){
                    queue.enqueue(neighbor);
                    previous.insert(neighbor, current);
                }
            }
        }
    }
    throw runtime_error("Path is empty!");
}

template <typename V, typename E, typename W>
Dictionary<V, W>* singleSourceShortestPath(V src, Graph<V, E, W>* g) {

    STLMinPriorityQueue<int, V> exploration;
    exploration.insert(0, src);
    Dictionary<V, W>* costs = new STLHashTable<V, W>;
    costs->insert(src, 0);

    while(!exploration.isEmpty()) {
        V current = exploration.remove();
        int currentCost = costs->get(current);
        vector<Edge<V, E, W>> edges = g->getOutgoingEdges(current);
        for (Edge<V, E, W> edge : edges) {
            V neighbor = edge.getDestination();
            int newCost = currentCost + edge.getWeight();
            if (!costs->contains(neighbor)) {
                costs->insert(neighbor, newCost);
                exploration.insert(newCost, neighbor);
            }
            else if (costs->get(neighbor) > newCost) {
                costs->update(neighbor, newCost);
                exploration.insert(newCost, neighbor);
            }
        } 
    }
    return costs;
}
