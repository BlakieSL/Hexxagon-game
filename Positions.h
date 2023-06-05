    //
    // Created by user on 25.05.2023.
    //

    #ifndef HEXXAGON_POSITIONS_H
    #define HEXXAGON_POSITIONS_H

#include <system_error>

    class Positions : public std::error_code {
        int x;
        int y;
    public:Positions(int x, int y);
        /**
         * This is simplest getter of X coordinate
         */
    public: int getX() const;
        /**
         * This is a simplest getter of Y coordinate
         */
    public: int getY() const;

    };


    #endif //HEXXAGON_POSITIONS_H
