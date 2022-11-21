/*
 © Copyright 2022 Anushree Sabnis
 * MIT License
*/

// maze.h
#ifndef READMAZE_H
#define READMAZE_H

#include <vector>

class MazeReader
{
    private:
        std::vector<std::vector<char>> MyVector;
    public :
        MazeReader(std::vector<std::vector<char>> & maze);
        std::vector<std::vector<char>> getMaze();

};

#endif