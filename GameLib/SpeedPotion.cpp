/**
 * @file SpeedPotion.cpp
 * @author Chirag Solanki
 */

#include "pch.h"
#include "SpeedPotion.h"
#include "Game.h"
#include "Sparty.h"
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
 * @param declaration The declaration for the SpeedPotion
 * @param node The xml node for the SpeedPotion
 * @param game The game object
 */
// for this to work we must enable default constructor in Item.h
SpeedPotion::SpeedPotion(DeclarationPotion * declaration, wxXmlNode * node, Game * game) : Item(declaration, node)
{
    mGame=game;
    mImage = make_unique<wxImage>(speedPotionImage, wxBITMAP_TYPE_ANY);
    mBitmap = make_unique<wxBitmap>(*mImage);
}


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
    Item::Draw(graphics);
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
//    auto sparty = mGame->GetSparty();
//    if (sparty) {
//       double newSpeed = sparty->GetSpeed() + mSpeedModifier; // Compute new speed
//        sparty->SetSpeed(newSpeed); // Set new speed
//    } else {
//        std::cerr << "Error: Sparty object not found in game." << std::endl;
//    }
//}


void SpeedPotion::GenerateSpeedModifier() {
    // Randomly generate a speed modifier
    std::uniform_real_distribution<> distr(-0.5, 1.5); // Range based on our design
    mSpeedModifier = distr(mRNG);
}

void SpeedPotion::OnConsume() {
   //for now just blank
}

/**
 * Load the potion from xml file
 * @param node
 */
void SpeedPotion::XmlLoad(wxXmlNode *node)
{
    double x;
    node->GetAttribute(L"col").ToDouble(&x);
    double y;
    node->GetAttribute(L"row").ToDouble(&y);
    SetLocation(x, y);
}

/**
 * Accept a visitor
 * @param visitor
 *
 */
void SpeedPotion::Accept(ItemVisitor* visitor) {
    visitor->VisitPotion(this);
}

