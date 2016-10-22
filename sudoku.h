#ifndef SUDOKU_H
#define SUDOKU_H

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]);

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]);
void print_frame(int row);
void print_row(const char* data, int row);

/*Function to determine whether the board is complete*/
bool is_complete(const char board[9][9]);

/*Function to check the validity of both "position" and "digit"*/
bool make_move(const char* position, char digit, char board[9][9]);
/* A helper function of "make_move", determining the digit validity*/
bool is_valid(int row, int column, char digit, const char board[9][9]);
/*A helper function of "is_valid", determining the validity of the digit
 within its sub-borad.*/
bool is_valid_in_sub_borad(int row_1, int row_2, int column_1, int column_2, char digit, const char board[9][9]);

/*Function to ouput and save the board in a .dat file*/
bool save_board(const char* filename, const char board[9][9]);

/*Function to solve board*/
bool solve_board(char board[9][9]);

#endif
