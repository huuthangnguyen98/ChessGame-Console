#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <stack>
#include <MMSystem.h>
#pragma comment (lib, "winmm.lib")
#include <iomanip>
#define minx 4
#define miny 3
using namespace std;
// Hàm xóa màn hình.
void XoaManHinh();
// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y);
// Hàm tô màu.
void textcolor(int x);
// Chỉnh màn hình chơi
void SetWindow(int Width, int Height);
// Thời gian thực
const std::string currentDateTime();
// Hàm ẩn đi con trỏ
void Nocursortype();