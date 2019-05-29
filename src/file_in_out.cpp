#include "file_in_out.h"
#include "key_event.h"
#include "linked_list.h"
#include <iostream>
#include <fstream>

using namespace std;

int director = 2;
int highscore[3] = { 0 };

void read_file(linked_list &list) {
    string quest, ans_A, ans_B, ans_C, ans_D, ans;
    int index = 1;
    ifstream fileout;

    fileout.open("F:/cau_truc_du_lieu/Game_ALTP/cauhoi.txt", ios::out);
    if (!fileout.is_open()) {
        cout << "Can not open file." << endl;
        return;
    }
    while (!fileout.eof()) {
        getline(fileout, quest);
        getline(fileout, ans_D);
        getline(fileout, ans_C);
        getline(fileout, ans_B);
        getline(fileout, ans_A);
        getline(fileout, ans);

        question ques = insert_ques(index, quest, ans_A, ans_B, ans_C, ans_D, ans);
        insert_head(list, ques);
        index++;
    }
    fileout.close();
}
void Introduce() {
    string money;
    int y = 6;
    ifstream fileout;

    fileout.open("F:/cau_truc_du_lieu/Game_ALTP/tien_thuong.txt", ios::out);
    if (!fileout.is_open()) {
        cout << "Can not open file." << endl;
        return;
    }
    while (!fileout.eof()) {
        getline(fileout, money);
        gotoXY(40, y);
        cout << money;
        y++;
    }
    fileout.close();
}
void file_high_score(int high_score, int &flag){
    int i = 0;
    ifstream fileout;

    fileout.open("F:/cau_truc_du_lieu/Game_ALTP/high_score.txt", ios::out);
    if (!fileout.is_open()) {
        cout << "Can not open file." << endl;
        return;
    }
    while(!fileout.eof()) {
        fileout >> highscore[i];
        i++;
    }
    fileout.close();

    if (high_score > highscore[0]) {
        highscore[2] = highscore[1];
        highscore[1] = highscore[0];
        highscore[0] = high_score;
        flag = 1;
    }
    else if(high_score > highscore[1]){
        highscore[2] = highscore[1];
        highscore[1] = high_score;
        flag = 1;
    }
    else if(high_score > highscore[2]){
        highscore[2] = high_score;
        flag = 1;
    }
    else flag = 0;

    ofstream filein;
    filein.open("F:/cau_truc_du_lieu/Game_ALTP/high_score.txt", ios::in);
    if (!filein.is_open()) {
        cout << "Can not open file." << endl;
        return;
    }
    for(int j = 0; j < 3; j++){
        filein << highscore[j] << endl;
    }
    filein.close();
}
void highScore(){
    int i = 0;
    ifstream fileout;

    fileout.open("F:/cau_truc_du_lieu/Game_ALTP/high_score.txt", ios::out);
    if (!fileout.is_open()) {
        cout << "Can not open file." << endl;
        return;
    }
    while(!fileout.eof()) {
        fileout >> highscore[i];
        i++;
    }
    for (int j = 0; j < 3; j++) {
        cout << highscore[j] << endl;
    }
    fileout.close();
}