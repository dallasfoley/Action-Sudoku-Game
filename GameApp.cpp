/**
 * @file GameApp.cpp
 * @author Jon Price
 */

#include <MainFrame.h>
#include "pch.h"
#include "GameApp.h"

/**
 * Initialize the application.
 * @return
 */
bool GameApp::OnInit() {
    if (!wxApp::OnInit())
        return false;

    auto mainFrame = new wxFrame();
    auto gameFrame = new MainFrame();
    gameFrame->Initialize(mainFrame);
    gameFrame->Show(true);
    mainFrame->Show(true);
    return true;
}