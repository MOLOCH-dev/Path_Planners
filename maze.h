/*
 © Copyright 2020 Anushree Sabnis
 * MIT License
*/

// maze.h
#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <functional>
#include <stack>

using namespace std;
class Map
{
    private : 
        int map_width = 50;
        int map_height = 50;
        int render_map_height;
        int render_map_width;
        int num_visitedCells = 0;
        int map_cell_offset = 1;
        char wall = '#';
        char visited = 'X';
        char space = ' ';
        vector<vector<char>> map;
        vector<vector<int>> cells;
        stack<pair<int,int>> cell_stack;

        enum 
        {
            CELL_PATH_N = 0x01,
            CELL_PATH_E = 0x02,
            CELL_PATH_S = 0x04,
            CELL_PATH_W = 0x08,
            CELL_VISITED = 0x10
        };

        enum 
        {
            NORTH = 0,
            EAST = 1,
            SOUTH = 2,
            WEST = 3
        };

    public:
    Map(int mw, int mh);
    void initMap(vector<vector<char>> & map);
    void initStack();
    void drawMap(vector<vector<char>> map);
    void createStack();
    void getMaze(vector<vector<char>> & maze);

    function<int(int)> offset_x = [this] (int x) { return this->cell_stack.top().first + x; };
    function<int(int)> offset_y = [this] (int y) { return this->cell_stack.top().second + y; };
};

#endif