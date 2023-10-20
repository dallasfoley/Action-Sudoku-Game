/**
  * @file MainFrame.h
  * @author Joseph Renas
  * The top-level (main) frame of the application
 */

# ifndef PROJECT1_MAINFRAME_H
# define PROJECT1_MAINFRAME_H
/**
 * Class for mGameView
 */
class GameView;

/**
  * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame
{
private:
    std::shared_ptr<GameView> mGameView;
public:
    void Initialize();
    void OnClose(wxCloseEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

};

# endif //PROJECT1_MAINFRAME_H