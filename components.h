#pragma once
#include <Windows.h>
#include <stdlib.h>


typedef struct buttonSettings_t {
	int left, top, right, bottom;
	COLORREF color;
	COLORREF highlightColor;
	char* name;
}buttonSettings_t, BSets;

typedef struct button_t {
	BSets* sets;
	button_t* prev;
	button_t* next;
}button_t;

typedef struct windowSettings_t {
	int left, top, right, bottom;
	COLORREF color;
}windowSettings_t, WSets;

typedef struct window_t {
	WSets* sets;
	window_t* prev;
	window_t* next;
	button_t* firstButton;
	button_t* lastButton;
}window_t;

typedef struct menu_t {
	window_t* firstWindow;
	window_t* lastWindow;
}menu_t;

//add elem after last elem of list of windows
void AddWindow(menu_t* menu);
//add elem after last elem of list of buttons
void AddButton(window_t* window);

void LoadWindowSets(window_t* window, WSets* sets);
void LoadButtonSets(button_t* button, BSets* sets);

BSets* GetButtonSets(int left, int top, int right, int bot, COLORREF color, char* name, COLORREF highlightColor);
WSets* GetWindowSets(int left, int top, int right, int bot, COLORREF color);

void ReleaseWindows(menu_t* menu);
void ReleaseButtons(window_t* window);

