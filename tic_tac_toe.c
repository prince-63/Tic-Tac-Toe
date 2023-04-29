//        ||       ||
//    1   ||   2   ||   3
//  _____ || _____ || _____
//        ||       ||
//    4   ||   5   ||   6
//  _____ || _____ || _____
//        ||       ||
//    7   ||   8   ||   9
//        ||       ||

#include <stdio.h>
void printBoard();
void winner();

// board structure
char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void main()
{
  printBoard();

  int player = 1;
  char input;
  int status = -1;
  int position;
  int positionStore[10];

  // count boxes
  int count = 1;

  // applying while and input user given character;
  while (status == -1)
  {
    // check player
    player = (player % 2 == 0) ? 2 : 1;

    if (player == 1)
    {
      printf("\nEnter player 1 response -> \n");
    }
    else
    {
      printf("\nEnter player 2 response -> \n");
    }

    // input player response
    input = (player == 1) ? 'X' : 'O';

    // position input by user where are you place
    printf("\n position : ");
    scanf("%d", &position);

    // checking valid or not
    if (position >= 1 && position <= 9)
    {

      // if position alredy exists the give error and enter again position by user.
      for (int i = 1; i <= count; i++)
      {
        if (positionStore[i] == position)
        {
          printf("\nEnter valid position this position alredy exist.\n");
          player--;
          count--;
          break;
        }
      }

      positionStore[count] = position;
      board[position] = input;
      player++;
      count++;
      printBoard();
    }
    else
    {
      printf("Enter right position.\n");
    }

    if (count == 10)
    {
      status = 1;
    }
  }

  printf("Final: \n");
  printBoard();
  winner();
}

// UI structure
void printBoard()
{
  printf("\n");
  printf("       ||       ||       \n");
  printf("   %c   ||   %c   ||   %c  \n", board[1], board[2], board[3]);
  printf(" _____ || _____ || _____ \n");
  printf("       ||       ||       \n");
  printf("   %c   ||   %c   ||   %c  \n", board[4], board[5], board[6]);
  printf(" _____ || _____ || _____ \n");
  printf("       ||       ||       \n");
  printf("   %c   ||   %c   ||   %c  \n", board[7], board[8], board[9]);
  printf("       ||       ||       \n");
  printf("\n");
}

// winner diside
void winner()
{
  int ans = 0;
  char player = 'X';
  int players = 1;
  int playerOneCount = 1;
  int playerTwoCount = 1;

  // if index = 0 to index = 2 are equal then check which character equal
  // and after deside player winner
  if (board[1] == board[2] && board[2] == board[3])
  {
    if (player == board[1])
    {
      players = 1;
      playerOneCount++;
    }
    else
    {
      players = 2;
      playerTwoCount++;
    }
  }

  // if index = 3 to index = 5 are equal then check which character equal
  // and after deside player winner
  if (board[4] == board[5] && board[5] == board[6])
  {
    if (player == board[4])
    {
      players = 1;
      playerOneCount++;
    }
    else
    {
      players = 2;
      playerTwoCount++;
    }
  }

  // if index = 6 to index = 8 are equal then check which character equal
  // and after deside player winner
  if (board[7] == board[8] && board[8] == board[9])
  {
    if (player == board[7])
    {
      players = 1;
      playerOneCount++;
    }
    else
    {
      players = 2;
      playerTwoCount++;
    }
  }

  // if index = 1, index = 4, index = 8 are equal then check which character equal
  // and after deside player winner
  if (board[1] == board[5] && board[5] == board[9])
  {
    if (player == board[1])
    {
      players = 1;
      playerOneCount++;
    }
    else
    {
      players = 2;
      playerTwoCount++;
    }
  }

  // if index = 2, index = 4, index = 6 are equal then check which character equal
  // and after deside player winner
  if (board[3] == board[5] && board[5] == board[7])
  {
    if (player == board[3])
    {
      players = 1;
      playerOneCount++;
    }
    else
    {
      players = 2;
      playerTwoCount++;
    }
  }

  // if index = 0, index = 3, index = 6 are equal then check which character equal
  // and after deside player winner
  if (board[1] == board[4] && board[4] == board[7])
  {
    if (player == board[1])
    {
      players = 1;
      playerOneCount++;
    }
    else
    {
      players = 2;
      playerTwoCount++;
    }
  }

  // if index = 2, index = 5, index = 8 are equal then check which character equal
  // and after deside player winner
  if (board[3] == board[6] && board[6] == board[9])
  {
    if (player == board[3])
    {
      players = 1;
      playerOneCount++;
    }
    else
    {
      players = 2;
      playerTwoCount++;
    }
  }

  if (playerOneCount == playerTwoCount)
  {
    printf("\nmatch drow.\n");
  }
  else if (players == 1 && playerOneCount > playerTwoCount)
  {
    printf("\nplayer 1 is winner.\n");
  }
  else if (players == 2 && playerTwoCount > playerOneCount)
  {
    printf("\n\npplayer 2 is winner.\n\n");
  }
}
