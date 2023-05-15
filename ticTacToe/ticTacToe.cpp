#include <wx/wxprec.h>
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif
#include <string.h>

int board[3][3];

int player; //Define o usuário da jogada
int turnCounter; // Contador de jogadas
int victorious; // Define o ganhador

void initBoard(); // Função para inicializar o tabuleiro
int checkBoard();

void initBoard() {

	int line, column;

	player = 1;
	turnCounter = 0;
	victorious = 0;

	for (line = 0; line < 3; line++) {
		for (column = 0; column < 3; column++) {
			board[line][column] = 0;
		}
	}
}

int checBoard() {
	int line, column, player_1, player_2;

	// Verificando linhas
	for (line = 0; line < 3; line++) {
		player_1 = 0;
		player_2 = 0;
		for (column = 0; column < 3; column++) {
			if (board[line][column] == 1) player_1++;
			else if (board[line][column] == 2) player_2++;
		}
		if (player_1 == 3) {
			return 1;
		}
		else if (player_2 == 3) {
			return 2;
		}
	}

	// Verificando colunas
	for (column = 0; column < 3; column++) {
		player_1 = 0;
		player_2 = 0;
		for (line = 0; line < 3; line++) {
			if (board[line][column] == 1) player_1++;
			else if (board[line][column] == 2) player_2++;
		}
		if (player_1 == 3) {
			return 1;
		}
		else if (player_2 == 3) {
			return 2;
		}

	}

	// Verificando a diagonal principal
	player_1 = 0;
	player_2 = 0;
	for (line = 0; line < 3; line++) {
		if (board[line][column] == 1) player_1++;
		else if (board[line][column] == 2) player_2++;
	}
	if (player_1 == 3) {
		return 1;
	}
	else if (player_2 == 3) {
		return 2;
	}


	// Verificando a diagonal secundária
	player_1 = 0;
	player_2 = 0;
	column = 0;
	for (line = 0; line < 3; line++) {
		if (board[line][column] == 1) player_1++;
		else if (board[line][column] == 2) player_2++;
		column--;
	}
	if (player_1 == 3) {
		return 1;
	}
	else if (player_2 == 3) {
		return 2;
	}

	// Se não houver ganhador
	return 0;

}




class ticTacToe : public wxApp {
public:
	virtual bool OnInit();
};


/// Caso a função wxFrame não esteja "habilitada", configure em vinculador as bibliotecas adicionais
class MainFrame : public wxFrame {
public:
	MainFrame();
protected:
	wxMenuBar* m_mainMenuBar;
	wxMenu* m_menuGame;
	wxMenu* m_menuHelp;

	/// Botões Top
	wxButton* m_btnTopLeft;
	wxButton* m_btnTopMid;
	wxButton* m_btnTopRight;

	/// Botões Mid
	wxButton* m_btnMidLeft;
	wxButton* m_btnMidMid;
	wxButton* m_btnMidRight;

	/// Botões Low
	wxButton* m_btnLowLeft;
	wxButton* m_btnLowMid;
	wxButton* m_btnLowRight;

	/// Barra de Status
	wxStatusBar* m_StatusBar;


