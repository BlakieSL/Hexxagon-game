//
// Created by user on 25.05.2023.
//

#include <iostream>
#include "Game.h"
void Game::startGame() {
    std::cout << "Type 1 for Player game, or press 0 to play with Bot";
    int val;
    std::cin >> val;
    setGamemod(val);
    if(Gamemod==1) {
        while (isGameOver()) {
            board.printArr();
            applyPlayer();
            changeTurn();
        }
    }
    if(Gamemod==0){
        while(isGameOver()){
            board.printArr();
            applyBot();
            changeTurn();
        }
    }

    std::cout<< winner();
}
bool Game::isGameOver() {

    std::vector<Positions> positions = board.getAllPositions();
    for (const auto& startPos : positions) {
        std::string piece = board.getPieceAtPosition(startPos);
        for (const auto& endPos : positions) {
            if (logic.isValidMove(startPos, endPos, board, piece)) {
                return false;
            }
        }
    }
    return true;
}
std::string Game::winner() {
    int white = 0;
    int red = 0;
    for (const auto& row : board.getArr()) {
        for (const auto& piece : row) {
            if (piece == "R") {
                red++;
            } else if (piece == "W") {
                white++;
            }
        }
    }
    if (white > red) {
        return "W";
    }else if(red > white){
        return "R";
    }else {
        return "Draw";
    }
}
bool Game::isPieceOfCurrentPlayer(const std::string& piece) {
    return(piece == currentPlayer);
}
void Game::changeTurn() {
    currentPlayer = (currentPlayer =="R")? "W": "R";
}
void Game::applyPlayer() {
    bool flag=true;
    while(flag) {
            std::cout << " Enter starting coordinates " << std::endl;
            int x1;
            std::cin >> x1;
            if (std::cin.fail()) {
                throw std::runtime_error("Invalid staring x position");
            }
            int y1;
            std::cin >> y1;
            if (std::cin.fail()) {
                throw std::runtime_error("Invalid staring y position");
            }

            Positions startingPos(x1, y1);

            std::cout << "Enter ending coordinates" << std::endl;
            int x2;
            std::cin >> x2;
            if (std::cin.fail()) {
                throw std::runtime_error("Invalid input ending x position");
            }
            int y2;
            std::cin >> y2;
            if (std::cin.fail()) {
                throw std::runtime_error("Invalid input ending Y position");
            }

            Positions endingPos(x2, y2);

            if (logic.isValidMove(startingPos, endingPos, board, currentPlayer)
                && isPieceOfCurrentPlayer(board.getPieceAtPosition(startingPos))) {
                move.makeMove(board, startingPos, endingPos);

                flag = false;

            } else {
                std::cout << "Move is invalid, or it is not yours piece" << std::endl;
            }
    }
}

void Game::applyBot() {
    bool flag= true;
    while(flag) {
        if (currentPlayer == "R") {
            std::cout << " Enter starting coordinates " << std::endl;
            int x1;
            std::cin >> x1;
            int y1;
            std::cin >> y1;
            Positions startingPos(x1, y1);

            std::cout << "Enter ending coordinates" << std::endl;
            int x2;
            std::cin >> x2;
            int y2;
            std::cin >> y2;
            Positions endingPos(x2, y2);

            if (logic.isValidMove(startingPos, endingPos, board, currentPlayer)
                && isPieceOfCurrentPlayer(board.getPieceAtPosition(startingPos))) {
                move.makeMove(board, startingPos, endingPos);
                flag = false;
            } else {
                std::cout << "Move is invalid, or it is not yours piece" << std::endl;
            }
        } else {
            std::pair<Positions, Positions> cord = bot.getMoveCoordinates(board, logic, currentPlayer);
            move.makeMove(board, cord.first, cord.second);
            std::cout << "bot made a move: " << cord.first.getX() << " " << cord.first.getY() << " " <<
                      cord.second.getX() << " " << cord.second.getY() << std::endl;
            flag=false;
        }
    }
}
int Game::getGamemod() const {
    return Gamemod;
}
void Game::setGamemod(int val) {
this->Gamemod = val;
}





