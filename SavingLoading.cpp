//
// Created by user on 25.05.2023.
//

#include "SavingLoading.h"
#include "GUI.h"
#include <fstream>

void SavingLoading::saveToFile(const std::string &filename, const Board &board, int mode, const std::string& currentPlayer ) {
    std::ofstream ofstr (filename);
    const auto& arr = board.getArr();

    ofstr << mode << '\n';
    ofstr << currentPlayer << '\n';
    for (const auto& row : arr) {
        for (const auto& piece : row) {
            std::string newPiece = piece;
            if (newPiece == " ") {
                newPiece = "empty";
            }
            ofstr << newPiece<< " ";
        }
        ofstr << '\n';
    }
}

void SavingLoading::loadFromFile(const std::string &filename, Board &board, GUI& gui) {
    std::ifstream  ifstr(filename);
    std::array<std::array<std::string, 9>, 17> arr;
    int mode;
    std::string currentPlayer;
    ifstr >> mode;
    ifstr >> currentPlayer;
    for (auto & i : arr) {
        for (auto & j : i) {
            std::string piece;
            ifstr >> piece;
            if(piece == "empty"){
                piece = " ";
            }
            j = piece;
        }
    }
    board.setArr(arr);
    gui.setGameMod(mode);
    gui.setCurrentPlayer(currentPlayer);
}


