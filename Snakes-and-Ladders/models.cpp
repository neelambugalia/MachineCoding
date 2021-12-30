// classes - snake, ladder, game-board, dice
#include<bits/stdc++.h>
using namespace std;

class Player{
    private:
    int id;
    string name;
    int position;

    public:
    Player(){
        this->position = 0;
    }
    Player(string name, int id){
        this->name = name;
        this->id = id;
        this->position = 0;
    }

    string getName(){
        return name;
    }

    int getId(){
        return id;
    }

    int getPosition(){
        return position;
    }

    void setPosition(int position){
        this->position = position;
    }

    void updatePosition(int diceResult){
        this->position = this->position + diceResult;
    }

};

class Snake{
    private:
    int head;
    int tail;

    public:
    Snake(int head, int tail){
        this->head = head;
        this->tail = tail;
    }

    int getHead(){
        return head;
    }

    int getTail(){
        return tail;
    }
};

class Ladder{
    private:
    int end;
    int start;

    public:
    Ladder(int start, int end){
        this->end = end;
        this->start = start;
    }

    int getEnd(){
        return end;
    }

    int getStart(){
        return start;
    }
};

class GameBoard{
    private:
    int size;
    vector<Snake>snakes;
    vector<Ladder>ladders;
    vector<Player>players;

    public:
    GameBoard(){
        this->size = 10;
    }

    GameBoard(int size, vector<Snake> snakes, vector<Ladder> ladders, vector<Player> players){
        this->size = size;
        this->snakes = snakes;
        this->ladders = ladders;
        this->players = players;
    }

    int getSize(){
        return size;
    }

    Player& getPlayer(int idx){
        return players[idx];
    }

    void updatePlayer(int idx, int moves){
        players[idx].setPosition(moves + players[idx].getPosition());
    }

    void setPlayer(int idx, int position){
        players[idx].setPosition(position);
    }

    vector<Player> getPlayers(){
        return players;
    }

    vector<Snake> getSnakes(){
        return snakes;
    }

    vector<Ladder> getLadders(){
        return ladders;
    }
 };

class Dice{
    private:
    int startNumber;
    int endNumber;

    public:
    Dice(){
        this->startNumber = 1;
        this->endNumber = 6;
    }

    Dice(int startNumber, int endNumber){
        this->startNumber = startNumber;
        this->endNumber = endNumber;
    }

    int roll(){
        return startNumber + rand() % (endNumber - startNumber);
    }

};
