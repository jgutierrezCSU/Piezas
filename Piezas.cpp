#include "Piezas.h"
#include <vector>
#include <iostream> 
using namespace std; 
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    board.resize(BOARD_ROWS);
	for (int i = 0 ; i < BOARD_ROWS; ++i)
    {
		board[i].resize(BOARD_COLS);
    }
	turn = X;

	for(int i=0; i< BOARD_ROWS; i++)
	{
		for( int j =0; j < BOARD_COLS; j++)
		{
			board[i][j] = Blank;
		}
	}
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
turn = X;
  for (int i = 0; i < BOARD_ROWS; i++)
  {
    	for (int j = 0; j < BOARD_COLS; j++)
	{
      		board[i][j] = Blank;
    	}
  }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
	
	if(column >BOARD_ROWS || column <0)
	{
		if(turn == X)
		{
		  turn = O;
		}
		else{
		   turn = X;
		}
		return Invalid;
	}
	for(int i= 0; i <3; ++i)
	{
		if(board[i][column] == Blank)
		{
			Piece save = turn;
			board[i][column] = turn;
			if(turn == X)
			{
			   turn = O;
			}
			else
			{
			   turn = X;
			}
			return save;
		}
	}
	if(turn == X)
	{
	   turn = O;
	}
	else
	{
	    turn = X;
	}
    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
	
	if( row <0 || row >2 || column <0 || column >3)
	{
		return Invalid;
	}
	else
	return board[row][column];
    return Blank;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    return Blank;
}
