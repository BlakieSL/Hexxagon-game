//
// Created by user on 25.05.2023.
//

#include "Logic.h"
bool Logic::isValidMove(const Positions& startPos, const Positions& endPos, Board& board, const std::string& piece) {
    int x1 = startPos.getX();
    int y1 = startPos.getY();

    int x2 = endPos.getX();
    int y2 = endPos.getY();
    if(!board.isValidPos(Positions(x2,y2))){
        return false;
    }
    std::array<std::array<std::string,9>,17> arr = board.getArr();

    if(x2<0 || y2<0 || x2>arr.size()-1 || y2 > arr[1].size()-1){return false;}

    if(arr[x2][y2] != "0"){return false;}

    std::string p;
    //piece == "R"? p = "R": p = "W";
    if(arr[x1][y1] != piece){return false;}

    int dx = abs(x1-x2);
    int dy = abs(y1-y2);
    //default clause for validation
    if(dx <=4 && dy <=2 && (dx+dy)<=4){return true;}
    return false;
}
