//
// Created by MiaKim on 25/07/2025.
//
#include <iostream>
#include <vector>

using namespace std;

class TicTacToe{
private:
    vector<vector<char>> gameboard;
    char currentPlayer = 'X';

public:
    //Gameboard (3x3)
    void resetBoard() {
        char symbolNumber = '1'; // why char ? cuz vector<vector<char>> gameboard
        gameboard.clear(); //reset gameboard. otherwise, board getting bigger

        for (int i =0; i < 3; i ++) {
            vector<char>row;
            for (int j =0; j <3; j++) {
                row.push_back(symbolNumber); //add row
                symbolNumber ++;
            }
            gameboard.push_back(row);
        }
    }

    void displayBoard() {
        for (int i =0; i <3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << gameboard[i][j];
               if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "--+---+---" << endl;
        }
    }

    bool isValidMove(int move) {
        int rows = (move-1) / 3;
        int cols = (move - 1) % 3;

        if (1>move || move > 9) {
            cout << "Invalid input. Plz enter a number between 1 and 9" << endl;
            return false;
        }else if (gameboard[rows][cols] == 'X' || gameboard[rows][cols] == 'O' ) {
            cout << "Here is already taken. try again" << endl;
            return false;
        }else {
            return true;
        }
    }

    void updateBoard(int move) {
        int rows = (move-1) / 3;
        int cols = (move - 1) % 3;

        gameboard[rows][cols] = currentPlayer;

    }

    void switchPlayer() {
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        }else {
            currentPlayer = 'X';
        }
    }

    bool checkWin(){
        //rows
         for(int i = 0; i < 3; i++){
             if (gameboard[i][0] == currentPlayer &&
                 gameboard[i][1] == currentPlayer &&
                 gameboard[i][2] == currentPlayer)
                 return true;
        }
        //cols
        for (int i =0; i<3; i++) {
            if (gameboard[0][i] == currentPlayer &&
                gameboard[1][i] == currentPlayer &&
                gameboard[2][i] == currentPlayer)
                return true;
        }

        //diagonals
        if (gameboard[0][0] == currentPlayer &&
            gameboard[1][1] == currentPlayer &&
            gameboard[2][2] == currentPlayer)
            return true;

        if (gameboard[0][2] == currentPlayer &&
            gameboard[1][1] == currentPlayer &&
            gameboard[2][0] == currentPlayer)
            return true;
    }

    bool checkDraw() {
        //all board full? false: not full / true : already full as symbols O,X
        for (int i =0; i <3; i++) {
            for (int j = 0; j < 3; j++) {
                if (gameboard[i][j] != 'O' && gameboard[i][j] != 'X'){
                    return false;
                }
            }
        }
        return true;
    }



    void play() {
        cout << "👾👾👾TicTacToe game👾👾👾" << endl;

        char playAgain = 'Y';
        while (playAgain == 'y' || playAgain =='Y') {
            resetBoard();
            displayBoard();

            bool gameEnded = false;

            while (!gameEnded) {
                cout << "It's " << currentPlayer << "turn. Pick a spot (1-9) to place your symbol: " ;
                int spot;
                cin >> spot;

                if (isValidMove(spot) == true) {
                    updateBoard(spot);
                    displayBoard();

                    //check win?
                    if (checkWin()) {
                        cout << currentPlayer << "is win" << endl;
                        gameEnded = true;
                    }
                    else if (checkDraw()) {
                        cout << "This is game draw" << endl;
                        gameEnded = true;
                    }
                    else {
                        switchPlayer();
                    }
                }
            }
            cout << "Play again ? (Y/N): ";
            cin >> playAgain;
        }
        cout << "Game Ended Bye :) " << endl;
    }



};

int main() {
    TicTacToe game;

    game.play();


    return 0;
}
