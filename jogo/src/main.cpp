
#include "game.hpp"
#include "name_prompt.hpp"

int main(int argc, char** argv) {

    // app do wxWidgets
    wxApp* pApp = new NamePrompt();
    wxApp::SetInstance(pApp);
    wxEntryStart(argc, argv);

    // jogo
    Game::getInstance()->start();

    return 0;
}