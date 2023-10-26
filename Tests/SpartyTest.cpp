///**
// * @file SpartyTest.cpp
// * @author rohch
// */
//
//#include <pch.h>
//#include "gtest/gtest.h"
//
//#include <Game.h>
//#include <Sparty.h>
//
//using namespace std;
//
///**
// * Test class for Sparty class
// */
//class SpartyMock : public Sparty {
//public:
//    SpartyMock(Game * game) : Sparty(game) {}
//
//    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {}
//
//};
//
//TEST(SpartyTest, Construct){
//
//    // Construct a Sparty to test
//    Game game;
//    SpartyMock sparty(&game);
//}
//
//TEST(SpartyTest, Movement){
//    // Construct a Sparty to test
//    Game game;
//    SpartyMock sparty(&game);
//
//    // Test initial values
//    ASSERT_EQ(sparty.GetX(), 0);
//    ASSERT_EQ(sparty.GetY(), 0);
//
//    // Test SetLandingPoint, GetX, GetY
//    sparty.SetLandingPoint(100, 200);
//    sparty.Update(10);
//    ASSERT_EQ(sparty.GetX(), 40);
//    ASSERT_EQ(sparty.GetY(), 130);
//
//    // Make sure it doesn't move too far
//    ASSERT_FALSE(sparty.GetX() == 100);
//    ASSERT_FALSE(sparty.GetY() == 200);
//
//    // Test another location
//    sparty.SetLandingPoint(400, 300);
//    sparty.Update(10);
//    ASSERT_EQ(sparty.GetX(), 340);
//    ASSERT_EQ(sparty.GetY(), 230);
//
//}