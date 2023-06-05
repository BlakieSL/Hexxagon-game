//
// Created by user on 25.05.2023.
//

#ifndef HEXXAGON_GAME_H
#define HEXXAGON_GAME_H
#include <string>
#include "Board.h"
#include "Logic.h"
#include "Move.h"
#include "SavingLoading.h"
#include "AI.h"

class Game  {
Board board;
Logic logic;
Move move;
AI bot;
SavingLoading sl;
int Gamemod;
std::string currentPlayer = "R";
public: int getGamemod() const;
public: void setGamemod(int val);
public: void startGame();
public: void applyPlayer();
public: void applyBot();
public: bool isGameOver();
public: std::string winner();
public: void changeTurn();
public: bool isPieceOfCurrentPlayer(const std::string& piece);
};


#endif //HEXXAGON_GAME_H
