/*
 © Copyright 2020 Anushree Sabnis
 * MIT License
*/

#include <iostream>
#include "maze.h"

using namespace std;

Map::Map(int mw, int mh) {
    map_width = mw;
    map_height = mh;
    render_map_width = 2*map_width + 1;
    render_map_height = 2*map_height + 1;
    initMap(map);
    initStack();
    createStack();
    drawMap(map);
}

void Map::initMap(vector<vector<char>> & map)
{
    vector<char> row(render_map_width, wall);
    vector<char> wallrow(render_map_width, wall);
    vector<vector<char>> map_func(render_map_height, row);
    map = map_func;
}

void Map::initStack()
{
    cells.resize(map_width, vector<int>(map_height));
    cell_stack.push(make_pair(0,0));
    cells[0][0] = CELL_VISITED;
    num_visitedCells++;

}

void Map::createStack()
{
    // Run till all cells are visisted
    while (true) {
      cout << cell_stack.top().first << "," << cell_stack.top().second << endl;

    if (num_visitedCells == (map_width) * (map_height)) {
        cout << "All cells are visited! Maze is now ready.";
        break;
    }
    else {
        // 1. Check unvisited neighbours
        vector<int> neighbours;
        // North Neighbour
        if (cell_stack.top().second > 0 && ( cells[offset_x(0)][offset_y(-1)] & CELL_VISITED) == 0 ) {
            neighbours.push_back(NORTH);
        }
      // South Neighbour
        if (cell_stack.top().second < map_height-map_cell_offset && ( cells[offset_x(0)][offset_y(1)] & CELL_VISITED) == 0 ) {
            neighbours.push_back(SOUTH);
        }
        // East Neighbour
        if ((cell_stack.top().first < map_width-map_cell_offset) && (cells[offset_x(1)][offset_y(0)] & CELL_VISITED) == 0) {
            neighbours.push_back(EAST);
        } 
        
        // West Neighbour
        if (cell_stack.top().first> 0 && ( cells[offset_x(-1)][offset_y(0)] & CELL_VISITED) == 0 ) {
            neighbours.push_back(WEST);
        }

        // 2. If neighbours are available, create path
        if (!neighbours.empty()) {
            // Choose direction
            int next_cell_dir = neighbours[rand() % neighbours.size()];
            int rX = cell_stack.top().first*2 + 1;
            int rY = cell_stack.top().second*2 + 1;
            map[rX][rY] = visited;

            switch (next_cell_dir)
            {
                case NORTH:
                    cells[offset_x(0)][offset_y(0)] |= CELL_PATH_N;
                    cells[offset_x(0)][offset_y(-1)] |= CELL_PATH_S;
                    cell_stack.push(make_pair((cell_stack.top().first),cell_stack.top().second -1));
                    map[rX][rY-1] = space;
                    break;
                case EAST:
                    cells[offset_x(0)][offset_y(0)] |= CELL_PATH_E;
                    cells[offset_x(1)][offset_y(0)] |= CELL_PATH_W;
                    cell_stack.push(make_pair((cell_stack.top().first + 1),cell_stack.top().second));
                  map[rX+1][rY] = space;
                    break;
                case SOUTH:
                    cells[offset_x(0)][offset_y(0)] |= CELL_PATH_S;
                    cells[offset_x(0)][offset_y(1)] |= CELL_PATH_N;
                    cell_stack.push(make_pair((cell_stack.top().first),cell_stack.top().second +1));
                  map[rX][rY+1] = space;
                  
                    break;
                case WEST:
                    cells[offset_x(0)][offset_y(0)] |= CELL_PATH_W;
                    cells[offset_x(-1)][offset_y(0)] |= CELL_PATH_E;
                    cell_stack.push(make_pair((cell_stack.top().first - 1),cell_stack.top().second));
                  map[rX-1][rY] = space;
                    break;
            }
            
            // Make new cell visited cell
            cells[offset_x(0)][offset_y(0)] |= CELL_VISITED;
            num_visitedCells++;

        }
        // 3. If no neighbours are available, backtrack
        else {
            cout << "popping stack" << endl;
            cell_stack.pop();
            continue;
        }
        
    }

  }
  int rX = cell_stack.top().first*2 + 1;
  int rY = cell_stack.top().second*2 + 1;
  map[rX][rY] = visited;
  
}

void Map::drawMap(vector<vector<char>> map)
{
    cout << "Drawing map";
    for(auto line : map)
    {
        cout << "\n" << endl;
        for (auto pixel : line) {
            cout << pixel << "  ";
        }
    }
}


void Map::getMaze(vector<vector<char>> &maze)
{
    maze = map;
}

int main() {
    int mw, mh, cf;
    cout << "Input Map height, Width " << endl;
    cin >> mw >> mh;
    Map maze(mw, mh);

    // getting Maze
    // vector<vector<char>> nmaze;
    // maze.getMaze(nmaze);
    // maze.drawMap(nmaze);
}