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

int checkBoard() {
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
		column = line;
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
	column = 2;
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

	// Métodos de reação à entrada do mouse
	void OnBtnTopLeftEnterWindow(wxCommandEvent& event);
	void OnBtnTopMidEnterWindow(wxCommandEvent& event);
	void OnBtnTopRightEnterWindow(wxCommandEvent& event);

	void OnBtnMidLeftEnterWindow(wxCommandEvent& event);
	void OnBtnMidMidEnterWindow(wxCommandEvent& event);
	void OnBtnMidRightEnterWindow(wxCommandEvent& event);

	void OnBtnLowLeftEnterWindow(wxCommandEvent& event);
	void OnBtnLowMidEnterWindow(wxCommandEvent& event);
	void OnBtnLowRightEnterWindow(wxCommandEvent& event);

	// Métodos de reação a saída do mouse
	void OnBtnTopLeftLeaveWindow(wxCommandEvent& event);
	void OnBtnTopMidLeaveWindow(wxCommandEvent& event);
	void OnBtnTopRightLeaveWindow(wxCommandEvent& event);

	void OnBtnMidLeftLeaveWindow(wxCommandEvent& event);
	void OnBtnMidMidLeaveWindow(wxCommandEvent& event);
	void OnBtnMidRightLeaveWindow(wxCommandEvent& event);

	void OnBtnLowLeftLeaveWindow(wxCommandEvent& event);
	void OnBtnLowMidLeaveWindow(wxCommandEvent& event);
	void OnBtnLowRightLeaveWindow(wxCommandEvent& event);



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


	DisableGrid();
	SetStatusText("Go to New Game to start a match");



	Bind(wxEVT_MENU, &MainFrame::OnNewGame, this, ID_NewGame);
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

	// Conectando o evento do botão no frame
	m_btnTopLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnTopLeftClick), NULL, this);
	m_btnTopMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnTopMidClick), NULL, this);
	m_btnTopRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnTopRightClick), NULL, this);

	m_btnMidLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidLeftClick), NULL, this);
	m_btnMidMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidMidClick), NULL, this);
	m_btnMidRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnMidRightClick), NULL, this);

	m_btnLowLeft->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowLeftClick), NULL, this);
	m_btnLowMid->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowMidClick), NULL, this);
	m_btnLowRight->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainFrame::OnBtnLowRightClick), NULL, this);


	m_btnTopLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnTopLeftEnterWindow), NULL, this);
	m_btnTopMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnTopMidEnterWindow), NULL, this);
	m_btnTopRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnTopRightEnterWindow), NULL, this);

	m_btnMidLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidLeftEnterWindow), NULL, this);
	m_btnMidMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidMidEnterWindow), NULL, this);
	m_btnMidRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidRightEnterWindow), NULL, this);

	m_btnLowLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowLeftEnterWindow), NULL, this);
	m_btnLowMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowMidEnterWindow), NULL, this);
	m_btnLowRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowRightEnterWindow), NULL, this);

	m_btnTopLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnTopLeftLeaveWindow), NULL, this);
	m_btnTopMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnTopMidLeaveWindow), NULL, this);
	m_btnTopRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnTopRightLeaveWindow), NULL, this);

	m_btnMidLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidLeftLeaveWindow), NULL, this);
	m_btnMidMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidMidLeaveWindow), NULL, this);
	m_btnMidRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnMidRightLeaveWindow), NULL, this);

	m_btnLowLeft->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowLeftLeaveWindow), NULL, this);
	m_btnLowMid->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowMidLeaveWindow), NULL, this);
	m_btnLowRight->Connect(wxEVT_ENTER_WINDOW, wxCommandEventHandler(MainFrame::OnBtnLowRightLeaveWindow), NULL, this);
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

	/* Texto dos botões*/
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
	EnableGrid();
	initBoard();
	SetStatusText("It is Player 1's turn!");
}

void MainFrame::OnExit(wxCommandEvent& event) {
	Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event) {
	wxMessageBox("This is a Tic Toe in C/C++ by Erick Bryan Cubas", "About Tic Tac Toe", wxOK | wxICON_INFORMATION);
}


