/**
 * @file ScoreboardTest.cpp
 * @author rohch
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Game.h>
#include <Scoreboard.h>

using namespace std;

/**
 * Test class for Scoreboard class
 */
class ScoreboardTest : public Scoreboard {
public:
    ScoreboardTest() : Scoreboard(){}

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {}

};

TEST(ScoreboardTest, Construct){

    // Construct a Scoreboard to test
    ScoreboardTest scoreboard;

    // Test initial values
    ASSERT_EQ(scoreboard.GetDuration(), 0);

}

TEST(ScoreboardTest, Update){
    // Construct a Scoreboard to test
    ScoreboardTest scoreboard;

    // Test initial values
    ASSERT_EQ(scoreboard.GetDuration(), 0);

    // Test Update
    scoreboard.Update(10);
    ASSERT_EQ(scoreboard.GetDuration(), 10);

    // Test Update
    scoreboard.Update(20);
    ASSERT_EQ(scoreboard.GetDuration(), 30);

    // Test Update
    scoreboard.Update(30);
    ASSERT_EQ(scoreboard.GetDuration(), 60);

}

TEST(ScoreboardTest, Reset){
    // Construct a Scoreboard to test
    ScoreboardTest scoreboard;

    // Test initial values
    ASSERT_EQ(scoreboard.GetDuration(), 0);

    // Test Update
    scoreboard.Update(10);
    ASSERT_EQ(scoreboard.GetDuration(), 10);

    // Test Update
    scoreboard.Update(20);
    ASSERT_EQ(scoreboard.GetDuration(), 30);

    // Test Update
    scoreboard.Update(30);
    ASSERT_EQ(scoreboard.GetDuration(), 60);

    // Test Reset
    scoreboard.Reset();
    ASSERT_EQ(scoreboard.GetDuration(), 0);

}