#include <iostream>
#include <cstdio>
#include <ctime>
#include "sudoku.h"
//THIS IS FEATURE ONE!!
using namespace std;


int main() {
  clock_t t;
  char board[9][9];

  // This section illustrates the use of the pre-supplied helper functions.
  cout << "============== Pre-supplied functions ==================" << endl << endl;

  cout << "Calling load_board():" << endl;
  load_board("mystery1.dat", board);

  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;

  cout << "====================== Question 1 ======================" << endl << endl;

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  cout << "====================== Question 2 ======================" << endl << endl;

  load_board("easy.dat", board);
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board))
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
  cout<<endl;

  // write more tests
  //Confliction should be found in its row
  load_board("medium.dat", board);
  cout << "Putting '3' into A5 is ";
  if (!make_move("A5", '3', board))
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
  cout<<endl;

  //Confliction should be found in its column
  load_board("medium.dat", board);
  cout << "Putting '9' into A3 is ";
  if (!make_move("A3", '9', board))
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
  cout<<endl;

  //Confliction should be found in its sub-board
  load_board("medium.dat", board);
  cout << "Putting '5' into B2 is ";
  if (!make_move("B2", '5', board))
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);
  cout<<endl;

  cout << "====================== Question 3 ======================" << endl << endl;

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board)){
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  }
  else{
    cout << "Save board failed." << endl;
  }
  cout << endl;

  cout << "====================== Question 4 ======================" << endl << endl;
  //solve "easy"
  load_board("easy.dat", board);
  t= clock();
  if (solve_board(board)) {
    t=clock()-t;
    cout<<"The time for solving the board is "<<t/static_cast<double>(CLOCKS_PER_SEC)<<"s"<<endl;
    cout << "The 'easy' board has a solution:" << endl;
    display_board(board);
  } else{
    t=clock()-t;
    cout<<"The time for solving the board is "<<t/static_cast<double>(CLOCKS_PER_SEC)<<"s"<<endl;
    cout << "A solution cannot be found." << endl;
  }
  cout << endl;

  //solve "medium"
  load_board("medium.dat", board);
  t= clock();
  if (solve_board(board)) {
    t=clock()-t;
    cout<<"The time for solving the board is "<<t/static_cast<double>(CLOCKS_PER_SEC)<<"s"<<endl;
    cout << "The 'medium' board has a solution:" << endl;
    display_board(board);
  } else{
    t=clock()-t;
    cout<<"The time for solving the board is "<<t/static_cast<double>(CLOCKS_PER_SEC)<<"s"<<endl;
    cout << "A solution cannot be found." << endl;
  }
  cout << endl;

	// write more tests
  //solve "mystery1"
  load_board("mystery1.dat", board);
  t= clock();
  if (solve_board(board)) {
    t=clock()-t;
    cout<<"The time for solving the board is "<<t/static_cast<double>(CLOCKS_PER_SEC)<<"s"<<endl;
    cout << "The 'mystery1' board has a solution:" << endl;
    display_board(board);
  } else{
    t=clock()-t;
    cout<<"The time for solving the board is "<<t/static_cast<double>(CLOCKS_PER_SEC)<<"s"<<endl;
    cout << "A solution cannot be found." << endl;
  }
  cout << endl;

  //solve "mystery2"
  load_board("mystery2.dat", board);
  t= clock();
  if (solve_board(board)) {
    t=clock()-t;
    cout<<"The time for solving the board is "<<t/static_cast<double>(CLOCKS_PER_SEC)<<"s"<<endl;
    cout << "The 'mystery2' board has a solution:" << endl;
    display_board(board);
  } else{
    t=clock()-t;
    cout<<"The time for solving the board is "<<t/static_cast<double>(CLOCKS_PER_SEC)<<"s"<<endl;
    cout << "A solution cannot be found." << endl;
  }
  cout << endl;

  //solve "mystery3"
  load_board("mystery3.dat", board);
  t= clock();
  if (solve_board(board)) {
    t=clock()-t;
    cout<<"The time for solving the board is "<<t/static_cast<double>(CLOCKS_PER_SEC)<<"s"<<endl;
    cout << "The 'mystery3' board has a solution:" << endl;
    display_board(board);
  } else{
    t=clock()-t;
    cout<<"The time for solving the board is "<<t/static_cast<double>(CLOCKS_PER_SEC)<<"s"<<endl;
    cout << "A solution cannot be found." << endl;
  }
  cout << endl;

cout << "====================== Question 5 ======================" << endl << endl;
cout<<"The number of recursions and the runtimes for solving each board have been written in Q4. ";
cout<<"The summary of findings is in 'findings.txt'."<<endl<<endl;



  return 0;
}
