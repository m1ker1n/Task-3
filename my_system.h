#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "components.h"
#include "my_graphics.h"

typedef enum {
	ENTER,
	LEFT,
	UP,
	RIGHT,
	DOWN
} messages_t;

void SystemOpen(HWND hwnd);
void SystemInit();
void SystemRelease();
void SystemUpdate();
void SystemClose();

char* HandleMessages(messages_t msg);

void ReadFile(FILE* streamPtr);
void ParseFile(FILE* streamPtr, char* str);

/* Format:
MenuBegin
	WindowBegin
		[WindowSettings]
		Rectangle = (left,top,right,bottom)
		Color = (R,G,B)
		ButtonBegin
			[ButtonSettings]
			Rectangle = (left,top,right,bottom)
			Color = (R,G,B)
			Name = name
			HighlightColor = (R,G,B)
		ButtonEnd
	WindowEnd
MenuEnd
*/
