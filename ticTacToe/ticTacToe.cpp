#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif
#include <string.h>

class ticTacToe : public wxApp {
public:
	virtual bool OnInit();
};


/* Caso a função wxFrame não esteja "habilitada", configure em vinculador as bibliotecas adicionais*/
class MainFrame : public wxFrame {
public:
	MainFrame();
protected:
	wxMenuBar* m_mainMenuBar;
	wxMenu* m_menuGame;
	wxMenu* m_menuHelp;
private:
	void OnNewGame(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
};

bool ticTacToe::OnInit() {
	MainFrame* frame = new MainFrame();
	frame->Show();

	//[ALTERAR] Na etapa 3, vamos inicializar o tabuleiro aqui.

	return true;
}

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "Tic Tac Toe") {

}