//
// Created by user on 26.05.2023.
//

#include <string>
#include "AI.h"
#include "Board.h"
#include "Logic.h"

std::vector<std::pair<Positions, Positions>> AI::getAllPossibleMoves(Board& board, Logic& logic, const std::string& piece) {
    std::vector<std::pair<Positions, Positions>> possibleMoves;
    std::vector<Positions> allPos = board.getAllPositions();
    for(const auto& startPos : allPos){
        if(board.getPieceAtPosition(startPos)!="W"){
            continue;
        }
        for(const auto& endPos : allPos){
            if(logic.isValidMove(startPos, endPos,board, piece)){
                possibleMoves.emplace_back(startPos, endPos);
            }
        }
    }
    return possibleMoves;
}
int AI::amountOfPieces( Board& board,const Positions &startPos, const Positions &endPos) {
    int counter=0;
    std::string piece = board.getPieceAtPosition(startPos);
    int dx = abs(startPos.getX()-endPos.getX());
    int dy = abs(startPos.getY()-endPos.getY());
    if((dx+dy)<=4){
        counter++;
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
        std::string  neighPiece = board.getPieceAtPosition(pos);
        if(neighPiece == "R"){
            counter++;
        }
    }
    return counter;
}
std::pair<Positions, Positions> AI::getMoveCoordinates( Board& board, Logic& logic, const std::string& piece) {
    std::vector<std::pair<Positions, Positions>> getPossible = getAllPossibleMoves(board, logic, piece);
    int countMax = -1;
    std::pair<Positions, Positions> best =
            std::make_pair(Positions(0, 0), Positions(0, 0));

    for(const auto& move : getPossible){
        if(board.getPieceAtPosition(move.first) == "W") {
            int amount = amountOfPieces(board, move.first, move.second);
            if (amount > countMax) {
                countMax = amount;
                best = move;
            }
        }
    }
    return best;
}
