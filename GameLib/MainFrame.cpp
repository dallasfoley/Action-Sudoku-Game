/**
 * @file MainFrame.cpp
 * @author Joseph Renas
 * @author Jon Price
 */

#include "pch.h"
#include "ids.h"
#include "MainFrame.h"
#include "GameView.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{

    Create(nullptr, wxID_ANY, L"Sudoku", wxDefaultPosition,  wxSize( 1000,800 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Create the view class object as a child of MainFrame
    auto gameView = new GameView();

    mGameView = gameView;

    gameView->Initialize(this);

    // Add it to the sizer
    sizer->Add(gameView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

    auto menuBar = new wxMenuBar( );

    auto fileMenu = new wxMenu();
    auto levelMenu = new wxMenu();
    auto helpMenu = new wxMenu();

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(levelMenu, L"&Level");
    menuBar->Append(helpMenu, L"&Help");

    fileMenu->Append(IDM_SOLVE, L"&Solve", "Solve this level");
    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    levelMenu->Append(IDM_ADDLVL1, L"&Level 1", "Load level 1");
    levelMenu->Append(IDM_ADDLVL2, L"&Level 2", "Load level 2");
    levelMenu->Append(IDM_ADDLVL3, L"&Level 3", "Load level 3");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
    helpMenu->Append(IDM_FPS, L"&Display FPS", "Show FPS");

    SetMenuBar( menuBar );

    CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
}

/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    // Stop the animation
    mGameView->Stop();
    Destroy();
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

/**
 * About menu option handlers
 * @param event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(L"Welcome to Action Sudoku!",
                 L"About",
                 wxOK,
                 this);
}

