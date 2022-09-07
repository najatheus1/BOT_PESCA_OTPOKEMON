#include <iostream>
#include <Windows.h>
#include <array>

std::array<HWND, 2> window{};
std::array<int, 4> color_rgb{};
std::array<LONG, 6> pos_cursor{};
std::array<int, 4 >count {};
HDC dc;
POINT cursor;
COLORREF color;

void marcador(int pox_x, int pos_y);
void ClickCursor(int count_click);
void pesca(void);
void TARGET(void);
void ATTACK(void);
void d_ATTACK(void);
void returnCallback(void);
void callBack(void);
void bot_pesca(void);

int main()
{
	SetConsoleTitle("BOT_PESCA(OTPOKEMON) [BY: SRNAJA]");
	for (std::size_t i = 0; i <= 5; ++i) {
		pos_cursor[i] = 0;
	}

	while (pos_cursor[0] == 0 && pos_cursor[1] == 0) {
		GetCursorPos(&cursor);
		marcador(cursor.x, cursor.y);

		std::cout << "COLOQUE O MOUSE OU O MARCADOR EM CIMA DO PEIXE DA PESCA E APERTE CTRL+SHIFT+O" << std::endl;
		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(0x4f)) {
			pos_cursor[0] = cursor.x;
			pos_cursor[1] = cursor.y;
		}
		std::system("cls");
	}

	while (pos_cursor[2] == 0 && pos_cursor[3] == 0) {
		GetCursorPos(&cursor);
		std::cout << "COLOQUE O MOUSE EM CIMA DA AGUA E APERTE CTRL+SHIFT+A" << std::endl;
		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(0x41)) {
			pos_cursor[2] = cursor.x;
			pos_cursor[3] = cursor.y;
		}
		marcador(cursor.x, cursor.y);

		std::system("cls");
	}

	while (pos_cursor[4] == 0 && pos_cursor[5] == 0) {
		GetCursorPos(&cursor);
		std::cout << "COLOQUE O MOUSE EM CIMA DA JANELA DE ATAQUE E APERTE CTRL+SHIFT+B" << std::endl;
		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(0x42)) {
			pos_cursor[4] = cursor.x;
			pos_cursor[5] = cursor.y;
		}

		marcador(cursor.x, cursor.y);
		std::system("cls");
	}

	callBack();
	return 0;
}

void ClickCursor(int count_click) {
	for (std::size_t i = 1; i <= count_click; i++) {
		Sleep(200);
		mouse_event(0x0002, NULL, NULL, NULL, NULL);
		mouse_event(0x0004, NULL, NULL, NULL, NULL);
		Sleep(200);
	}
}

void pesca(void) {
	count[0] = 0;
	GetCursorPos(&cursor);
	while ((cursor.x != pos_cursor[0]) && (cursor.x != pos_cursor[1])) {
		GetCursorPos(&cursor);
		SetPhysicalCursorPos(pos_cursor[0], pos_cursor[1]);
	}

	ClickCursor(1);

	while ((cursor.x != pos_cursor[2]) && (cursor.x != pos_cursor[3])) {
		GetCursorPos(&cursor);
		SetPhysicalCursorPos(pos_cursor[2], pos_cursor[3]);
	}

	ClickCursor(2);

	ShowCursor(1);
}

void marcador(int pox_x, int pos_y) {
	SetPixel(dc, pox_x, pos_y, RGB(0, 0, 0));
	SetPixel(dc, pox_x + 1, pos_y, RGB(0, 0, 0));
	SetPixel(dc, pox_x, pos_y + 1, RGB(0, 0, 0));
	SetPixel(dc, pox_x + 1, pos_y + 1, RGB(0, 0, 0));
	SetPixel(dc, pox_x - 1, pos_y, RGB(0, 0, 0));
	SetPixel(dc, pox_x, pos_y - 1, RGB(0, 0, 0));
	SetPixel(dc, pox_x - 1, pos_y - 1, RGB(0, 0, 0));
	SetPixel(dc, pox_x + 2, pos_y, RGB(0, 0, 0));
	SetPixel(dc, pox_x, pos_y + 2, RGB(0, 0, 0));
	SetPixel(dc, pox_x + 2, pos_y + 2, RGB(0, 0, 0));
	SetPixel(dc, pox_x - 2, pos_y, RGB(0, 0, 0));
	SetPixel(dc, pox_x, pos_y - 2, RGB(0, 0, 0));
	SetPixel(dc, pox_x - 2, pos_y - 2, RGB(0, 0, 0));
}

