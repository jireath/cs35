/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#include <string>

#include "inroadsGame.h"
#include "graphAlgorithms.h"
#include "adjacencyListUndirectedGraph.h"

using namespace std;

InroadsGame::InroadsGame(Graph<string, bool, int>* graph) {
  this->inroadsGraph = graph;
  this->score = 0;
  this->scoreGraph = new AdjacencyListUndirectedGraph<string, bool, int>;
  vector<string> inroadsVertices = graph->getVertices();
  for (int i=0; i<inroadsVertices.size(); i++) {
    this->scoreGraph->insertVertex(inroadsVertices[i]);
  }
}

InroadsGame::~InroadsGame() {
  delete scoreGraph;
}

string InroadsGame::calculateScore() {
  
  int libScore = libraryScore();
  int stoScore = storeScore();
  int medicScore = medScore();
  
  int turnScore = libScore + stoScore + medicScore;

  this->score = this->score + turnScore;

  string message;

  message = "Your score this turn:\n  +" +to_string(libScore)+ 
          " from the library\n  +" + to_string(stoScore)+ " from stores\n  +"
          + to_string(medicScore) + " from medical access\n" +
          "Total points this turn: " + to_string(turnScore);

  return message;
}

int InroadsGame::getScore() {
  return this->score;
}

bool InroadsGame::improveRoad(pair<string, string> road) {
  
  Edge<string, bool, int> oldEdge = this->inroadsGraph->
                                getEdge(road.first, road.second);

  if (oldEdge.getLabel() == true) {
    return true;
  }
  this->inroadsGraph->removeEdge(road.first, road.second);
  this->inroadsGraph->insertEdge
                (road.first, road.second, true, oldEdge.getWeight());
  
  this->scoreGraph->insertEdge(road.first, road.second, 
                                        true, oldEdge.getWeight());
  return false;
}

int InroadsGame::libraryScore() {
  vector<string> vertices = this->scoreGraph->getVertices();

  int libScore = 0;
  if (this->scoreGraph->containsVertex("L")) {
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices[i].rfind("R", 0) == 0) {
        if (reachableDFS(string(vertices[i]), string("L"), this->scoreGraph)) {
          libScore+=15;
        }
      }
    }
  }
  return libScore;
}

int InroadsGame::storeScore() {
  vector<string> vertices = this->scoreGraph->getVertices();

  int storeScore = 0;
  for(int i = 0; i < vertices.size(); i++) {
    if (vertices[i].rfind("S", 0) == 0) {
      for(int j = 0; j < vertices.size(); j++) {
        if (vertices[j].rfind("R", 0) == 0) {
          if (reachableDFS(string(vertices[j]),
               string(vertices[i]), this->scoreGraph)) {
            vector<string> pathSize = shortestLengthPathBFS
                    (string(vertices[j]),string(vertices[i]),this->scoreGraph);
            if (pathSize.size() < 4) {
              storeScore+=10;
            }
          }
        }
      }
    }
  }
  return storeScore;
}

int InroadsGame::medScore() {
  vector<string> vertices = this->scoreGraph->getVertices();

  int medScore = 0;
  for(int i = 0; i < vertices.size(); i++) {
    if (vertices[i].rfind("M", 0) == 0) {
      Dictionary<string, int>* ssspHospital = 
          singleSourceShortestPath(vertices[i], this->scoreGraph);
      for(int j = 0; j < vertices.size(); j++) {
        if (vertices[j].rfind("R", 0) == 0) {
          if(reachableDFS(string(vertices[j]),
                   string(vertices[i]), this->scoreGraph)) {
            int path = ssspHospital->get(vertices[j]);
            medScore += (420/path);
          }
        }
      }
      delete ssspHospital;
    }
  }
  return medScore;
}


