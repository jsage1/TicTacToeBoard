/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

////turn change tests/////
TEST(TicTacToeBoardTest, oneturnchange)
{
	TicTacToeBoard Game;
	
	Piece returned = Game.toggleTurn();
	Piece test = O;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, tenturnchange)
{
	TicTacToeBoard Game;
	
	Game.toggleTurn();//1 o
	Game.toggleTurn();//2 x
	Game.toggleTurn();//3 o
	Game.toggleTurn();//4 x
	Game.toggleTurn();//5 o
	Game.toggleTurn();//6 x
	Game.toggleTurn();//7 o
	Game.toggleTurn();//9 x
	Piece returned = Game.toggleTurn();//10 o
	Piece test = O;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getemptyboard)
{
	TicTacToeBoard Game;
	
	Piece returned = Game.getPiece(0,0);
	Piece test = Blank;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getpiece)
{
	TicTacToeBoard Game;
	
	Piece returned = Game.getPiece(0,0);
	Piece test = Blank;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getinvalidboard)
{
	TicTacToeBoard Game;
	Game.placePiece(1, 1);
	Piece returned = Game.getPiece(1,1);
	Piece test = O;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getinvalidplace)
{
	TicTacToeBoard Game;
	
	Piece returned = Game.placePiece(5, 5);
	Piece test = Invalid;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getwinneremptyboard)
{
	TicTacToeBoard Game;
	Piece returned = Game.getWinner();
	Piece test = Blank;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getwinnercatsboard)
{
	TicTacToeBoard Game;
	Game.placePiece(0, 0);
	Game.placePiece(0, 1);
	Game.placePiece(1, 1);
	Game.placePiece(2, 2);
	Game.placePiece(1, 2);
	Game.placePiece(1, 0);
	Game.placePiece(0, 2);
	Game.placePiece(2, 0);
	Game.placePiece(2, 1);
	
	char returned = Game.getWinner();
	char test = '?';
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getwinnerhalfboard)
{
	TicTacToeBoard Game;
	Game.placePiece(0, 0);
	Game.placePiece(2, 2);
	Piece returned = Game.getWinner();
	Piece test = Blank;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getwinnerdiagonal)
{
	TicTacToeBoard Game;
	Game.placePiece(1, 1);
		Game.toggleTurn();
	Game.placePiece(0, 0);
		Game.toggleTurn();
	Game.placePiece(2, 2);
	Piece returned = Game.getWinner();
	Piece test = O;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getwinnerdiagonal2)
{
	TicTacToeBoard Game;
	Game.placePiece(0, 2);
		Game.toggleTurn();
	Game.placePiece(1, 1);
		Game.toggleTurn();
	Game.placePiece(2, 0);
	Piece returned = Game.getWinner();
	Piece test = O;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getwinnervert)
{
	TicTacToeBoard Game;
	Game.placePiece(0, 1);
		Game.toggleTurn();
	Game.placePiece(0, 0);
		Game.toggleTurn();
	Game.placePiece(0, 2);
	Piece returned = Game.getWinner();
	Piece test = O;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getwinnerhorizontal)
{
	TicTacToeBoard Game;
	Game.placePiece(1, 0);
		Game.toggleTurn();
	Game.placePiece(0, 0);
		Game.toggleTurn();
	Game.placePiece(2, 0);
	Piece returned = Game.getWinner();
	Piece test = O;
	ASSERT_EQ(returned, test);
}


TEST(TicTacToeBoardTest, twopiecessamespot)
{
	TicTacToeBoard Game;
	Game.placePiece(0, 0);
	Piece returned = Game.placePiece(0, 0);
	Piece test = O;
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, PlacingAfterGameOver)
{
	TicTacToeBoard Game;
	Game.placePiece(1, 1);
		Game.toggleTurn();
	Game.placePiece(0, 0);
		Game.toggleTurn();
	Game.placePiece(2, 2);
	Piece returned = Game.placePiece(2, 1);
	Piece test = Blank;
	ASSERT_EQ(returned, test);
}
