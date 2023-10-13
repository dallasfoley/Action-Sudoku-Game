/**
 * @file MainFrame.cpp
 * @author Joseph Renas
 * @author Jon Price
 */

#include "pch.h"

#include "MainFrame.h"
#include "GameView.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize(wxFrame * parent)
{

    Create(nullptr, wxID_ANY, L"Sudoku", wxDefaultPosition,  wxSize( 1000,800 ));


//    Create(parent, wxID_ANY, L"Game",
//           wxDefaultPosition, wxDefaultSize,
//           wxFULL_REPAINT_ON_RESIZE);

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Create the view class object as a child of MainFrame
    auto gameView = new GameView();

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