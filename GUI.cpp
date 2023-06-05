//
// Created by user on 27.05.2023.
//

#include "GUI.h"
#include "Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>

const sf::Color RedPiece(255, 0, 0);
const sf::Color WhitePiece(255, 255, 255);
const sf::Color EmptyPiece(128, 0, 128);
const sf::Color XPiece(34,23,167);

void GUI::changeTurn() {
    currentPlayer = (currentPlayer =="R")? "W": "R";
}
void GUI::setCurrentPlayer(std::string currentPlayer1) {
    this->currentPlayer = std::move(currentPlayer1);
}
void GUI::setGameMod(int val) {
    this->Gamemod = val;
}
bool GUI::isGameOver() {
    std::vector<Positions> positions = board.getAllPositions();
    for (const auto& startPos : positions) {
        for (const auto& endPos : positions) {
            if (logic.isValidMove(startPos, endPos, board, currentPlayer)) {
                return false;
            }
        }
    }
    return true;
}
std::string GUI::winner() {
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
Positions GUI::selectHex(const sf::Vector2i &mousePos) {
    int col = (mousePos.x-20)/60;
    int row = (mousePos.y+5)/52;
    return {row,col}; // convert mouse position to array(board)
}
void GUI::drawHex(sf::RenderWindow &window, const sf::Color color, int x, int y, bool isSelected) {
    sf::CircleShape hexxagon(30,6);
    hexxagon.setFillColor(color);
    hexxagon.setPosition({static_cast<float>(x),static_cast<float>(y)});
    hexxagon.setOutlineThickness(2.0f);
    hexxagon.setOutlineColor(isSelected ? sf::Color::Green : sf::Color::Black);
    sf::Angle angle(30);
    hexxagon.setRotation(angle);
    window.draw(hexxagon);
}
void GUI::drawAllHex(sf::RenderWindow &window, const std::array<std::array<std::string, 9>, 17> &arr) {
    sf::Color color;
    for(int i =0; i<arr.size(); i++){
        for(int j=0;j<arr[i].size();j++) {
            if (arr[i][j] != " ") {
                if (arr[i][j] == "W") {
                    color = WhitePiece;
                } else if (arr[i][j] == "R") {
                    color = RedPiece;
                } else if (arr[i][j] == "0") {
                    color = EmptyPiece;
                } else if (arr[i][j] == "x") {
                    color = XPiece;
                }
                int width = 20+j*60;
                int height = i*52-5;
                drawHex(window, color, width,height, false);
            }
        }
    }
}
void GUI::visualizeMove(sf::RenderWindow &window,  Positions positions,const std::array<std::array<std::string, 9>, 17> &arr){
    int x = positions.getX();
    int y = positions.getY();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        Positions endPos = selectHex(mousePos);
        if (logic.isValidMove(Positions(x, y), endPos, board, arr[x][y])) {
            move.makeMove(board, Positions(x, y), endPos);
            changeTurn();
        }

    }

}
void GUI::drawSelectedHex(sf::RenderWindow &window, const Positions positions,const std::array<std::array<std::string, 9>, 17> &arr) {
    int x = positions.getX();
    int y = positions.getY();
    if (x >= 0 && x < arr.size() &&y >= 0 && y < arr[x].size()) {
        sf::Color color;
        if(arr[x][y] != " " && arr[x][y] != "0" && arr[x][y] != "x" && arr[x][y] == currentPlayer){
            if (arr[x][y] == "W") {
                color = WhitePiece;
            } else if (arr[x][y] == "R") {
                color = RedPiece;
            }
            int width = 20+y*60;
            int height = x*52-5;
            drawHex(window, color,width, height, true);

            for(int i =0; i<arr.size(); i++){
                for(int j =0; j<arr[i].size(); j++){
                    if(logic.isValidMove(Positions(x,y), Positions(i,j), board, arr[x][y] )){
                        if (arr[i][j] == "W") {
                            color = WhitePiece;
                        } else if (arr[i][j] == "R") {
                            color = RedPiece;
                        } else if(arr[i][j] == "0"){
                            color = EmptyPiece;
                        }
                        int width1 = 20+j*60;
                        int height1 = i*52-5;
                        drawHex(window, color ,width1,height1 ,true);
                    }
                }
            }
        }
    }
}
void GUI::start() {
    std::cout << "Type 1 to play game, or type 0 to load the game"<<std::endl;
    int x;
    std::cin>>x;
    if(x==0){
        std::cout<<"Type the name of file you want to load";
        std::string filename;
        std::cin>>filename;
        SavingLoading::loadFromFile(filename,board, *this);
    }
    if(x!=0) {
        std::cout << "Type 1 for Player game, or press 0 to play with Bot";
        int val;
        std::cin >> val;
        setGameMod(val);
    }
    sf::RenderWindow window(sf::VideoMode({540,900}), "Window");
    sf::Event event{};
    Positions positions = Positions(0, 0);

    while(window.isOpen() && !isGameOver()){
        window.clear(sf::Color::Black);
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            } else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W ){
                std::cout<<"Chose a file name"<<std::endl;
                std::string filename;
                std::cin>>filename;
                SavingLoading::saveToFile(filename,board,Gamemod, currentPlayer);
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                positions = selectHex(mousePos);
                isHexSelected = true;
            }
        }
        drawAllHex(window, board.getArr());
        if (isHexSelected) {
            drawSelectedHex(window,positions, board.getArr());
            visualizeMove(window,positions,board.getArr());
        }
        if(Gamemod == 0 && currentPlayer == "W"){
            std::pair<Positions, Positions> cord = bot.getMoveCoordinates(board, logic, currentPlayer);
            move.makeMove(board, cord.first, cord.second);
            changeTurn();
        }

        window.display();
    }
    std::cout<<"Winner: "<< winner();

}







