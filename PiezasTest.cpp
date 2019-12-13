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


