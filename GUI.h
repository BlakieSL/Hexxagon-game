//
// Created by user on 27.05.2023.
//

#ifndef HEXXAGON_GUI_H
#define HEXXAGON_GUI_H


#include "Board.h"
#include "Logic.h"
#include "Move.h"
#include "AI.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SavingLoading.h"

class GUI {
    Board board;
Logic logic;
Move move;
AI bot;

int Gamemod;
std::string currentPlayer = "R";
bool isHexSelected = false;
/**
 * \brief This function changes the turn of a player
 */
public:void changeTurn();
/**
 * \brief This function checks if move is valid
 */
public:void setCurrentPlayer(std::string currentPlayer1);
public:bool isGameOver();
/**
 * \brief This function decides who won the game by calculating pieces
 */
public:std::string winner();
/**
 * \brief This function sets the game mod(with bot or with another player)
 */
public:void setGameMod(int val);
/**
 * \brief This function selects the needed hexagon
 * It converts position of mouse into indexes of array
 * @return the Position of hexagon in array
 */
public:Positions selectHex(const sf::Vector2i& mousePos);
/**
 * \brief draws each hexagon
 * @param window is used to draw hexagon on the window
 * @param color is used to draw hexagon with specific color
 * @param x is used to set X position of hexagon
 * @param y is used to set Y position of hexagon
 * @param isSelected is used to indicate whether hexagon should be outlined or not
 */
public:void drawHex(sf::RenderWindow& window, sf::Color color, int x, int y, bool isSelected);
/**
 * \brief This function draws all hexagons on the screen
 * @param window is used to pass it as an argument to drawHex function
 * @param arr is used to visualize board(array)
 */
public:void drawAllHex(sf::RenderWindow& window, const std::array<std::array<std::string, 9>, 17>& arr);
/**
 * \brief This function is used to outline selected hexagon and visualize possible moves
 * @param window is used to pass it as an argument to drawHex
 * @param positions is used to get x and y coordinates of element of array
 * @param arr is used to visualize needed elements of an array
 */
public:void drawSelectedHex(sf::RenderWindow& window,  Positions positions, const std::array<std::array<std::string, 9>, 17>& arr );
/**
 * \brief This function makes moves on the board
 * @param window is used to get coordinates of Right button mouse click
 * @param positions is used to get x and y coordinates of array
 * @param arr is used to pass it as an argument to validation method
 */
public: void visualizeMove(sf::RenderWindow &window, Positions positions,
                       const std::array<std::array<std::string, 9>, 17> &arr);
/**
 * \brief This function is used to combine all methods and starts the game
 */
public:void start();
};


#endif //HEXXAGON_GUI_H
