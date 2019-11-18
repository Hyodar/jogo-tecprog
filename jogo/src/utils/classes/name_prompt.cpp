// Libraries
// ---------------------------------------------------------------------------

#include <string>
#include <locale>

#include <unicode/utypes.h>
#include <unicode/unistr.h>
#include <unicode/translit.h>

// Class header
// ---------------------

#include "name_prompt.hpp"

// Internal libraries
// ---------------------

#include "game.hpp"

// Attribute initialization
// ---------------------------------------------------------------------------

wxBEGIN_EVENT_TABLE(PromptFrame, wxFrame)
EVT_BUTTON(10001, PromptFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

// Methods
// ---------------------------------------------------------------------------

PromptFrame::PromptFrame() : wxFrame(nullptr, wxID_ANY, "Insira seu nome de jogador") {
    m_btn1 = new wxButton(this, 10001, "Enviar", wxPoint(125, 100), wxSize(150, 50));
    m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(125, 10), wxSize(150, 50));
}

// ---------------------------------------------------------------------------

PromptFrame::~PromptFrame() {
    delete m_btn1;
    delete m_txt1;
}

// ---------------------------------------------------------------------------

void PromptFrame::OnButtonClicked(wxCommandEvent& event) {

    std::string textBoxContent(m_txt1->GetValue().mb_str(wxConvUTF8));

    // testa se a string eh valida
    if(textBoxContent.find_first_not_of(' ') != std::string::npos && textBoxContent != "") {
        std::string res = removeDiacritics(textBoxContent);
        Game::getInstance()->setPlayerName(res);
        event.Skip();
        Close();
    }
    event.Skip();
}

// ---------------------------------------------------------------------------

/*
    Código retirado de https://stackoverflow.com/questions/2992066/code-to-strip-diacritical-marks-using-icu,
    de autoria do usuário Quentin Pradet do StackOverflow
*/

std::string PromptFrame::removeDiacritics(const std::string& str) {
    // UTF-8 std::string -> UTF-16 UnicodeString
    UnicodeString source = UnicodeString::fromUTF8(StringPiece(str));
    source.toLower();

    // Transliterate UTF-16 UnicodeString
    UErrorCode status = U_ZERO_ERROR;
    Transliterator* accentsConverter = Transliterator::createInstance(
        "NFD; [:M:] remove; NFC", UTRANS_FORWARD, status);
    accentsConverter->transliterate(source);

    // UTF-16 UnicodeString -> UTF-8 std::string
    std::string result;
    source.toUTF8String(result);

    return result;
}

// ---------------------------------------------------------------------------

NamePrompt::NamePrompt() {

}

// ---------------------------------------------------------------------------

NamePrompt::~NamePrompt() {
    delete m_frame1;
}

// ---------------------------------------------------------------------------

bool NamePrompt::OnInit() {
    m_frame1 = new PromptFrame;
    m_frame1->Show();

    return false;
}

// ---------------------------------------------------------------------------

int NamePrompt::OnExit() {
    if(Game::getInstance()->getPlayerName() == "") {
        Game::getInstance()->stop();
        return 1;
    }
    return 0;
}
