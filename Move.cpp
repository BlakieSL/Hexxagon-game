//
// Created by user on 25.05.2023.
//

#include <iostream>
#include "Move.h"

void Move::makeMove( Board& board, const Positions& starsPos,const Positions& endPos) {
    std::string piece =  board.getPieceAtPosition(starsPos);
    int dx = abs(starsPos.getX()-endPos.getX());
    int dy = abs(starsPos.getY()-endPos.getY());

    if(dx>2 || dy > 1){
        board.setPieceAtPostion(endPos, piece);
        board.setPieceAtPostion(starsPos, "0");
    }else {
        board.setPieceAtPostion(endPos, piece);
        board.setPieceAtPostion(starsPos, piece);
    }
    Positions neighbors[6] = {
            Positions(endPos.getX()-2,endPos.getY()),
            Positions(endPos.getX()+2, endPos.getY()),
            Positions(endPos.getX()-1, endPos.getY()-1),
            Positions(endPos.getX()-1,endPos.getY()+1),
            Positions(endPos.getX()+1, endPos.getY()-1),
            Positions(endPos.getX()+1, endPos.getY()+1)
    };
    for(const auto& pos : neighbors){
        if(board.isValidPos(pos)) {
            std::string neighPiece = board.getPieceAtPosition(pos);
            if (neighPiece == board.getOppositePiece(piece)) {
                board.setPieceAtPostion(pos, piece);
            }
        }
    }
}
