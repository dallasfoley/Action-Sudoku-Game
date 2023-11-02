/**
 * @file FpsDisplay.h
 * @author Jon Price
 *
 * Class to display fps
 */

#ifndef PROJECT1_FPSDISPLAY_H
#define PROJECT1_FPSDISPLAY_H

/**
 * Class to display fps
 */
class FpsDisplay {
private:

    /// Frames
    double mFrames;
public:
    void Update(double elapsed);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
};


#endif //PROJECT1_FPSDISPLAY_H