// Eventos dos Botões
void MainFrame::OnBtnTopLeftClick(wxCommandEvent& event) {
	if (m_btnTopLeft->IsEnabled()) {
		board[0][0] = player;
		m_btnTopLeft->Disable();
		if (player == 1) {
			m_btnTopLeft->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnTopLeft->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	victorious = checkBoard();
	if (victorious != 0 || turnCounter >= 9) {
		EndGame();
	}
}
void MainFrame::OnBtnTopMidClick(wxCommandEvent& event) {
	if (m_btnTopMid->IsEnabled()) {
		board[0][1] = player;
		m_btnTopMid->Disable();
		if (player == 1) {
			m_btnTopMid->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnTopMid->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	victorious = checkBoard();
	if (victorious != 0 || turnCounter >= 9) {
		EndGame();
	}
}
void MainFrame::OnBtnTopRightClick(wxCommandEvent& event) {
	if (m_btnTopRight->IsEnabled()) {
		board[0][2] = player;
		m_btnTopRight->Disable();
		if (player == 1) {
			m_btnTopRight->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnTopRight->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	victorious = checkBoard();
	if (victorious != 0 || turnCounter >= 9) {
		EndGame();
	}
}
void MainFrame::OnBtnMidLeftClick(wxCommandEvent& event) {
	if (m_btnMidLeft->IsEnabled()) {
		board[1][0] = player;
		m_btnMidLeft->Disable();
		if (player == 1) {
			m_btnMidLeft->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnMidLeft->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	victorious = checkBoard();
	if (victorious != 0 || turnCounter >= 9) {
		EndGame();
	}
}
void MainFrame::OnBtnMidMidClick(wxCommandEvent& event) {
	if (m_btnMidMid->IsEnabled()) {
		board[1][1] = player;
		m_btnMidMid->Disable();
		if (player == 1) {
			m_btnMidMid->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnMidMid->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	victorious = checkBoard();
	if (victorious != 0 || turnCounter >= 9) {
		EndGame();
	}
}
void MainFrame::OnBtnMidRightClick(wxCommandEvent& event) {
	if (m_btnMidRight->IsEnabled()) {
		board[1][2] = player;
		m_btnMidRight->Disable();
		if (player == 1) {
			m_btnMidRight->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnMidRight->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	victorious = checkBoard();
	if (victorious != 0 || turnCounter >= 9) {
		EndGame();
	}
}
void MainFrame::OnBtnLowLeftClick(wxCommandEvent& event) {
	if (m_btnLowLeft->IsEnabled()) {
		board[2][0] = player;
		m_btnLowLeft->Disable();
		if (player == 1) {
			m_btnLowLeft->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnLowLeft->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	victorious = checkBoard();
	if (victorious != 0 || turnCounter >= 9) {
		EndGame();
	}
}
void MainFrame::OnBtnLowMidClick(wxCommandEvent& event) {
	if (m_btnLowMid->IsEnabled()) {
		board[2][1] = player;
		m_btnLowMid->Disable();
		if (player == 1) {
			m_btnLowMid->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnLowMid->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	victorious = checkBoard();
	if (victorious != 0 || turnCounter >= 9) {
		EndGame();
	}
}
void MainFrame::OnBtnLowRightClick(wxCommandEvent& event) {
	if (m_btnLowRight->IsEnabled()) {
		board[2][2] = player;
		m_btnLowRight->Disable();
		if (player == 1) {
			m_btnLowRight->SetLabelText("X");
			player = 2;
		}
		else {
			if (player == 2) {
				m_btnLowRight->SetLabelText("O");
				player = 1;
			}
		}
	}
	turnCounter++;
	victorious = checkBoard();
	if (victorious != 0 || turnCounter >= 9) {
		EndGame();
	}
}

// Métodos de reação à entrada do mouse
void MainFrame::OnBtnTopLeftEnterWindow(wxCommandEvent& event) {
	if (m_btnTopLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}


void MainFrame::OnBtnTopMidEnterWindow(wxCommandEvent& event) {
	if (m_btnTopMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnTopRightEnterWindow(wxCommandEvent& event) {
	if (m_btnTopRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidLeftEnterWindow(wxCommandEvent& event) {
	if (m_btnMidLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidMidEnterWindow(wxCommandEvent& event) {
	if (m_btnMidMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidRightEnterWindow(wxCommandEvent& event) {
	if (m_btnMidRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowLeftEnterWindow(wxCommandEvent& event) {
	if (m_btnLowLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowMidEnterWindow(wxCommandEvent& event) {
	if (m_btnLowMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowRightEnterWindow(wxCommandEvent& event) {
	if (m_btnLowRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

// Métodos de reação a saída do mouse
void MainFrame::OnBtnTopLeftLeaveWindow(wxCommandEvent& event) {
	if (m_btnTopLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnTopMidLeaveWindow(wxCommandEvent& event) {
	if (m_btnTopMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnTopRightLeaveWindow(wxCommandEvent& event) {
	if (m_btnTopRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidLeftLeaveWindow(wxCommandEvent& event) {
	if (m_btnMidLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidMidLeaveWindow(wxCommandEvent& event) {
	if (m_btnMidMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnMidRightLeaveWindow(wxCommandEvent& event) {
	if (m_btnMidRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowLeftLeaveWindow(wxCommandEvent& event) {
	if (m_btnLowLeft->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowMidLeaveWindow(wxCommandEvent& event) {
	if (m_btnLowMid->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}

void MainFrame::OnBtnLowRightLeaveWindow(wxCommandEvent& event) {
	if (m_btnLowRight->IsEnabled()) {
		strcpy(m_msgStatusBar, "");
		strcpy(m_msgStatusBar, "Click here to mark a(n) ");
		if (player == 1) {
			strcat(m_msgStatusBar, "X!");
		}
		else {
			if (player == 2) {
				strcat(m_msgStatusBar, "O!");
			}
		}
	}
	SetStatusText(m_msgStatusBar);
}