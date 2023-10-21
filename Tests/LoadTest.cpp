/**
 * @file LoadTest.cpp
 * @author Joseph Renas
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

using namespace std;

class GameTest : public ::testing::Test {
protected:
    /**
    * Read a file into a wstring and return it.
    * @param filename Name of the file to read
    * @return File contents
    */
    wstring ReadFile(const wxString &filename)
    {
        ifstream t(filename.ToStdString());
        wstring str((istreambuf_iterator<char>(t)),
                    istreambuf_iterator<char>());

        return str;
    }
};


TEST_F(GameTest, Load) {
    //std::cout << ReadFile(L"levels/level0.xml").length();
    // Test that the file is getting read by asserting that the file has the right length
    wstring filename = L"levels/level0.xml";
    ASSERT_EQ(ReadFile(filename).length(), 5405);

    wxXmlDocument xmlDoc;
    xmlDoc.Load(filename);
    auto root = xmlDoc.GetRoot();

    std::cout << root->GetName();

    auto child = root->GetChildren();

    //Make sure that the node is declarations
    ASSERT_EQ(child->GetName(), "declarations");

    // the first declaration has id "i362", assure that that is what we are getting.
    auto firstSuperChild = child->GetChildren();
    ASSERT_EQ(firstSuperChild->GetAttribute(L"id"), L"i362" );

    Game game;

    game.Load(filename);
    // check to see if the game has the amount of declarations we expect
    ASSERT_EQ(game.GetMapLength(), 18);
}