//
// Created by user on 26.05.2023.
//

#ifndef HEXXAGON_AI_H
#define HEXXAGON_AI_H


#include <vector>
#include "Positions.h"
#include "Board.h"
#include "Logic.h"

class AI {

    /**
     * \brief This function finds all possible moves for AI
     * This function gets all Positions and finds all possible moves for AI( whose pieces are marked as W
     * @param board is used to get all positions
     * @param logic is used to check whether chosen move is valid
     * @param piece is used as a parameter for validation function
     * @return The vector which consists of pair of positions(starting position and ending)
     */
    public: std::vector<std::pair<Positions, Positions>>getAllPossibleMoves(Board& board, Logic& logic,const std::string& piece);
    /**
     * \brief This function calculate how many pieces can be captured in chosen move
     * This function calculate value of move, by counting how many pieces can be obtained
     * (if move is short, then we can get at least one piece), also it will find amount of pieces
     * that AI can get by capturing closest enemy pieces
     * @param board is used to get access to board function which returns piece on position
     * @param startPos is a starting position
     * @param endPos is a ending position
     * @return amount of pieces that can be obtained in the move
     */
    public: int amountOfPieces(Board& board,const Positions& startPos, const Positions& endPos);
    /**
     * \brief This function will return positions of best possible move
     * This functions will iterate through all Possible moves(getAllPossibleMoves) and calculate which is best(amountOfPieces)
     * @param board is used to get access to board function(getPieceAtPosition) and to pass it to other functions as argument
     * @param logic is passed as argument to other functions
     * @param piece is passed as argument to other functions
     * @return the pair of coordinates(starting and ending) that represents the best possible move
     */
    public: std::pair<Positions, Positions> getMoveCoordinates( Board& board, Logic& logic, const std::string& piece);
};


#endif //HEXXAGON_AI_H
