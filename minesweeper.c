

// Assignment 1 20T1 COMP1511: Minesweeper
// minesweeper.c
//
// This program was written by Calvin Li (z5242094)
// on 12.03.2020
//
// Version 1.0.0 (2020-03-08): Assignment released.
// Version 1.0.1 (2020-03-08): Fix punctuation in comment.
// Version 1.0.2 (2020-03-08): Fix second line of header comment to say minesweeper.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Possible square states.
#define VISIBLE_SAFE    0
#define HIDDEN_SAFE     1
#define HIDDEN_MINE     2

// The size of the starting grid.
#define SIZE 8

// The possible command codes.
#define DETECT_ROW              1
#define DETECT_COL              2
#define DETECT_SQUARE           3
#define REVEAL_SQUARE           4
#define GAMEPLAY_MODE           5
#define DEBUG_MODE              6
#define REVEAL_RADIAL           7

// Add any extra #defines here.

void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);
int detect_row (int array[SIZE][SIZE], int n);
int detect_col(int array[SIZE][SIZE], int n);

// Place your function prototyes here.

int main(void) {
    int minefield[SIZE][SIZE];
    int total_mines = 0;
    initialise_field(minefield);
    printf("Welcome to minesweeper!\n");
    printf("How many mines? ");
    scanf("%d", &total_mines);
    // TODO: Scan in the number of pairs of mines.
    printf("Enter pairs:\n");
    int pair_counter = 0;
    int i = 0;
    int j = 0;

    // TODO: Scan in the pairs of mines and place them on the grid.
    while (pair_counter < total_mines) {
        if (i >= 0 && i < SIZE) {
            scanf("%d %d", &i, &j);
            minefield[i][j] = HIDDEN_MINE;
            pair_counter++;

        } else if (j >= 0 && j < SIZE) {
            scanf("%d %d", &i, &j);
            minefield[i][j] = HIDDEN_MINE;
            pair_counter++;
        } else {
            return 0;
        }

    }
    printf("Game Started\n");
    print_debug_minefield(minefield);

    // TODO: Scan in commands to play the game until the game ends.
    // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
    // You should display the minefield after each command has been processed.

    int gameover = 0;
    while (gameover == 0) {
      int command = 0;
      int action = 0;
      j = 0;
      i = 0;
      scanf("%d", &command);
      // Code below is detecting rows and columns;
    //******************************************************************************
      if (command == DETECT_ROW) {
          scanf("%d", &action);
          detect_row (minefield, action);
          printf("There are %d mine(s) in row %d\n", detect_row (minefield, action), action);
          j = 0;
          print_debug_minefield(minefield);

      } else if (command == DETECT_COL) {

            scanf("%d", &action);
            detect_col (minefield, ip);
            printf("There are %d mine(s) in column %d\n", detect_col (minefield, action), action);
            i = 0;
            print_debug_minefield(minefield);

                // Code below detecs square:
    //******************************************************************************

            } else if (command  == DETECT_SQUARE) {

                int row = 0;
                int col = 0;
                int size = 0;
                scanf("%d %d %d", &row, &col, &size);
                int move = (size - 1)/2;
                int pos_row = row;
                int pos_col = col;
                int up_lim = row - move;
                int down_lim = row + move;
                int right_lim = col + move;
                int left_lim = col - move;
                int counter1 = 0;
                int counter2 = 0;

                while (row >= up_lim) {
                    col = left_lim;
                    while (col <= right_lim) {
                        if (minefield[row][col] == HIDDEN_MINE) {
                            counter1++;
                        }
                        col++;
                    }
                    row--;
                }
                row = pos_row + 1;
                while (row <= down_lim && row < SIZE) {
                    col = left_lim;
                    while (col <= right_lim) {
                        if (minefield[row][col] == HIDDEN_MINE) {
                            counter2++;
                        }
                        col++;
                    }
                    row++;
                }
                int sum = counter1 + counter2;
                printf("There are %d mine(s) in the square centered at row %d, column %d of size %d\n", sum, pos_row, pos_col, size);
                print_debug_minefield(minefield);

                // Code below reveals the square
    //******************************************************************************

            } else if (command == REVEAL_SQUARE) {
                int row = 0;
                int col = 0;
                scanf("%d %d", &row, &col);
                if (minefield[row][col] == HIDDEN_MINE) {
                    printf("Game over\n");
                    print_debug_minefield(minefield);
                    gameover = 1;
                } else if (minefield[row][col] != HIDDEN_MINE) {
                // Detect square:
                    int move = 1;
                    int pos_row = row;
                    int pos_col = col;
                    int up_lim = row - move;
                    int down_lim = row + move;
                    int right_lim = col + move;
                    int left_lim = col - move;
                    int counter1 = 0;
                    int counter2 = 0;
                    if (up_lim < 0) {
                        up_lim = 0;
                    } else if (down_lim >= SIZE) {
                        down_lim = SIZE - 1;
                    } else if ( left_lim < 0) {
                        left_lim = 0;
                    } else if (right_lim >= SIZE) {
                        right_lim = SIZE - 1;
                    }
                    while (row >= up_lim) {
                        if (up_lim < 0) {
                            up_lim = 0;
                        } else if (down_lim >= SIZE) {
                            down_lim = SIZE - 1;
                        } else if ( left_lim < 0) {
                            left_lim = 0;
                        } else if (right_lim >= SIZE) {
                            right_lim = SIZE - 1;
                        }
                        col = left_lim;
                        while (col <= right_lim && col >= 0) {
                            if (up_lim < 0) {
                                up_lim = 0;
                             } else if (down_lim >= SIZE) {
                                 down_lim = SIZE - 1;
                             } else if ( left_lim < 0) {
                                 left_lim = 0;
                             } else if (right_lim >= SIZE) {
                                 right_lim = SIZE - 1;
                             }
                            if (minefield[row][col] == HIDDEN_MINE) {
                                counter1++;
                            }
                            col++;
                            }
                        row--;
                    }
                    row = pos_row + 1;
                    while (row <= down_lim) {
                        if (up_lim < 0) {
                            up_lim = 0;
                        } else if (down_lim >= SIZE) {
                            down_lim = SIZE - 1;
                        } else if ( left_lim < 0) {
                            left_lim = 0;
                        } else if (right_lim >= SIZE) {
                            right_lim = SIZE - 1;
                        }
                        col = left_lim;
                        while (col <= right_lim && col <= SIZE) {
                             if (up_lim < 0) {
                                  up_lim = 0;
                             } else if (down_lim >= SIZE) {
                                 down_lim = SIZE - 1;
                             } else if ( left_lim < 0) {
                                 left_lim = 0;
                             } else if (right_lim >= SIZE) {
                                 right_lim = SIZE - 1;
                             }
                            if (minefield[row][col] == HIDDEN_MINE) {
                                counter2++;
                            }
                            col++;
                        }
                        row++;
                    }
                    int sum = counter1 + counter2;
                    row = pos_row;
                    col = pos_col;
                    // Code below considers when there's no adjacent mines, then reveal them all.
                    if (sum == 0) {
                        if (up_lim < 0) {
                            up_lim = 0;
                        } else if (down_lim >= SIZE) {
                            down_lim = SIZE - 1;
                        } else if ( left_lim < 0) {
                            left_lim = 0;
                        } else if (right_lim >= SIZE) {
                            right_lim = SIZE - 1;
                        }
                        while (row >= up_lim && up_lim >= 0) {
                            col = left_lim;
                            while (col <= right_lim) {
                                if (up_lim < 0) {
                                up_lim = 0;
                            } else if (down_lim >= SIZE) {
                                down_lim = SIZE - 1;
                            } else if ( left_lim < 0) {
                                left_lim = 0;
                            } else if (right_lim >= SIZE) {
                                right_lim = SIZE - 1;
                            }
                                minefield[row][col] = VISIBLE_SAFE;
                                col++;
                            }
                            row--;
                        }
                        row = pos_row + 1;

                        while (row <= down_lim && row < SIZE) {

                            col = left_lim;
                            while (col <= right_lim && right_lim < SIZE) {
                                if (up_lim < 0) {
                                    up_lim = 0;
                                } else if (down_lim >= SIZE) {
                                    down_lim = SIZE - 1;
                                } else if ( left_lim < 0) {
                                    left_lim = 0;
                                } else if (right_lim >= SIZE) {
                                    right_lim = SIZE - 1;
                                }
                                minefield[row][col] = VISIBLE_SAFE;
                                col++;
                            }
                            row++;
                        }
                        print_debug_minefield(minefield);
                        row = pos_row;
                        col = pos_col;// End the sum == 0 if.

                    } else if (sum > 0) {
                        minefield[row][col] = VISIBLE_SAFE;
                        print_debug_minefield(minefield);
                    // End of has adjacent mines.
                    }

                }
            }
            else {
                gameover = 1;
            }
            // Code below sets the game won condition.
            // if every element in the grid has been revealed except for the mined one
            // then game won!
            int one_counter = 0;
            i = 0;
            while (i < SIZE) {
                j = 0;
                while (j < SIZE) {
                    if (minefield[i][j] == 1) {
                        one_counter++;
                    }
                    j++;
                }
                i++;
            }
            if (one_counter == 0) {
                printf("Game Won!\n");
                gameover = 1;
            }

        }//end while








  return 0;
}

