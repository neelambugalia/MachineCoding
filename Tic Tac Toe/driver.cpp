#include "game_service.cpp"

int main(){
    int gridSize;
    cout << "Please size of grid : ";
    cin >> gridSize;
    vector<vector<char>> grid(gridSize, vector<char> (gridSize, '_'));
    string name1, name2;
    cout << "Enter names of players\n";
    cout << "1st player : ";
    cin >> name1;
    cout << "2nd player : ";
    cin >> name2;

    Player player1 = Player(name1, 'X');
    Player player2 = Player(name2, 'O');
    vector<Player> players;
    players.push_back(player1);
    players.push_back(player2);
    GameBoard gameBoard = GameBoard(gridSize, grid, players);
    GameService game = GameService(gameBoard);
    game.playGame();

    return 0;
}