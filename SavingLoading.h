//
// Created by user on 25.05.2023.
//

#ifndef HEXXAGON_SAVINGLOADING_H
#define HEXXAGON_SAVINGLOADING_H


#include <string>
#include "Board.h"
#include "GUI.h"
class GUI;

class SavingLoading {
/**
 * \brief This function is used to save array into file
 * @param filename is used to create a file with chosen name
 * @param board is used to get access to board(array)
 * @param mode is used to save a game mode
 * @param currentPlayer is used to save which move is
 */
public: static void saveToFile(const std::string& filename, const Board& board,int mode, const std::string& currentPlayer );
/**
 * \brief This function is used to load from file
 * @param filename is used to read a file with chosen name
 * @param board is used to set a board(array)
 * @param gui is used to set a currentPlayer and a game mode
 */
public: static void loadFromFile(const std::string& filename, Board& board, GUI& gui);
};


#endif //HEXXAGON_SAVINGLOADING_H