// Set the entire minefield to HIDDEN_SAFE.
void initialise_field(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            minefield[i][j] = HIDDEN_SAFE;
            j++;
        }
        i++;
    }
}

// Print out the actual values of the minefield.
void print_debug_minefield(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", minefield[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

// detect rows and count the number of mines.
int detect_row (int array[SIZE][SIZE], int n) {

     int j = 0;
     int num_mines = 0;
     while (j < SIZE) {
         if (array[n][j] == HIDDEN_MINE) {
             num_mines++;
         }//end if
         j++;
     }// end while
     return num_mines;
}

// detect columns and count the number of mines.
int detect_col (int array[SIZE][SIZE], int n) {

     int i = 0;
     int num_mines = 0;
     while (i < SIZE) {
         if (array[i][n] == HIDDEN_MINE) {
             num_mines++;
         }//end if
         i++;
     }// end while
     return num_mines;
}


int detect_square (int array[SIZE][SIZE], int *m, int *n, int *k) {
    int i = *m;
    int j = *n;
    int move = (*k - 1)/2;
    int up_lim = i - move;
    int down_lim = i + move;
    int right_lim = j + move;
    int left_lim = j - move;
    int counter1 = 0;
    int counter2 = 0;

    while (j > up_lim && j > 0) {
        j = left_lim;
        while (j <= right_lim && j < SIZE) {
            if (array[i][j] == HIDDEN_MINE) {
                counter1++;
            }
            j++;
        }
        i--;
    }
    i = *m + 1;
    while (i < down_lim && i > 0) {
        j = left_lim;
        while (j <= right_lim && j < SIZE) {
            if (array[i][j] == HIDDEN_MINE) {
                counter2++;
            }
            j++;
        }
        i++;
    }
    int sum = counter1 + counter2;
    return sum;

}
