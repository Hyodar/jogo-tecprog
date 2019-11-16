
#ifndef NAME_PROMPT_HPP_
#define NAME_PROMPT_HPP_

#include <wx/wx.h>

/*
    Classe feita com base no guia encontrado em 
    https://www.youtube.com/watch?v=FOIbK4bJKS8,
    de autoria do usuário do youtube javidx9
*/

class PromptFrame : public wxFrame {

public:
    PromptFrame();
    ~PromptFrame();

    void OnButtonClicked(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();

private:
    std::string removeDiacritics(const std::string& str);

    wxButton* m_btn1;
    wxTextCtrl* m_txt1;
};

class NamePrompt : public wxApp {

public:
    NamePrompt();
    ~NamePrompt();

    bool OnInit();
    int OnExit();

private:
    PromptFrame* m_frame1;
};

#endif // NAME_PROMPT_HPP_
