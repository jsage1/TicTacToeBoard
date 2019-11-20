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


TEST(TicTacToeBoardTest, oneturnchange)
{
	TicTacToeBoard Game;
	
	char returned = Game.toggleTurn();
	char test = 'O';
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
	char returned = Game.toggleTurn();//10 o
	char test = 'O';
	ASSERT_EQ(returned, test);
}

TEST(TicTacToeBoardTest, getpieceempty)
{
	TicTacToeBoard Game;
	
	Piece returned = game.getPiece(0,0);
	Piece test = ' ';
	ASSERT_EQ(returned, test);
}
