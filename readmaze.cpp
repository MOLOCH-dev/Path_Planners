#include <string>
#include <vector>
#include "readmaze.h"
#include <fstream>
#include <iostream>


MazeReader::MazeReader(std::vector<std::vector<char>> & maze) { MyVector = maze; }
std::vector<std::vector<char>> MazeReader::getMaze() { return MyVector; }

int main() {

    std::string eachrow;

    std::ifstream myfile("./maze_file.txt");

    std::vector<std::vector<char> > MyVector;

    while (std::getline(myfile, eachrow))
    {
        std::vector<char> row;

        for (char &x : eachrow)
        {
            // if (x != ' ') 
            //     //add element to vector row
            row.push_back(x); 
        }
        //after iterating row in text file, add vector into 2D vector
        MyVector.push_back(row);
    }

    for (std::vector<char> &row : MyVector)
    {
        for (char &x : row) 
            //print each element
            std::cout << x << ' ';

        //change row
        std::cout << '\n';
    }

    return 0;
}