void d_ATTACK(void) {
	for (BYTE i = VK_F1; i <= VK_F12; i++) {
		keybd_event(i, NULL, KEYEVENTF_KEYUP, NULL);
	}
}

void TARGET(void) {
	GetCursorPos(&cursor);
	while ((cursor.x != pos_cursor[4]) && (cursor.x != pos_cursor[5])) {
		GetCursorPos(&cursor);
		SetPhysicalCursorPos(pos_cursor[4], pos_cursor[5]);
	}

	ClickCursor(1);
}

void ATTACK(void) {
	TARGET();
	for (BYTE i = VK_F1; i <= VK_F12; i++) {
		keybd_event(i, NULL, NULL, NULL);
	}
	Sleep(200);
}

void returnCallback(void) {
	while (true) {
		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x51)) {
			callBack();
		}
	}
}

void callBack(void) {
	for (std::size_t i = 0; i <= 3; ++i) {
		color_rgb[i] = 0;
	}

	dc = 0;
	color = 0;

	window[0] = FindWindow("otPokemon", NULL);
	if (!window[0]) {
		std::cout << "O OTPOKEMON ESTÁ FECHADO!" << std::endl;
		return;
	}

	dc = GetDC(window[0]);

	for (;;) {
		bot_pesca();
	}
}

void bot_pesca(void) {
	window[0] = FindWindow("otPokemon", NULL);
	if (window[0]) {
		window[1] = GetForegroundWindow();
		if (window[1]) {
			if (window[0] == window[1]) {
				GetCursorPos(&cursor);
				if (!dc) {
					dc = GetDC(window[0]);
				}

				++count[0];
				if (count[0] >= 10000) {
					pesca();
				}

				if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x45)) {
					returnCallback();
				}

				if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(0x4f)) {
					std::cout << "COLOQUE O MOUSE OU O MARCADOR EM CIMA DO PEIXE DA PESCA" << std::endl;
					pos_cursor[0] = cursor.x;
					pos_cursor[1] = cursor.y;
				}

				if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(0x41)) {
					std::cout << "COLOQUE O MOUSE EM CIMA DA AGUA" << std::endl;
					pos_cursor[2] = cursor.x;
					pos_cursor[3] = cursor.y;
				}

				if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(0x42)) {
					std::cout << "COLOQUE O MOUSE EM CIMA DA JANELA DE ATAQUE" << std::endl;
					pos_cursor[4] = cursor.x;
					pos_cursor[5] = cursor.y;
				}

				color = GetPixel(dc, pos_cursor[0] + 1, pos_cursor[1] + 1);
				marcador(pos_cursor[0], pos_cursor[1]);
				marcador(pos_cursor[2], pos_cursor[3]);
				marcador(pos_cursor[4], pos_cursor[5]);
				color_rgb[0] = static_cast<int>GetRValue(color);
				color_rgb[1] = static_cast<int>GetGValue(color);
				color_rgb[2] = static_cast<int>GetBValue(color);
				color_rgb[3] = RGB(color_rgb[0], color_rgb[1], color_rgb[2]);
				if (color_rgb[3] >= 917341 && color_rgb[3] <= 3254083) {
					ShowCursor(0);
					SetPhysicalCursorPos(pos_cursor[0], pos_cursor[1]);
					Sleep(200);
					mouse_event(0x0002, NULL, NULL, NULL, NULL);
					mouse_event(0x0004, NULL, NULL, NULL, NULL);
					ATTACK();
					pesca();
					std::cout << "PEGOU UM POKEMON!!" << std::endl;
				}
			}
		}
	}
}
