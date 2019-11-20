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

TEST(TicTacToeBoardTest, getinvalidboard)
{
	TicTacToeBoard Game;
	
	Piece returned = Game.getPiece(100,100);
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
