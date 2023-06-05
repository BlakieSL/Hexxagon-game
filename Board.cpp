
#include "Board.h"
#include <iostream>
#include <utility>
void Board::printArr() {

    for (int j = 0; j < arr[0].size(); j++) {
        std::cout << j << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << " " << i << std::endl;
    }
    for (int j = 0; j < arr[0].size(); j++) {
        std::cout << j << " ";
    }
    std::cout << std::endl;
}
std::array<std::array<std::string, 9>, 17> Board::getArr() const{
    return arr;
}

void Board::setPieceAtPostion(const Positions& position, std::string piece) {
    arr[position.getX()][position.getY()] = std::move(piece);
}

std::string Board::getPieceAtPosition(const Positions& positions) {
    return arr[positions.getX()][positions.getY()];
}

std::string Board::getOppositePiece(const std::string& piece) {
    if (piece == "R"){
        return "W";
    }else{
        return "R";
    }
}
std::vector<Positions> Board::getAllPositions() const {
    std::vector<Positions> positions;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            positions.emplace_back(i, j);
        }
    }
    return positions;
}

bool Board::isValidPos(Positions positions) {
    return positions.getX()<arr.size() && positions.getY()<arr[1].size();
}

void Board::setArr(std::array<std::array<std::string, 9>, 17> array) {
    arr = std::move(array);
}




