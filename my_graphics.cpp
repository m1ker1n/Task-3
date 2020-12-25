#include "my_graphics.h"

HWND hWnd;

void InitWindow(HWND hwnd) {
	hWnd = hwnd;
}

void ClearWindow() {
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	LPRECT rect = (LPRECT)malloc(sizeof(RECT));
	GetWindowRect(hWnd, rect);
	HBRUSH hBrush = CreateSolidBrush(GetBkColor(hdc));
	HPEN hPen = CreatePen(PS_SOLID, 0, GetBkColor(hdc));
	Rectangle(hdc, 0, 0, rect->right, rect->bottom);
	free(rect);
	EndPaint(hWnd, &ps);
}

void DrawMenu(menu_t* menu, activeComponent* actComp) {
	if (!menu && !actComp) {
		ClearWindow();
	}
	else {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		DrawMenuWindows(hdc, menu->firstWindow);

		DrawActiveComp(hdc, actComp);
		EndPaint(hWnd, &ps);
	}
}

void DrawActiveComp(HDC hdc, activeComponent* actComp) {
	DrawWindow(hdc, actComp->window);
	DrawWindowButtons(hdc, actComp->window->firstButton);
	DrawButton(hdc, actComp->button, 1);
}

void DrawWindowButtons(HDC hdc, button_t* button) {
	button_t* tempButton = button;
	while (tempButton->next != button) {
		DrawButton(hdc, tempButton, 0);
		tempButton = tempButton->next;
	}
	DrawButton(hdc, tempButton, 0);
}

void DrawMenuWindows(HDC hdc, window_t* window) {
	window_t* tempWindow = window;
	while (tempWindow->next != window) {
		DrawWindow(hdc, tempWindow);
		DrawWindowButtons(hdc, tempWindow->firstButton);
		tempWindow = tempWindow->next;
	}
	DrawWindow(hdc, tempWindow);
	DrawWindowButtons(hdc, tempWindow->firstButton);
}

void DrawButton(HDC hdc,button_t* button, int isActive) {
	HBRUSH hBrush;
	BSets* sets = button->sets;
	if (!isActive)
		hBrush = CreateSolidBrush(sets->color);
	else
		hBrush = CreateSolidBrush(sets->highlightColor);
	SelectObject(hdc, hBrush);
	Rectangle(hdc, sets->left, sets->top, sets->right, sets->bottom);

	TextOutA(hdc, sets->left+5, sets->top+5, sets->name, strlen(sets->name));
}

void DrawWindow(HDC hdc, window_t* window) {
	HBRUSH hBrush;
	WSets* sets = window->sets;
	hBrush=CreateSolidBrush(sets->color);
	SelectObject(hdc, hBrush);
	Rectangle(hdc, sets->left, sets->top, sets->right, sets->bottom);
}
