#include <iostream>
#include <Windows.h>
#include <array>

std::array<HWND, 2> window{};
std::array<int, 4> color_rgb{};
std::array<LONG, 6> pos_cursor{};
HDC dc;
POINT cursor;
COLORREF color;

void marcador(int pox_x, int pos_y);
void pesca(void);
void TARGET(void);
void ATTACK(void);
void d_ATTACK(void);
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

void pesca(void) {
	Sleep(200);
	SetCursorPos(pos_cursor[0], pos_cursor[1]);
	mouse_event(0x0002, NULL, NULL, NULL, NULL);
	mouse_event(0x0004, NULL, NULL, NULL, NULL);
	Sleep(200);
	mouse_event(0x0002, NULL, NULL, NULL, NULL);
	mouse_event(0x0004, NULL, NULL, NULL, NULL);
	Sleep(200);
	SetCursorPos(pos_cursor[2], pos_cursor[3]);
	mouse_event(0x0002, NULL, NULL, NULL, NULL);
	mouse_event(0x0004, NULL, NULL, NULL, NULL);
	mouse_event(0x0002, NULL, NULL, NULL, NULL);
	mouse_event(0x0004, NULL, NULL, NULL, NULL);
	Sleep(200);
	mouse_event(0x0002, NULL, NULL, NULL, NULL);
	mouse_event(0x0004, NULL, NULL, NULL, NULL);
	Sleep(200);
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
	keybd_event(VK_F1, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_F2, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_F3, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_F4, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_F5, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_F6, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_F7, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_F8, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_F9, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_F10, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_F11, NULL, KEYEVENTF_KEYUP, NULL);
	keybd_event(VK_F12, NULL, KEYEVENTF_KEYUP, NULL);
}

void TARGET(void) {
	Sleep(400);
	SetCursorPos(pos_cursor[4], pos_cursor[5]);
	mouse_event(0x0002, NULL, NULL, NULL, NULL);
	mouse_event(0x0004, NULL, NULL, NULL, NULL);
	Sleep(400);
	mouse_event(0x0002, NULL, NULL, NULL, NULL);
	mouse_event(0x0004, NULL, NULL, NULL, NULL);
	Sleep(400);
}

void ATTACK(void) {
	TARGET();
	Sleep(400);
	keybd_event(VK_F1, NULL, NULL, NULL);
	keybd_event(VK_F2, NULL, NULL, NULL);
	keybd_event(VK_F3, NULL, NULL, NULL);
	keybd_event(VK_F4, NULL, NULL, NULL);
	keybd_event(VK_F5, NULL, NULL, NULL);
	keybd_event(VK_F6, NULL, NULL, NULL);
	keybd_event(VK_F7, NULL, NULL, NULL);
	keybd_event(VK_F8, NULL, NULL, NULL);
	keybd_event(VK_F9, NULL, NULL, NULL);
	keybd_event(VK_F10, NULL, NULL, NULL);
	keybd_event(VK_F11, NULL, NULL, NULL);
	keybd_event(VK_F12, NULL, NULL, NULL);
	pesca();
	//d_ATTACK();
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
				if (!dc) {
					dc = GetDC(window[0]);
				}

				GetCursorPos(&cursor);
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

				color = GetPixel(dc, pos_cursor[0] + 1, pos_cursor[1] + 1);
				marcador(pos_cursor[0], pos_cursor[1]);
				marcador(pos_cursor[2], pos_cursor[3]);
				marcador(pos_cursor[4], pos_cursor[5]);
				color_rgb[0] = static_cast<int>GetRValue(color);
				color_rgb[1] = static_cast<int>GetGValue(color);
				color_rgb[2] = static_cast<int>GetBValue(color);
				color_rgb[3] = RGB(color_rgb[0], color_rgb[1], color_rgb[2]);
				if (color_rgb[3] >= 917341 && color_rgb[3] <= 3254083) {
					pesca();
					ATTACK();
					std::cout << "PEGOU UM POKEMON!!" << std::endl;
				}
				return;
			}
		}
	}
}
