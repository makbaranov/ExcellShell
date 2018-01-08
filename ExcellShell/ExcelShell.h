#pragma once
// ��������� SDKDDKVer.h ������������ ����������� ����� ��������� ��������� ��������� Windows.

// ���� ��������� ��������� ������ ���������� ��� ���������� ������ Windows, �������� WinSDKVer.h �
// ������� ��� ������� _WIN32_WINNT �������� �������������� ��������� ����� ���������� SDKDDKVer.h.
#include <SDKDDKVer.h>

#include <string>
#include <locale>
#include <windows.h>
#include <algorithm> // all_of, copy, fill, find, for_each, none_of, remove, reverse, transform
#include <iostream> // istream, ostream
#include <sstream> // stringstream
#include <fstream>
#include <vector>

#define BREAK_ON_FAIL(x) if (FAILED(hr = x)) break;
#define MAX_COLUMN 40
#define VISIBLE 1 //app.visible = 1, invisible = 0;

enum columns
{
	A_COLUMN = 1, B_COLUMN, C_COLUMN, D_COLUMN, E_COLUMN,
	F_COLUMN, G_COLUMN, H_COLUMN, I_COLUMN, J_COLUMN,
	K_COLUMN, L_COLUMN, M_COLUMN, N_COLUMN, O_COLUMN,
	P_COLUMN, Q_COLUMN, R_COLUMN, S_COLUMN, T_COLUMN,
	U_COLUMN, V_COLUMN, W_COLUMN, X_COLUMN, Y_COLUMN,
	Z_COLUMN,
	AA_COLUMN, AB_COLUMN, AC_COLUMN, AD_COLUMN, AE_COLUMN,
	AF_COLUMN, AG_COLUMN, AH_COLUMN, AI_COLUMN, AJ_COLUMN,
	AK_COLUMN, AL_COLUMN, AM_COLUMN, AN_COLUMN, AO_COLUMN,
	AP_COLUMN, AQ_COLUMN, AR_COLUMN, AS_COLUMN, AT_COLUMN,
	AU_COLUMN, AV_COLUMN, AW_COLUMN, AX_COLUMN, AY_COLUMN,
	AZ_COLUMN
};

#define BLACK 0x0
#define WHITE 0xFFFFFF
#define DARK_GREEN 0x008000
#define BROWN 0xC3C83
#define BLUE 0xFF0000
#define GRAY 14277081
#define RED 0x0000FF
#define LIGHT_BROWN 8696052
#define PINK 13408767
#define CREAM 0xADCBF8

struct xls_t
{
	VARIANT app;
	VARIANT wbs;
	VARIANT wb;
	VARIANT wss;
	VARIANT ws;
};

HRESULT AutoWrap(int autoType, VARIANT *pvResult, IDispatch *pDisp, LPOLESTR ptName, int cArgs...);

std::wstring str_to_wstr(const std::string &s, const unsigned cp = CP_ACP);
std::string wstr_to_str(const std::wstring &s, const unsigned cp = CP_ACP);

HRESULT proc_beg(const std::wstring &path, xls_t * const xls, bool visible = true); //open if path.size() != 0 or add if path.size() == 0
HRESULT proc_end(HRESULT hr, xls_t * const xls, bool save = true, bool close = true);

HRESULT activate_sheet(xls_t * const xls, int sheetnum);

HRESULT read(VARIANT ws, int _r, int _c, std::wstring * const _x);
HRESULT read_formula(VARIANT ws, int _r, int _c, std::wstring * const _x);
int read_int(VARIANT ws, int _r, int _c);

HRESULT write(xls_t * const xls, int _r, int _c, std::wstring wstr);

int get_inter_color(VARIANT ws, int _r, int _c);
HRESULT get_inter_color(VARIANT ws, int _r, int _c, int *color);
HRESULT set_inter_color(VARIANT ws, int _r, int _c, const int color);
HRESULT set_inter_color_range(xls_t * const xls, int r_since, int c_since, int r_before, int c_before, const int color);

int get_font_color(VARIANT ws, int _r, int _c);
HRESULT get_font_color(VARIANT ws, int _r, int _c, int *x);
HRESULT set_font_color(VARIANT ws, int _r, int _c, const int x);
HRESULT set_font_color_range(xls_t * const xls, int r_since, int c_since, int r_before, int c_before, const int x);

bool get_italic(VARIANT ws, int _r, int _c);
HRESULT get_italic(VARIANT ws, int _r, int _c, bool* state);
HRESULT set_italic(VARIANT ws, int _r, int _c, bool state);
HRESULT set_italic_range(xls_t * const xls, int r_since, int c_since, int r_before, int c_before, bool state);

bool get_bold(VARIANT ws, int _r, int _c);
HRESULT set_bold_range(xls_t * const xls, bool state, int r_since, int c_since, int r_before, int c_before);

std::wstring get_cell(int r, int c);

void erase_range(xls_t * const xls, int r_since, int c_since, int r_before, int c_before);