#include<bits/stdc++.h>
using namespace std;

class Player{
    private:
    string name;
    char piece;
    

    public:
    Player(){}
    Player(string name, char piece){
        this->name = name;
        this->piece = piece;
    }

    string getName(){
        return name;
    }

    char getPiece(){
        return piece;
    }
};

class GameBoard{
    private:
    int size;
    vector<vector<char>> grid;
    vector<Player> players;

    public:
    GameBoard() {}
    GameBoard(int size, vector<vector<char>> grid, vector<Player> players){
        this->size = size;
        this->players = players;
        this->grid = grid;
    }

    vector<vector<char>>& getGrid(){
        return grid;
    }

    Player& getPlayer(int id){
        return players[id];
    }

    int getSize(){
        return size;
    }

    void writeOnBoard(int x, int y, char piece){
        grid[x][y] = piece;
    }
};