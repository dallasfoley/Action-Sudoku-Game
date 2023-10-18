/**
 * @file Game.h
 * @author Jon Price
 */

#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

class Sparty;

/// class which represents the Game
class Game {
private:
    double mScale; ///< current scaling of the window
    double mXOffset;
    double mYOffset;
    std::unique_ptr<wxBitmap> mBackground; ///< background for the level, for now a placeholder
    std::shared_ptr<Sparty> mSparty;
public:
    Game();
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    Game();
    void Update(double elapsed);
    void OnLeftDown(wxMouseEvent & event);
};


#endif //PROJECT1_GAME_H
