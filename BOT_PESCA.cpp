#include <iostream>
#include <Windows.h>
#include <array>
#include <string>

#define NAME_TITLE "BOT_PESCA(OTPOKEMON) [BY: SRNAJA]"
std::array<HWND, 2> window{};
std::array<int, 4> color_rgb{};
std::array<LONG, 6> pos_cursor{};
std::array<int, 4 >count{};
HDC dc;
POINT cursor;
COLORREF color;
RECT rect, r;
std::string text;


void marcador(int pox_x, int pos_y);
void ClickCursor(int count_click);
void pesca(void);
void TARGET(void);
void ATTACK(void);
void d_ATTACK(void);
void returnCallback(void);
void callBack(void);
void bot_pesca(void);
void square(void);

int main()
{
	window[0] = FindWindow("otPokemon", NULL);
	while (!window[0]) {
		std::system("cls");
		std::cout << "O OTPOKEMON ESTÁ FECHADO!" << std::endl;
		std::cout << "esperando..." << std::endl;
		window[0] = FindWindow("otPokemon", NULL);
		return 0;
	}

	SetConsoleTitle(NAME_TITLE);

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

	ClickCursor(2);

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
	d_ATTACK();

	while (true) {
		if (GetAsyncKeyState(0x51)) {
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
	dc = GetDC(window[0]);

	for (;;) {
		bot_pesca();
	}
}

void square(void) {
	GetClientRect(window[0], &rect);
	SetBkMode(dc, TRANSPARENT);
	SetTextColor(dc, RGB((rand() % 255 + 1), (rand() % 255 + 1), (rand() % 255 + 1)));
	DrawTextA(dc, "BOT DE PESCA [ BY : SR.NAJA ]", -1, &rect, DT_BOTTOM | DT_INTERNAL | DT_VCENTER | DT_NOCLIP | DT_CENTER);

	//Cursor
	r.bottom = (cursor.y + 2) + 4;
	r.top = cursor.y - 30;
	r.left = cursor.x - 20;
	r.right = (cursor.x + 2) + 25;
	DrawFocusRect(dc, &r);
	r.top = r.top + 40;
	text = "X:" + std::to_string(cursor.x) + "/" + "Y:" + std::to_string(cursor.y);
	DrawTextA(dc, text.c_str(), -1, &r, DT_BOTTOM | DT_INTERNAL | DT_VCENTER | DT_NOCLIP | DT_CENTER);

	//Y: pos_cursor[3] && X: pos_cursor[2]
	r.bottom = (pos_cursor[3] + 2) + 4;
	r.top = pos_cursor[3] - 30;
	r.left = pos_cursor[2] - 20;
	r.right = (pos_cursor[2] + 2) + 25;
	DrawFocusRect(dc, &r);
	r.top = r.top + 40;
	text = "X:" + std::to_string(pos_cursor[0]) + "/" + "Y:" + std::to_string(pos_cursor[1]);
	DrawTextA(dc, text.c_str(), -1, &r, DT_BOTTOM | DT_INTERNAL | DT_VCENTER | DT_NOCLIP | DT_CENTER);

	//Y: pos_cursor[5] && X: pos_cursor[4]
	r.bottom = (pos_cursor[5] + 2) + 4;
	r.top = pos_cursor[5] - 30;
	r.left = pos_cursor[4] - 20;
	r.right = (pos_cursor[4] + 2) + 25;
	DrawFocusRect(dc, &r);
	r.top = r.top + 40;
	text = "X:" + std::to_string(pos_cursor[0]) + "/" + "Y:" + std::to_string(pos_cursor[1]);
	DrawTextA(dc, text.c_str(), -1, &r, DT_BOTTOM | DT_INTERNAL | DT_VCENTER | DT_NOCLIP | DT_CENTER);

	//Y: pos_cursor[1] && X: pos_cursor[0]
	r.bottom = (pos_cursor[1] + 2) + 4;
	r.top = pos_cursor[1] - 30;
	r.left = pos_cursor[0] - 20;
	r.right = (pos_cursor[0] + 2) + 25;
	DrawFocusRect(dc, &r);
	r.top = r.top + 40;
	text = "X:" + std::to_string(pos_cursor[0]) + "/" + "Y:" + std::to_string(pos_cursor[1]);
	DrawTextA(dc, text.c_str(), -1, &r, DT_BOTTOM | DT_INTERNAL | DT_VCENTER | DT_NOCLIP | DT_CENTER);

	DrawFocusRect(dc, &rect);
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
				if (count[0] >= 17000) {
					pesca();
				}

				if (GetAsyncKeyState(0x45)) {
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
				square();

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
