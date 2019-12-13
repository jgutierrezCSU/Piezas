/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest,initRESET) {
  Piezas Board;
  Board.reset();
  ASSERT_EQ(Board.dropPiece(0), X);
}
TEST(PiezasTest, dropPieceForO) {
  Piezas Board;
  Board.dropPiece(0);
  ASSERT_EQ(Board.dropPiece(0), O);
}
TEST(PiezasTest, dropPieceForX) {
  Piezas Board;
  ASSERT_EQ(Board.dropPiece(0), X);
}
TEST(PiezasTest, doubleDrop)
{
  Piezas Board;
  Board.dropPiece(1);
  ASSERT_EQ(Board.dropPiece(1), O);
}
TEST(PiezasTest, placePieceWhenEmpty)
{
  Piezas Board;
  ASSERT_EQ(Board.pieceAt(0,0), Blank);
  ASSERT_EQ(Board.pieceAt(0,3), Blank);
  ASSERT_EQ(Board.pieceAt(2,3), Blank);
  ASSERT_EQ(Board.pieceAt(2,0), Blank);
}
TEST(PiezasTest, GameStateOnBlank) {
  Piezas Board;
  ASSERT_EQ(Board.gameState(), Invalid);
}
TEST(PiezasTest, GSTie)
{
    Piezas Board;
    Board.dropPiece(0); 
    Board.dropPiece(1);
    Board.dropPiece(0); 
    Board.dropPiece(1); 
    Board.dropPiece(0); 
    Board.dropPiece(1);
    Board.dropPiece(2); 
    Board.dropPiece(2);
    Board.dropPiece(2); 
    Board.dropPiece(3);
    Board.dropPiece(3); 
    Board.dropPiece(3);
    ASSERT_EQ(Board.gameState(), Blank);
}
TEST(PiezasTest, XvertWin)
{
    Piezas Board;
    Board.dropPiece(0); 
    Board.dropPiece(0);
	
    Board.dropPiece(1); 
    Board.dropPiece(0); 
    Board.dropPiece(2); 
    Board.dropPiece(1);
	
    Board.dropPiece(3); 
    Board.dropPiece(1);
    Board.dropPiece(2); 
    Board.dropPiece(3);
    Board.dropPiece(3); 
    Board.dropPiece(2);
    ASSERT_EQ(Board.gameState(), X);
}
