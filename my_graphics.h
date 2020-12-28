#pragma once
#include "my_system.h"

void InitWindow(HWND hwnd);

void DrawMenu(menu_t* menu, activeComponent* actComp);
void DrawMenuWindows(HDC hdc, window_t* window);
void DrawWindowButtons(HDC hdc, button_t* button);
void DrawActiveComp(HDC hdc, activeComponent* actComp);
void DrawButton(HDC hdc, button_t* button, int isActive);
void DrawWindow(HDC hdc, window_t* window);
void ClearWindow();