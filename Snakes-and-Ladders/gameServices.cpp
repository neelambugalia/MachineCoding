#include "models.cpp"

class GameService{
    private:
    GameBoard board;
    Dice dice;


    public:
    GameService(){}

    GameService(GameBoard board, Dice dice){
        this->board = board;
        this->dice = dice;
    }

    void playGame(){
        int boardSize = board.getSize();
        int maxPosition = boardSize*boardSize;
        int curIdx = 0;
        while(1){
            Player &curPlayer = board.getPlayer(curIdx);
            string playerName = curPlayer.getName();
            int moves = dice.roll();
            cout << playerName << " rolled " << moves << "\n";
            int playerPosition = curPlayer.getPosition();
            
            if(playerPosition + moves <= maxPosition){
                board.updatePlayer(curIdx, moves);
                cout << playerName << " moved to " << curPlayer.getPosition() << "\n";
            }
    
            for(auto snake : board.getSnakes()){
                if(snake.getHead() == curPlayer.getPosition()){
                    board.setPlayer(curIdx,snake.getTail());
                    cout << playerName << " got snake and now is at " << curPlayer.getPosition()<<"\n";
                }
            }
            for(auto ladder : board.getLadders()){
                if(ladder.getStart() == curPlayer.getPosition()){
                    board.setPlayer(curIdx,ladder.getEnd());
                    cout << playerName << " got ladder and now is at " << curPlayer.getPosition()<<"\n";
                }
                    
            }
            
            if(curPlayer.getPosition() == maxPosition){
                cout << playerName << " won the game\n";
                break;
            }
            curIdx++;
            curIdx %= board.getPlayers().size();
        }
    }


};