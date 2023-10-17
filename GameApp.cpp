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

    auto mainFrame = new wxFrame();
    auto gameFrame = new MainFrame();
    gameFrame->Initialize(mainFrame);
    gameFrame->Show(true);
    mainFrame->Show(true);
    return true;
}