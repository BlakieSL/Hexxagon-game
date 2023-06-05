
#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H
#include <string>
#include <array>
#include <vector>
#include "Positions.h"

class Board {
    std::array<std::string,9> arr1 {" ", " ", " ", " ", "W", " ", " ", " ", " "};
    std::array<std::string,9> arr2 {" ", " ", " ", "0", " ", "0", " ", " ", " "};
    std::array<std::string,9> arr3 {" ", " ", "0", " ", "0", " ", "0", " ", " "};
    std::array<std::string,9> arr4 {" ", "0", " ", "0", " ", "0", " ", "0", " "};
    std::array<std::string,9> arr5 {"R", " ", "0", " ", "0", " ", "0", " ", "R"};
    std::array<std::string,9> arr6 {" ", "0", " ", "0", " ", "0", " ", "0", " "};
    std::array<std::string,9> arr7 {"0", " ", "0", " ", "x", " ", "0", " ", "0"};
    std::array<std::string,9> arr8 {" ", "0", " ", "0", " ", "0", " ", "0", " "};
    std::array<std::string,9> arr9 {"0", " ", "0", " ", "0", " ", "0", " ", "0"};
    std::array<std::string,9> arr10{" ", "0", " ", "x", " ", "x", " ", "0", " "};
    std::array<std::string,9> arr11{"0", " ", "0", " ", "0", " ", "0", " ", "0"};
    std::array<std::string,9> arr12{" ", "0", " ", "0", " ", "0", " ", "0", " "};
    std::array<std::string,9> arr13{"W", " ", "0", " ", "0", " ", "0", " ", "W"};
    std::array<std::string,9> arr14{" ", "0", " ", "0", " ", "0", " ", "0", " "};
    std::array<std::string,9> arr15{" ", " ", "0", " ", "0", " ", "0", " ", " "};
    std::array<std::string,9> arr16{" ", " ", " ", "0", " ", "0", " ", " ", " "};
    std::array<std::string,9> arr17{" ", " ", " ", " ", "R", " ", " ", " ", " "};
    std::array<std::array<std::string, 9>, 17> arr {arr1,arr2,arr3,arr4,arr5,arr6,arr7,arr8,arr9,arr10,arr11,arr12,arr13,arr14,arr15,arr16,arr17};
    /**
     * \brief This function prints the board(array) to console
     */
    public:void printArr();
    /**
     * \brief returns array(board)
     */
    public: std::array<std::array<std::string, 9>, 17> getArr() const;
    /**
     * \brief set a piece on the chosen position on the board
     * @param position is used to pass a coordinates, on which piece should be set
     * @param piece is a piece that should be set
     */
    public: void setPieceAtPostion(const Positions& position, std::string piece);
    /**
     * \brief returns a piece on the chosen position
     * @param positions is a position, from which piece should be returned
     * @return returns a piece
     */
    public: std::string getPieceAtPosition(const Positions& positions);
    /**
     * \brief returns an opposite color piece to one, that was passed as a argument
     */
    public:  std::string getOppositePiece(const std::string& piece);
    /**
     * \brief returns all positions on the board(array) as a vector of positions
     */
    public:std::vector<Positions> getAllPositions() const;
    /**
     * \brief This function simply checks whether element is in array
     * @param positions is used to get element with this position
     */
    public: bool isValidPos(Positions positions);
    /**
     * \brief This function is used to set an array
     */
    public: void setArr(std::array<std::array<std::string, 9>, 17> array);
};


#endif //HEXXAGON_BOARD_H
