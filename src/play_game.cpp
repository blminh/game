#include "play_game.h"
#include "linked_list.h"
#include "processing_game.h"
#include "paint_menu.h"
#include "file_in_out.h"
#include <iostream>
#include <windows.h>

void play_game(){
    system("cls");
    linked_list list;
    init_linked_list(list);
    read_file(list);
    node *p = new node;
    p = list.head;
    int arr[15] = { 0 };
    int k = 1;
    int diem = 0, flag = 0;
    do {
        int ran = random(arr);
        node *q = new node;
        q = list.head;
        while (q != NULL) {
            if (q->data.index == ran) {
                GiaoDien();
                output_ques(q, k);
                if(Times_Choose(q) == 1){
                    diem++;
                }
                else{
                    goto end;
                }
                k++;
                break;
            }
            q = q->next;
        }
        p = p->next;
    } while (p != NULL);
    if(k == 15){ end:
        system("cls");
        std::cout << "END GAME";
        file_high_score(diem, flag);
        if(flag == 1)
            std::cout << "High Score\n";
        Sleep(1000);
    }
}