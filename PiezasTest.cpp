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
TEST(PiezasTest, StartThenReset) {
    Piezas Board;
    Board.dropPiece(2);
    Board.reset();
    ASSERT_EQ(Board.pieceAt(0, 2), Blank);
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
TEST(PiezasTest, XWins)
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
TEST(PiezasTest, OWins){
  Piezas Board;
  Board.dropPiece(0);
  Board.dropPiece(1);
  Board.dropPiece(0);
  Board.dropPiece(1);
  Board.dropPiece(1);
	
  Board.dropPiece(0);
  Board.dropPiece(2);
  Board.dropPiece(2);
	
  Board.dropPiece(3);
  Board.dropPiece(3);
  Board.dropPiece(2);
  Board.dropPiece(3);
  ASSERT_EQ(Board.gameState(), O);
}
TEST(PiezasTest, OutOfBounds44)
{
    Piezas Board;
    ASSERT_EQ(Board.pieceAt(4,4), Invalid);
}
TEST(PiezasTest, OutOfBoundsNeg11)
{
    Piezas Board;
    ASSERT_EQ(Board.pieceAt(-1,-1), Invalid);
}
TEST(PiezasTest, DropPieceMultiple) {
  Piezas Board;
  Board.dropPiece(0);
  Board.dropPiece(0);
  Board.dropPiece(0);
  ASSERT_EQ(Board.dropPiece(0), Blank);
}
TEST(PiezasTest, OutOfBoundsNeg1)
{
    Piezas Board;
    ASSERT_EQ(Board.dropPiece(-1), Invalid);
}

TEST(PiezasTest, OutOfBoundsPos4)
{
    Piezas Board;
    ASSERT_EQ(Board.dropPiece(4), Invalid);
}