	char m_msgStatusBar[200];

/// wxCommandEvent é um obtejo para atribuir parâmetros de evento
private:
	void OnNewGame(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	void EnableGrid();
	void DisableGrid();
	void EndGame();

	/// Métodos de reação aos cliques
	void OnBtnTopLeftClick(wxCommandEvent& event);
	void OnBtnTopMidClick(wxCommandEvent& event);
	void OnBtnTopRightClick(wxCommandEvent& event);

	void OnBtnMidLeftClick(wxCommandEvent& event);
	void OnBtnMidMidClick(wxCommandEvent& event);
	void OnBtnMidRightClick(wxCommandEvent& event);

	void OnBtnLowLeftClick(wxCommandEvent& event);
	void OnBtnLowMidClick(wxCommandEvent& event);
	void OnBtnLowRightClick(wxCommandEvent& event);


};

bool ticTacToe::OnInit() {
	MainFrame* frame = new MainFrame();
	frame->Show();

	return true;
}

enum {
	ID_NewGame = 1
};

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "Tic Tac Toe") {
	this->SetSizeHints(600, 600);

	m_mainMenuBar = new wxMenuBar(0);
	m_menuGame = new wxMenu();
	m_menuHelp = new wxMenu();

	m_mainMenuBar->Append(m_menuGame, "Game");
	m_mainMenuBar->Append(m_menuHelp, "Help");

	m_menuGame->Append(ID_NewGame, "&New Game\tCtrl-N", "Start New Match");
	m_menuGame->AppendSeparator();
	m_menuGame->Append(wxID_EXIT);

	m_menuGame->Append(wxID_ABOUT);

	wxFont font(48, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	this->SetMenuBar(m_mainMenuBar);

	wxGridSizer* gBoard = new wxGridSizer(3, 3, 0, 0);
	gBoard->SetMinSize(500, 500);

	// 1 - TOP LEFT
	m_btnTopLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnTopLeft->SetFont(font);
	gBoard->Add(m_btnTopLeft, 0, wxALL | wxEXPAND, 5);

	// 2 - TOP MID
	m_btnTopMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnTopMid->SetFont(font);
	gBoard->Add(m_btnTopMid, 0, wxALL | wxEXPAND, 5);

	// 3 - TOP RIGHT
	m_btnTopRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnTopRight->SetFont(font);
	gBoard->Add(m_btnTopRight, 0, wxALL | wxEXPAND, 5);

	// 4 - MID LEFT
	m_btnMidLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidLeft->SetFont(font);
	gBoard->Add(m_btnMidLeft, 0, wxALL | wxEXPAND, 5);

	// 5 - MID MID
	m_btnMidMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidMid->SetFont(font);
	gBoard->Add(m_btnMidMid, 0, wxALL | wxEXPAND, 5);

	// 6 - MID RIGHT	
	m_btnMidRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnMidRight->SetFont(font);
	gBoard->Add(m_btnMidRight, 0, wxALL | wxEXPAND, 5);
	
	// 7 - LOW LEFT	
	m_btnLowLeft = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowLeft->SetFont(font);
	gBoard->Add(m_btnLowLeft, 0, wxALL | wxEXPAND, 5);

	// 8 - LOW MID
	m_btnLowMid = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowMid->SetFont(font);
	gBoard->Add(m_btnLowMid, 0, wxALL | wxEXPAND, 5);

	// 9 - LOW RIGHT
	m_btnLowRight = new wxButton(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(40, 40), 0);
	m_btnLowRight->SetFont(font);
	gBoard->Add(m_btnLowRight, 0, wxALL | wxEXPAND, 5);


	this->SetSizer(gBoard);
	this->Layout();

	m_StatusBar = this->CreateStatusBar(1, wxST_SIZEGRIP, wxID_ANY);

	this->Centre(wxBOTH);

	Bind(wxEVT_MENU, &MainFrame::OnNewGame, this, ID_NewGame);
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

	// Conectando o evento do botão no frame
	m_btnTopLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnTopLeftClick), NULL, this);
	m_btnTopMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnTopMidClick), NULL, this);
	m_btnTopRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnTopRightClick), NULL, this);

	m_btnMidLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnTopLeftClick), NULL, this);
	m_btnMidMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidMidClick), NULL, this);
	m_btnMidRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidRightClick), NULL, this);

	m_btnLowLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowLeftClick), NULL, this);
	m_btnLowMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowMidClick), NULL, this);
	m_btnLowRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowRightClick), NULL, this);

}

wxIMPLEMENT_APP(ticTacToe);

