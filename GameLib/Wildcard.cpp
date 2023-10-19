/**
 * @file Wildcard.cpp
 * @author Chirag Solanki
 */

#include "Wildcard.h"
#include "Game.h"
#include "Sparty.h"

Wildcard::Wildcard(Game* game)
    : Item(game, L"images/wildcard.png"),  // Need to adjust to what the actual image is named.
      mGame(game) {
    // this generates a random speed modifier
    GenerateSpeedModifier();
}

void Wildcard::Draw(std::shared_ptr<wxGraphicsContext> graphics) {
    double x = GetX(); // Just assuming getX and getY are public getter methods for mX and mY in the Item class
    double y = GetY();
    //graphics->DrawBitmap(*GetImage(), x, y, GetImage()->GetWidth(), GetImage()->GetHeight());
}

void Wildcard::Update(double elapsed) {
    // Will add movement or other logic here later
}

void Wildcard::AffectSparty() {
    // For this I think there needs to be a public method in the Game class to get Sparty, and Sparty has a method to modify its speed.


    //auto sparty = mGame->GetSparty();
    //if (sparty) {
        //sparty->ModifySpeed(mSpeedModifier);
    //}
}






// for above i think we would need to implement this into the game class below (not too sure)
//
//      Sparty* Game::GetSparty() {
//         return mSparty.get();  // Assuming mSparty is a std::unique_ptr<Sparty>
//     }

// I also think we would need to implement this into the sparty class below (not too sure)
//
//     void Sparty::ModifySpeed(double speedModifier) {
//         mSpeed += speedModifier;  // Adjust as necessary based on how speed is handled in your class
//     }




void Wildcard::GenerateSpeedModifier() {
    // Randomly generate a speed modifier
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(-0.5, 1.5); // this range implies the speed can either increase by up to 50% or decrease down to 50% just my thoughts though

    mSpeedModifier = distr(gen);
}
