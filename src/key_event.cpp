#include"key_event.h"

using namespace std;

int InputKey() {
    if (_kbhit()) {
        int key = _getch();

        if (key == 224) {
            key = _getch();
            return key + 1000;
        }
        return key;
    }
    else
        return KEY_NONE;

    return KEY_NONE;
}

void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void noCursorType() {
    CONSOLE_CURSOR_INFO info;
    info.bVisible = FALSE;
    info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}