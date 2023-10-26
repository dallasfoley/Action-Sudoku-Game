/**
 * @file BoardTest.cpp
 * @author Joseph Renas
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Board.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

using namespace std;

/**
 * Test class for Board class
 */
class BoardTest : public ::testing::Test {
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


TEST_F(BoardTest, Load) {
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
}