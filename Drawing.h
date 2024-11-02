#pragma once
#include <sstream>
#include <string>
#include "includes.h"

namespace Drawing
{
	void Draw_Text(LPCSTR TextToDraw, int x, int y, D3DCOLOR Colour, LPD3DXFONT m_font);
	void DrawFilledRect(int x, int y, int w, int h, D3DCOLOR color);
	void DrawBorderBox(int x, int y, int w, int h, int thickness, D3DCOLOR Colour);
	void DrawString(char* String, int x, int y, int a, int r, int g, int b, ID3DXFont* font);
};

struct SD3DVertex {
	float x, y, z, rhw;
	DWORD colour;
	static const DWORD FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;
};



std::string IntToString(int number);
std::string FloatToString(float number);
void DrawCircleFilled(float mx, float my, float r, D3DCOLOR color, IDirect3DDevice9Ex* p_Device);
void DrawLine(float x, float y, float xx, float yy, float zoom, int r, int g, int b, int a);