//
// Created by user on 25.05.2023.
//

#ifndef HEXXAGON_MOVE_H
#define HEXXAGON_MOVE_H
#include "Board.h"
#include "Positions.h"

class Move {
/**
 * \brief This function is used to make moves on the board
 * @param board is used to get access to board functions(setPieceAtPositions, getPieceAtPosition)
 * @param startPos is a starting position for move
 * @param endPos is a ending coordinates for move
 */
public: void makeMove(Board& board, const Positions& starsPos,const Positions& endPos);
};


#endif //HEXXAGON_MOVE_H
