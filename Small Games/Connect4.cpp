#include <iostream>
#include <string>
#include <vector>
#include "cmpt_error.h"
#include <cstdlib>
using namespace std;

char piecedisplay (const vector<vector<int>>& game_board, const int& num1,const int& num2);//This function changes the 0,1,2 on the board to an interface
void gameboard (const vector<vector<int>>& game_board, const vector<char>& char_line);//this function displays the game board
void piecedropper (vector<vector<int>>& game_board, char column_num, char player, bool& check_true);//this function drops the piece to the bottom
int chartoint (char column_num);//this function converts the entered char into an int
bool check_board_full (vector<vector<int>> board);//checks if the board is full
void board_clear (vector<vector<int>>& board);//clears the board (changes all the ints to 0)
bool check_column (vector<vector<int>> board, int user, int column_num);//checks win in a column
bool check_row (vector<vector<int>> board, int user, int row_num);//checks win in a row
bool check_diagonal (vector<vector<int>> board, int user, int column);//checks if there's a diagonal win
bool check_negdiagonal (vector<vector<int>> board, int user, int column);//checks if there's a decending diagonal win
bool check_win (vector<vector<int>> board, int user);//checks all of the win conditions

int main() {
      vector<int> row6 = {0, 0, 0, 0, 0, 0, 0};
      vector<int> row5 = {0, 0, 0, 0, 0, 0, 0};
      vector<int> row4 = {0, 0, 0, 0, 0, 0, 0};
      vector<int> row3 = {0, 0, 0, 0, 0, 0, 0};
      vector<int> row2 = {0, 0, 0, 0, 0, 0, 0};
      vector<int> row1 = {0, 0, 0, 0, 0, 0, 0};
      const vector<char> char_line ={'a', 'b', 'c', 'd', 'e', 'f', 'g'};//used as a number line
      vector<vector<int>> board{row6, row5, row4, row3, row2, row1};//vector of the board
      cout << "Welcome to Connect 4\n"
             << "Your pieces look like 'X'\n"
             << "The Computer's Pieces look like '0'\n";//title
            bool board_full = false;
            bool win = false;
            bool game = true;

      while (game == true){//reapeats the game til completion
            gameboard(board, char_line);//displays board
            while (board_full == false && win == false){ //nested while loop to check for wins and ties
                  cout << "\nYour turn\nChoose a column: ";
                  char column_num;
                  cin >> column_num;
                  if (column_num >= 'a' && column_num <= 'g'){//runs piecedropper if column num is between 1 and 7
                        char player = 'p';//player is the user
                        bool check_true = true;
                        piecedropper(board, column_num, player, check_true);//drops the user piece at the selected column
                        gameboard(board, char_line);
                        if (check_win(board, 2) == true){//checks win
                              check_true = false;
                              win = true;
                              cout << "you win!\n";
                        }
                        if (check_true == true){
                              cout << "\nComputer's Turn \n";
                              player = 'c';//player is the computer
                              piecedropper(board, column_num, player, check_true);//drops the computer piece at a random column
                              gameboard(board, char_line);//displays gameboard
                              if (check_win(board, 1) == true){//checks win
                                    win = true;
                                    cout << "The computer wins this time...\n";
                              }
                        }
                  }else {
                        cout << "\nSorry, that's not a valid column. Please enter a column between 'a' and 'g'!\n\n";//checks valid entry
                        column_num = 0;
                        gameboard(board, char_line);
                  }//else
            board_full = check_board_full(board);
            if (board_full == true){//checks if the board is full
                  cout << "It's a draw!\n";
            }
            }//while board_full
            cout << "game over!\n\n";//end of game

            bool reset = true;
            while (reset == true){//asks the player to start a new game
            cout<< "Would you like to start a new game(Y or N)?";
            char new_game;
            cin >> new_game;
            if (new_game == 'y' || new_game == 'Y'){
                  board_clear(board);
                  board_full = false;
                  win = false;
                  reset = false;
            }else if (new_game == 'n' || new_game == 'N'){
                  game = false;
                  reset = false;
            }else {
                  cout << "that is not a valid response!\n";//asks the player again if imput is unknown
            }
      }//true
      }//while true loop
}//main

