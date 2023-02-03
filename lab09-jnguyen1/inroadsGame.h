/*
  Copyright (c) 2021
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, S. Caplan, A. Danner, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2021
  CPSC 035: Data Structures and Algorithms
*/

#pragma once
#include "inroadsGUI.h"
using namespace std;

/**
 * An instance of this class represents a single game of Inroads.  An object of
 * type InroadsGame does not represent the user interface, but does represent
 * the idea of a game of Inroads, including the state of the board and all of
 * the information pertaining to the player.  It also includes the logic for
 * making moves in the game and enforces the game's rules.
 */
class InroadsGame {
  public:
    /**
     * Creates a new InroadsGame. This takes an undirected graph with
     * labeled edges denoting if the edge is paved or unpaved and intializes
     * it.
     * @param graph a pointer pointing to the game's graph
     */
    InroadsGame(Graph<string, bool, int>* graph);

    /**
     * Destroys the InroadsGame. This action deletes the graph that is used
     * while playing the game.
     */
    ~InroadsGame();

    /**
     * Updates the score by adding up the points from the turn. It does this by
     * calling the private methods: libraryScore, storeScore, and medScore on
     * scoreGraph. It sums the three scores and updates our private score 
     * variable.
     * @return a string message that describes how points were earned in 
     * this turn.
     */
    string calculateScore();

    /**
    * This function returns the current score of the game.
    * @return the score
    */
    int getScore();

    /**
     * Improves the road/edge that the user chose in main through getNextMove.
     * This updates the inroadsGraph member variable, marking the edge as 
     * improved, and adds the improved edge to the scoreGraph member variable
     * @param road a pair of strings corresponding to the two nodes of the
     * graph that the road connects.
     * @return true if the edge has already been improved, false otherwise.
     */
    bool improveRoad(pair<string, string> road);

  private:
    Graph<string, bool, int>* inroadsGraph;
    Graph<string, bool, int>* scoreGraph;
    int score;

    /**
     * Calculates the sum of points gained through residential locations
     * being connected to libraries, using graphAlgorithms.
     * @return the sum of the points earned from libraries.
     */
    int libraryScore();
    /**
     * Calculates the sum of points gained through residential locations
     * being connected to stores, using graphAlgorithms.    
     * @return the sum of the points earned from stores.
     */
    int storeScore();
    /**
     * Calculates the sum of points gained through residential locations
     * being connected to medical locations, using graphAlgorithms.   
     * @return the sum of the points earned from medical centers.  
     */
    int medScore();
 
    // You can safely ignore the following code.  This eliminates some default
    // class routines, preventing you from using them accidentally.
    // Specifically, we are disabling the use of the copy constructor and the
    // copy assignment operator.  You can read more here:
    //   http://www.cplusplus.com/articles/y8hv0pDG/
  private:
    InroadsGame(const InroadsGame& other) = delete;
    InroadsGame& operator=(const InroadsGame& other) = delete;
};
