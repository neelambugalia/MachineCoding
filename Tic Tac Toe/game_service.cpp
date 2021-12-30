#include "models.cpp"

class GameService{
    private:
    GameBoard board;
    public:
    
    GameService(){}
    GameService(GameBoard board){
        this->board = board;
    }

    void printGrid(vector<vector<char>> &grid){
        int boardSize = board.getSize();
        cout << "Currently the Board is\n";
            for(int i = 0; i < boardSize; i++){
                for(int j = 0; j < boardSize; j++){
                cout << grid[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
    }

    void setPiecePosition(vector<vector<char>> &grid, Player& curPlayer){
        int boardSize = board.getSize();
        char piece = curPlayer.getPiece();
        int xPosition, yPosition;
        cout << "x position : ";
        cin >> xPosition;
        while(xPosition >= boardSize){
            cout << "Position out of bound. Please select positions from 0 to " << boardSize - 1 << "\n";
            cout << "x position : ";
            cin >> xPosition;
        }
                
        cout << "y position : ";
        cin >> yPosition;
        while(yPosition >= boardSize){
            cout << "Position out of bound. Please select positions from 0 to " << boardSize - 1 << "\n";
            cout << "y position : ";
            cin >> yPosition;
        }

        if(grid[xPosition][yPosition] != '_'){
                cout << "Invalid position. Please choose other position.\n";
                setPiecePosition(grid, curPlayer);
        }
        else{
            board.writeOnBoard(xPosition,yPosition,piece);
        }
    }

    bool hasWon(vector<vector<char>> &grid, char piece){
        int boardSize = board.getSize();
        int diagonal1Pieces = 0;
            int diagonal2Pieces = 0;
            int horizontalPieces = 0;
            int verticalPieces = 0;
            bool won = 0;
            for(int i =0; i < boardSize; i++){
                for(int j =0; j < boardSize; j++){
                    if(i == j && grid[i][j] == piece)
                        diagonal1Pieces++;
                    if(i + j == boardSize - 1 && grid[i][j] == piece)
                        diagonal2Pieces++;
                    if(grid[i][j] == piece)
                        horizontalPieces++;
                    if(grid[j][i] == piece)
                        verticalPieces++;
                }
                if(horizontalPieces == boardSize || verticalPieces == boardSize){
                    won = 1;
                    break;
                }
                horizontalPieces = 0;
                verticalPieces = 0;
            }
            return won || diagonal1Pieces == boardSize || diagonal2Pieces == boardSize;
    }

    bool isDraw(vector<vector<char>> &grid){
        int emptyCells = 0;
        for(auto i : grid){
            for(auto j : i){
                if(j == '_')
                    emptyCells++;
            }
        }
        return emptyCells == 0;
    }

    void playGame(){
        int id = 0;
        int boardSize = board.getSize();
        vector<vector<char>> &grid = board.getGrid();
        printGrid(grid);
        while(1){
            Player &curPlayer = board.getPlayer(id);
            char piece = curPlayer.getPiece();
            string playerName = curPlayer.getName();
            cout << playerName<<"'s turn\n";
            cout << "Select where you want to put your piece\n";

            setPiecePosition(grid, curPlayer); 
            printGrid(grid);

            if(hasWon(grid, piece)){
                cout << playerName << " has won the game\n";
                break;
            }
            if(isDraw(grid)){
                cout << "Oops! it's a draw.\n";
                break;
            }
            id++;
            id %= 2;
        }
    }

};