char piecedisplay (const vector<vector<int>>& game_board, const int& num1,const int& num2){
      if ( game_board[num1][num2] == 0) return ' ';//if the location is a 0, there is a space
      else if (game_board[num1][num2] == 1) return 'X';//if the location is a 1, there is a X
      else return '0';//if the location is a 2, there is a 0
}//display pieces
void gameboard(const vector<vector<int>>& game_board, const vector<char>& char_line){//this function displays the game board
      cout << "-";
      for (int i = 0; i < char_line.size(); i++){//creates a dotted boarder
            cout << "--";
      }
      cout << "\n";
      for (int i = 0; i < 6; i++){//displays the board with boarders
            cout << ":";
            for( int z = 0; z < 7; z++){
                  cout << piecedisplay(game_board, i, z) << ":";
            }
            cout << "\n";
      }
      cout << "-";
      for (int i = 0; i < char_line.size(); i++){//displays a dotted boarder
            cout << "--";
      }
      cout << "\n";
      cout << " ";
      for (int i = 0; i < char_line.size(); i++){//numbers at the bottom for reference
            cout << char_line[i] << " ";
      }
      cout << "\n";
}//void gameboard
void piecedropper (vector<vector<int>>& game_board, char column_num, char player, bool& check_true){
      int column_num2 = chartoint(column_num);
      if (player == 'p'){//if the player is going
            for (int row_num = 5; row_num >= 0; row_num--){
                  if (row_num == 0){
                        if (game_board[row_num][column_num2] == 1 || game_board[row_num][column_num2] == 2){//checks if the column is full
                              cout << "that column is full! Please choose another column \n";
                              check_true = false;
                        }
                  }
                  if (game_board[row_num][column_num2] == 0){
                        game_board[row_num][column_num2] = 1;//drops piece to the bottom
                        row_num = -2;//exits out loop
                  }
            }//for
      }else if (player == 'c'){//if the computer is going
            bool check_true2 = true;
            srand(time(NULL));
            column_num2 = rand() % 7;//generates a random number from 1-6
            while (check_true2 == true){
                  for (int row_num = 5; row_num >= 0; row_num--){//drops piece to the bottom
                        if (game_board[row_num][column_num2] == 0){
                              game_board[row_num][column_num2] = 2;
                              row_num = -2;
                              check_true2 = false;
                        }else if (row_num == 0){ 
                              column_num2 = rand() % 7;
                        }//do nothing
                  }//for
            }//else if
      }//while true
}//piecedropper
int chartoint (char column_num){
      if (column_num == 'a') return 0;//changes the char a-g to a number between 0 - 6
      else if (column_num == 'b') return 1;
      else if (column_num == 'c') return 2;
      else if (column_num == 'd') return 3;
      else if (column_num == 'e') return 4;
      else if (column_num == 'f') return 5;
      else if (column_num == 'g') return 6;
      else return 8;//never returns
}
void board_clear (vector<vector<int>>& board){
      for (int i = 0; i < 6; i++){//clears board
            for ( int z = 0; z < 7; z++){
                 board[i][z] = 0;
            }
      }
}
bool check_board_full (vector<vector<int>> board){
      int count = 0;
      int row_num = 0;
      for (int column_num = 0; column_num <= 6; column_num++){
            if(board[row_num][column_num] == 1 || board[row_num][column_num] == 2){//checks if the board is full
                  count++;
            }
      }
      if (count == 7){//if all of the rows are full, then count will = 7
            return true;
      }else {
            return false;//if it's not full return false
      }
}//board full
bool check_column (vector<vector<int>> board, int user, int column_num){
            for (int row_num = 0; row_num < 3; row_num++){//chooses one point and looks at 3 pieces above it, if they are all the same return true
                  if (board[row_num][column_num] != 0 && board[row_num][column_num] != user){
                        if (board[row_num + 1][column_num] != 0 && board[row_num + 1][column_num] != user){
                              if (board[row_num + 2][column_num] != 0 && board[row_num + 2][column_num] != user){
                                    if (board[row_num + 3][column_num] != 0 && board[row_num + 3][column_num] != user){
                                          return true;
                                    }
                              }
                        }  
                  }
            }//for
            return false;//return false if no wins could be found
}
bool check_row (vector<vector<int>> board, int user, int row_num){
      for (int column_num = 0; column_num < 4; column_num++){//choses a point and looks at the 3 pieces to the right of it, if all the same return true
            if (board[row_num][column_num] != 0 && board[row_num][column_num] != user){
                  if (board[row_num][column_num + 1] != 0 && board[row_num][column_num + 1] != user){
                        if (board[row_num][column_num + 2] != 0 && board[row_num][column_num + 2] != user){
                              if (board[row_num][column_num + 3] != 0 && board[row_num][column_num + 3] != user){
                                    return true;
                              }
                        }
                  }
            }
      }
      
      return false;//return false if no wins could be found
}
bool check_diagonal(vector<vector<int>> board, int user, int column){
      if (user == 1){//changes the user to reflect your piece number
            user = 2;
      }else if ( user == 2){
            user = 1;
      }
            for (int row = 5; row > 2; row--){//choses a point, looks at the 3 pieces above and to the right of it, if all the same return true;
                  if(board[row][column] == user){
                        if (board[row - 1][column + 1] == user){
                              if ( board[row - 2][column + 2] == user){
                                    if (board[row - 3][column + 3] == user){
                                          return true;
                                    }
                              }
                        }
                  }
                  
            }//for row
      return false;//if none could be found, return false
}
bool check_negdiagonal (vector<vector<int>> board, int user, int column){
      if (user == 1){//changes the number to reflect your piece number
            user = 2;
      }else if ( user == 2){
            user = 1;
      }
            for (int row = 0; row < 3; row++){//choses a point, looks at the 3 pieces below and to the right of it, if all the same return true;
                  if (board[row][column] == user){
                        if (board[row + 1][column + 1] == user){
                              if ( board[row + 2][column + 2] == user){
                                    if (board[row + 3][column + 3] == user){
                                          return true;
                                    }
                              }
                        }
                  }
                  
            }//for row
      return false;//if none could be found return false
}
bool check_win (vector<vector<int>> board, int user){//checks all of the win conditions
      for (int i = 0; i < 7; i++){
            if (check_column(board, user, i) == true){
                  return true;
            }
      }
      for (int i = 0; i < 6; i++){
            if (check_row(board, user, i) == true){
                  return true;
            }
      }
      for (int i = 0; i < 3; i++){
          if(check_diagonal(board, user, i) == true){
            return true;
          }      
      }
      for (int i = 0; i < 3; i++){
          if(check_negdiagonal(board, user, i) == true){
            return true;
          }      
      }
      return false;
}
