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
        gameboard.clear(); //reset gameboard. otherwise, board getting bigger
        char symbolNumber = '1'; // why char ? cuz vector<vector<char>> gameboard

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



    void play() {
        cout << "👾👾👾TicTacToe game👾👾👾" << endl;

        resetBoard();
        displayBoard();

    }



};

int main() {
    TicTacToe game;

    game.play();


    return 0;
}
