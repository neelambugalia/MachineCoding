#include "gameServices.cpp"

int main(){
    int boardSize;
    int NoOfSnakes;
    int NoOfLadders;
    int NoOfPlayers;

    cout << "Please Enter the Board Size\n";
    cin >> boardSize;

    cout << "Please Enter the no. of snakes you want\n";
    cin >> NoOfSnakes;
    vector<Snake> snakes;
    for(int i = 1; i <= NoOfSnakes; i++){
        int head , tail;
        cout << "Please Enter positions of snake no. " << i <<"\n";
        cout << "head : ";
        cin >> head;
        cout << "tail : ";
        cin >> tail;
        Snake snake = Snake(head, tail);
        snakes.push_back(snake);
    }

    cout << "Please Enter the no. of ladders you want\n";
    cin >> NoOfLadders;
    vector<Ladder> ladders;
    for(int i = 1; i <= NoOfLadders; i++){
        int start , end;
        cout << "Please Enter positions of ladder no. " << i <<"\n";
        cout << "start : ";
        cin >> start;
        cout << "end : ";
        cin  >> end;
        Ladder ladder = Ladder(start, end);
        ladders.push_back(ladder);
    }

    cout << "How many players are there\n";
    cin >> NoOfPlayers;
    vector<Player> players;
    for(int i = 1; i <= NoOfPlayers; i++){
        string name;
        cout << "Please Enter name of player no. " << i <<"\n";
        cin >> name;
        Player player = Player(name, i);
        players.push_back(player);
    }

    GameBoard board = GameBoard(boardSize, snakes, ladders, players);
    Dice dice = Dice();

    GameService game = GameService(board, dice);
    game.playGame();
   
    return 0;
}