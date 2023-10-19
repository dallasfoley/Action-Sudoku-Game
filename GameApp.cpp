/**
 * @file GameApp.cpp
 * @author Jon Price
 */

#include "pch.h"
#include <MainFrame.h>
#include "GameApp.h"

/**
 * Initialize the application.
 * @return
 */
bool GameApp::OnInit() {
    if (!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();


    auto gameFrame = new MainFrame();
    gameFrame->Initialize();
    gameFrame->Show(true);
    return true;
}