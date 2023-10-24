/**
 * @file Wildcard.cpp
 * @author Chirag Solanki
 */

#include "SpeedPotion.h"
#include "Game.h"
//#include "Sparty.h"
#include <iostream>
#include "wx/bitmap.h"

using namespace std;



// Static initialization of the random number generator
std::mt19937 SpeedPotion::mRNG = std::mt19937(std::random_device{}());


//just experimenting with this
/*SpeedPotion::SpeedPotion(Game* game) : Item(game, L"images/speedpotion.png"), mGame(game) {
    GenerateSpeedModifier();
}*/



const wstring speedPotionImage = L"images/speedpotion.png";

/**
 * Constructor for SpeedPotion
 * @param game
 */
// for this to work we must enable default constructor in Item.h
/*SpeedPotion::SpeedPotion(Game *game)
{
    mGame=game;
    mImage = make_unique<wxImage>(speedPotionImage, wxBITMAP_TYPE_ANY);
    mBitmap = make_unique<wxBitmap>(*mImage);
}
*/

/**
 * Destructor for SpeedPotion
 */
SpeedPotion::~SpeedPotion()
{
}

/**
 * Draw the SpeedPotion
 * @param graphics The graphics context to draw on
 */
void SpeedPotion::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mBitmap->GetWidth();
    double hit = mBitmap->GetHeight();
    graphics->DrawBitmap(*mBitmap,
                         (mX),
                         (mY),
                         wid,
                         hit);
}

void SpeedPotion::Update(double elapsed) {
    // Logic for updating the speed potion (dont know if needed)
    // For instance, movement, animation, disappearance after time, etc.
}

//void SpeedPotion::AffectSparty() {
    //auto sparty = mGame->GetSparty();
    //if (sparty) {
        //double newSpeed = sparty->GetSpeed() + mSpeedModifier; // Compute new speed
        //sparty->SetSpeed(newSpeed); // Set new speed

    //this is just in case, Probably not needed
    //} else {
        //std::cerr << "Error: Sparty object not found in game." << std::endl;
    //}
//}


void SpeedPotion::GenerateSpeedModifier() {
    // Randomly generate a speed modifier
    std::uniform_real_distribution<> distr(-0.5, 1.5); // Range based on our design
    mSpeedModifier = distr(mRNG);
}



