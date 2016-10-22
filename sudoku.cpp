#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function*/
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++)
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}
/* add your functions here */


/*Function to determine whether the board is complete. Returns 1 if the borad
is complete. */
bool is_complete(const char board[9][9]){
  for (int column=0; column<9; column++) {
    for (int row=0; row<9; row++){
      if(board[row][column]=='.'){
        return 0;
      }
    }
  }
  return 1;
}


/*Function to check the validity of both "position" and "digit". Returns 1
if both postion and digit are valid.*/
bool make_move(const char* position, char digit, char board[9][9]){
  int row, column;

  /*Check the "position" validity*/
  if (position[0]<'A' || position[0]>'I'){
    return 0;
  }else if (position[1]<'1' || position[1]> '9') {
    return 0;
  }else if (!isdigit(digit)){
    return 0;
  }

  /*Convert "posintion" from char to int (from 0 to 8 for both column and row)*/
  row = static_cast<int>(position[0]) - 65;
  column = static_cast<int>(position[1]) - 49;

  /*Check the digit validity*/
  if(!is_valid(row, column, digit, board)){
    return 0;
  }
  board[row][column] = digit;
  return 1;
}


/* A helper function of "make_move", determining the digit validity. Returns 1
if the digit is valid in the position.*/
bool is_valid(int row, int column, char digit, const char board[9][9]){
  /*Check for its column returns 0 if conflict is found.*/
  for (int i = 0; i < 9; ++i) {
    if (board[row][i]==digit) {
      return 0;
    }
  }

  /*Check for its row, returns 0 if conflict is found.*/
  for (int i = 0; i < 9; ++i) {
    if (board[i][column]==digit) {
      return 0;
    }
  }

  /*Check for its sub-board  by locating the sub-board that the positon
   belongs to first. Returns 0 if conflict is found.*/
  if(row/3==0){
    if(column/3==0){
      if(!is_valid_in_sub_borad(0,2,0,2,digit,board)){
        return 0;
      }
    }else if(column/3==1){
      if(!is_valid_in_sub_borad(0,2,3,5,digit,board)){
        return 0;
      }
    }else if(column/3==2){
      if(!is_valid_in_sub_borad(0,2,6,8,digit,board)){
        return 0;
      }
    }
  }
  else if (row/3==1){
    if(column/3==0){
      if(!is_valid_in_sub_borad(3,5,0,2,digit,board)){
        return 0;
      }
    }else if(column/3==1){
      if(!is_valid_in_sub_borad(3,5,3,5,digit,board)){
        return 0;
      }
    }else if(column/3==2){
      if(!is_valid_in_sub_borad(3,5,6,8,digit,board)){
        return 0;
      }
    }
  }
  else if (row/3==2){
    if(column/3==0){
      if(!is_valid_in_sub_borad(6,8,0,2,digit,board)){
        return 0;
      }
    }else if(column/3==1){
      if(!is_valid_in_sub_borad(6,8,3,5,digit,board)){
        return 0;
      }
    }else if(column/3==2){
      if(!is_valid_in_sub_borad(6,8,6,8,digit,board)){
        return 0;
      }
    }
  }
  return 1;
}


/*A helper function of "is_valid", determining the validity of the digit
 within its sub-borad. Returns 1 if the digit is valid inside its sub-borad.*/
bool is_valid_in_sub_borad(int row_1, int row_2, int column_1, int column_2, char digit, const char board[9][9]){
  for(int i=row_1; i<=row_2; i++){
    for(int j=column_1; j<=column_2; j++){
      if(board[i][j]==digit){
        return 0;
      }
    }
  }
  return 1;
}


/*Function to ouput the board in a .dat file, returns 1 if success.*/
bool save_board(const char* filename, const char board[9][9]){
  ofstream output;
  output.open(filename);
  if(!output){
    return 0;
  }

  for(int r=0; r<9; r++){
    for(int c=0; c<9; c++){
      output<<board[r][c];
      if(c==8){
        output<<endl;
      }
    }
  }
  output.close();
  return 1;
}


/*Function to solve board, returns 1 if a solution is found.*/
bool solve_board(char board[9][9]){
  int row, column;
  row=0;
  column=0;
  char current_position = board[row][column];

  /*Find the first unfilled position, return 1 if the borad is complete*/
  while(current_position != '.'){
    if(column==8 && row<8){
      row++;
      column=0;
    }else if(is_complete(board)){
      return 1;
    }else{
      column++;
    }
    current_position = board[row][column];
  }

  /*Converting the postion from int to char*/
  char position_char[2];
  position_char[0] = static_cast<char>(row+65);
  position_char[1] = static_cast<char>(column+49);

  /*Filling the position by attempting from digit 1 to 9 until it is valid
   in the postion, then calls the solve_board again to solve the next unfilled
   position.*/
  for(char attempt = '1'; attempt <='9'; attempt++){
    if(make_move(position_char, attempt, board)){
      if(solve_board(board)){
          return 1;
      }
    }
  }

  /*If none of the digit works, changing to position back to an unfilled state
  and returning 0.*/
  board[row][column] = '.';
  return 0;
}