void  MainFrame::EnableGrid() {
	
	m_btnTopLeft->Enable();
	m_btnTopMid->Enable();
	m_btnTopRight->Enable();

	m_btnMidLeft->Enable();
	m_btnMidMid->Enable();
	m_btnMidRight->Enable();

	m_btnLowLeft->Enable();
	m_btnLowMid->Enable();
	m_btnLowRight->Enable();

	// Texto dos botões
	m_btnTopLeft->SetLabelText("");
	m_btnTopMid->SetLabelText("");
	m_btnTopRight->SetLabelText("");

	m_btnMidLeft->SetLabelText("");
	m_btnMidMid->SetLabelText("");
	m_btnMidRight->SetLabelText("");

	m_btnLowLeft->SetLabelText("");
	m_btnLowMid->SetLabelText("");
	m_btnLowRight->SetLabelText("");

}

void  MainFrame::DisableGrid() {

	m_btnTopLeft->Disable();
	m_btnTopMid->Disable();
	m_btnTopRight->Disable();

	m_btnMidLeft->Disable();
	m_btnMidMid->Disable();
	m_btnMidRight->Disable();

	m_btnLowLeft->Disable();
	m_btnLowMid->Disable();
	m_btnLowRight->Disable();

	// Texto dos botões
	m_btnTopLeft->SetLabelText("");
	m_btnTopMid->SetLabelText("");
	m_btnTopRight->SetLabelText("");

	m_btnMidLeft->SetLabelText("");
	m_btnMidMid->SetLabelText("");
	m_btnMidRight->SetLabelText("");

	m_btnLowLeft->SetLabelText("");
	m_btnLowMid->SetLabelText("");
	m_btnLowRight->SetLabelText("");

}

void MainFrame::EndGame() {
	char mensagem[200] = "";
	if (victorious == 0) {
		strcpy(mensagem, "TIED MATCH!");
	}
	else {
		if (victorious == 1) {
			strcpy(mensagem, "X - Player 1 wins!");
		}
		else {
			if (victorious == 2) {
				strcpy(mensagem, "O - Player 2 wins!");
			}
		}
	}
	
	strcat(mensagem, "PLAY AGAIN?");
	if (wxMessageBox(mensagem, "END OF MATCH!", wxYES_NO | wxICON_INFORMATION) == wxYES) {
		initBoard(); // Reinicializando o banck-end
		EnableGrid(); // Reinicializando o front-end
	}
	else {
		Close(true);
	}

}


// Conecte event hadlers aos métodos do menu do topo
void MainFrame::OnNewGame(wxCommandEvent& event) {
	wxMessageBox("Test... New Game!", "New Game...", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnExit(wxCommandEvent& event) {
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
	wxMessageBox("This is a Tic Toe in C/C++ by Erick Bryan Cubas", "About Tic Tac Toe", wxOK | wxICON_INFORMATION);
}


// Eventos dos Botões
void MainFrame::OnBtnTopLeftClick(wxCommandEvent& event) {
	wxMessageBox("Button: Top Left!", "Deseja marcar essa posição?", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnBtnTopMidClick(wxCommandEvent& event) {
	wxMessageBox("Button: Top Mid!", "Deseja marcar essa posição?", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnBtnTopRightClick(wxCommandEvent& event) {
	wxMessageBox("Button: Top Right!", "Deseja marcar essa posição?", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnBtnMidLeftClick(wxCommandEvent& event) {
	wxMessageBox("Button: Mid Left!", "Deseja marcar essa posição?", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnBtnMidMidClick(wxCommandEvent& event) {
	wxMessageBox("Button: Mid Mid!", "Deseja marcar essa posição?", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnBtnMidRightClick(wxCommandEvent& event) {
	wxMessageBox("Button: Mid Right!", "Deseja marcar essa posição?", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnBtnLowLeftClick(wxCommandEvent& event) {
	wxMessageBox("Button: Low Left!", "Deseja marcar essa posição?", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnBtnLowMidClick(wxCommandEvent& event) {
	wxMessageBox("Button: Low Mid!", "Deseja marcar essa posição?", wxOK | wxICON_INFORMATION);
}
void MainFrame::OnBtnLowRightClick(wxCommandEvent& event) {
	wxMessageBox("Button: Low Right!", "Deseja marcar essa posição?", wxOK | wxICON_INFORMATION);
}

