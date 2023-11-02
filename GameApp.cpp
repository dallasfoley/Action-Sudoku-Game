/**
 * @file GameApp.cpp
 * @author Jon Price
 */

#include "pch.h"

#ifdef WIN32
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#endif

#include <MainFrame.h>
#include "GameApp.h"

/**
 * Initialize the application.
 * @return
 */
bool GameApp::OnInit() {
    #ifdef WIN32
    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
    #endif

    if (!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();


    auto gameFrame = new MainFrame();
    gameFrame->Initialize();
    gameFrame->Show(true);
    return true;
}