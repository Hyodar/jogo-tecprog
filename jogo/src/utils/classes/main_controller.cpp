
#include "main_controller.hpp"

#include "game.hpp"
#include "name_prompt.hpp"

MainController::MainController(int argc, char** argv) {
    wxApp* pApp = new NamePrompt();
    wxApp::SetInstance(pApp);
    wxEntryStart(argc, argv);

    Game::getInstance()->start();
}

MainController::~MainController() {
    
}