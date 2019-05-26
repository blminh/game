#include "key_event.h"
#include "linked_list.h"
#include "file_in_out.h"
#include "move_position.h"
#include "paint_menu.h"
#include "Menu.h"
#include "processing_game.h"
#include "play_game.h"
#include <iostream>

int main()
{
    int cont = 1;
    while (cont == 1) {
        system("cls");
        switch (Menu()) {
        case 1: {
            play_game();
            break;
        }
        case 2: {
            system("cls");
            highScore();
            std::cout << endl;
            std::cout << "Wait 5s!";
            Sleep(5000);
            continue;
        }break;
        case 3: {
            system("cls");
            Introduce();
            std::cout << endl;
            std::cout << "Wait 5s!";
            Sleep(5000);
            continue;
        }break;
        case 4: {
            return 0;
        }
        }

        std::cout << "Ban muon choi tiep!\n(1: tiep, 0: thoat)\n";
        std::cin >> cont;
    }
    return 0;
}