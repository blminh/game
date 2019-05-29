#include "processing_game.h"
#include "key_event.h"
#include <iostream>

int random(int arr[]) {
    int ran = rand() % 15 + 1;

    for (int i = 0; i < 15; i++) {
        if (arr[i] == 0) {
            arr[i] = ran;
            return ran;
        }
        else if (ran == arr[i]) {
            ran = rand() % 15 + 1;
            i = 0;
        }
    }

    return 0;
}
int process(node *pointer) {
    string ans;
    ANSWER_OPT select = UNDEFINE;
    int move = InputKey();

    switch (move) {
        case 49:
            select = ANS_D;
            ans = pointer->data.ans_D;
        break;

        case 50:
            select = ANS_C;
            ans = pointer->data.ans_C;
        break;

        case 51:
            select = ANS_B;
            ans = pointer->data.ans_B;
        break;

        case 52:
            select = ANS_A;
            ans = pointer->data.ans_A;
        break;

        case 27:
            system("cls");
            gotoXY(40, 10);
            std::cout << "NGUNG CUOC CHOI!!!";
        break;
    }

    switch (select) {
        case ANS_D:
            if (pointer->data.ans == ans)
                return 1;
            else
                return 0;
        break;

        case ANS_C:
            if (pointer->data.ans == ans)
                return 1;
            else
                return 0;
        break;

        case ANS_B:
            if (pointer->data.ans == ans)
                return 1;
            else
                return 0;
        break;

        case ANS_A:
            if (pointer->data.ans == ans)
                return 1;
            else
                return 0;
        break;
    }

    return 0;
}
int Times_Choose(node *pointer) {
    int i = 30;

    while (i >= 0) {
        if(i == 0)
            return 0;

        gotoXY(0, 0);
        std::cout << "Times: " << i;

        if (i < 10) {
            gotoXY(7, 0);
            std::cout << "0" << i;
        }

        if (_kbhit()) {
            if(process(pointer) == 1) {
                system("cls");
                gotoXY(20, 5);
                std::cout << "correct";
                Sleep(1000);
                return 1;
            }else {
                system("cls");
                gotoXY(20, 5);
                std::cout << "incorrect";
                Sleep(1000);
                return 0;
            }

            i = 30;
            system("cls");
            break;
        }

        i--;
        Sleep(1000);
    }

    return 0;
}