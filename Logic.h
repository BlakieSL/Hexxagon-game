//
// Created by user on 25.05.2023.
//

#ifndef HEXXAGON_LOGIC_H
#define HEXXAGON_LOGIC_H


#include "Board.h"
#include "Positions.h"
class Logic {
    /**
     * \brief This function check whether move is legal
     * @param startPos is used as a starting coordinates
     * @param endPos is used as an ending coordinates(to which it should move)
     * @param board is used to get an array(board)
     * @param piece is used to check whether piece on a staring coordinate is of the current player
     * @return true if move is legal, false if is not legal
     */
public: bool isValidMove(const Positions& startPos,const Positions& endPos, Board& board, const std::string& piece);
};


#endif //HEXXAGON_LOGIC_H
