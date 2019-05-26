// #include <fstream>
// #include "key_event.h"
// #include <iostream>
// #include <conio.h>
// #include <string>

// using namespace std;

// typedef struct question
// {
//     int     index;
//     string  ques;
//     string  ans_A;
//     string  ans_B;
//     string  ans_C;
//     string  ans_D;
//     string  ans;
// };
// typedef struct node_question
// {
//     question             data;
//     node_question       *next;
// } node;

// typedef struct linked_list_question
// {
//     node       *head;
//     node       *tail;
// } linked_list;
// typedef struct coordinates
// {
//     int x, y;
// };

// #define UP      1
// #define DOWN    2
// #define LEFT    3
// #define RIGHT   4

// void init_linked_list(linked_list &list);
// node *create_node(question ques);
// question insert_ques(int index, string ques, string ans_A, string ans_B, string ans_C, string ans_D, string ans);
// void insert_head(linked_list &list, question ques);
// coordinates Selection(coordinates &coor);
// int random(int arr[]);
// int process(node *pointer);
// void read_file(linked_list &list);
// void output_ques(node *pointer_ques, int k);
// int Times_Choose(node *pointer);
// void GiaoDien();
// int Menu();
// void MocThuong();
// void file_high_score(int high_score, int &flag);
// void high();

// int director = 2;
// int score[3] = {0};

// int main()
// {
//     int cont = 1;
//     while (cont == 1) {
//         system("cls");
//         switch (Menu()) {
//         case 1: {
//             system("cls");
//             linked_list list;
//             init_linked_list(list);
//             read_file(list);
//             node *p = new node;
//             p = list.head;
//             int arr[15] = { 0 };
//             int k = 1;
//             int diem = 0, flag = 0;
//             do {
//                 int ran = random(arr);
//                 node *q = new node;
//                 q = list.head;
//                 while (q != NULL) {
//                     if (q->data.index == ran) {
//                         GiaoDien();
//                         output_ques(q, k);
//                         if(Times_Choose(q) == 1){
//                             diem++;
//                         }
//                         else{
//                             goto end;
//                         }
//                         k++;
//                         break;
//                     }
//                     q = q->next;
//                 }
//                 p = p->next;
//             } while (p != NULL);
//             if(k == 15){ end:
//                 system("cls");
//                 cout << "END GAME";
//                 file_high_score(diem, flag);
//                 if(flag == 1)
//                     cout << "High Score\n";
//                 Sleep(1000);
//                 break;
//             }
//             break;
//         }
//         case 2: {
//             system("cls");
//             high();
//             cout << endl;
//             cout << "Wait 5s!";
//             Sleep(5000);
//             continue;
//         }break;
//         case 3: {
//             system("cls");
//             MocThuong();
//             cout << endl;
//             cout << "Wait 5s!";
//             Sleep(5000);
//             continue;
//         }break;
//         case 4: {
//             return 0;
//         }
//         }

//         cout << "Ban muon choi tiep!\n(1: tiep, 0: thoat)\n";
//         cin >> cont;
//     }
//     //system("pause");
//     return 0;
// }

// void init_linked_list(linked_list &list) {
//     list.head = NULL;
//     list.tail = NULL;
// }
// node *create_node(question ques) {
//     node *pointer = new node;
//     pointer->data = ques;
//     pointer->next = NULL;
//     return pointer;
// }
// question insert_ques(int index, string quest, string ans_A, string ans_B, string ans_C, string ans_D, string ans) {
//     question ques;
//     ques.index = index;
//     ques.ques = quest;
//     ques.ans_A = ans_A;
//     ques.ans_B = ans_B;
//     ques.ans_C = ans_C;
//     ques.ans_D = ans_D;
//     ques.ans = ans;
//     return ques;
// }
// void insert_head(linked_list &list, question ques) {
//     node *pointer = create_node(ques);
//     if (pointer == NULL) {
//         exit(1);
//     }
//     if (list.head == NULL) {
//         list.head = list.tail = pointer;
//     }
//     else {
//         pointer->next = list.head;
//         list.head = pointer;
//     }
// }
// void output_ques(node *pointer_ques, int k) {
//     gotoXY(8, 3);
//     cout << "Cau hoi " << k << ": " << pointer_ques->data.ques;
//     gotoXY(8, 9);
//     cout << pointer_ques->data.ans_D;
//     gotoXY(8, 15);
//     cout << pointer_ques->data.ans_C;
//     gotoXY(53, 9);
//     cout << pointer_ques->data.ans_B;
//     gotoXY(53, 15);
//     cout << pointer_ques->data.ans_A;
// }
// coordinates Selection(coordinates &coor) {
//     int select;
//     noCursorType();
//     gotoXY(48, 12);
//     cout << char(16);
//     while (coor.y >= 12 && coor.y <= 18)
//     {
//         if (_kbhit())
//         {
//             int key = InputKey();
//             if (key == 13)
//             {
//                 select = 5;
//                 break;
//             }
//             if (key == 's' || key == 'S' || key == KEY_DOWN)
//                 director = 2;
//             else if (key == 'w' || key == 'W' || key == KEY_UP)
//                 director = 1;
//             switch (director)
//             {
//             case 1:
//                 coor.y = coor.y - 2;
//                 break;
//             case 2:
//                 coor.y = coor.y + 2;
//                 break;
//             }
//             gotoXY(48, coor.y - 2);
//             cout << " ";
//             gotoXY(48, coor.y + 2);
//             cout << " ";
//             if (coor.y >= 12 && coor.y <= 18)
//             {
//                 gotoXY(48, coor.y);
//                 cout << char(16);
//             }
//             if (coor.y < 12)
//             {
//                 coor.y = 18;
//                 gotoXY(48, 10);
//                 cout << " ";
//                 gotoXY(48, coor.y);
//                 cout << char(16);
//             }
//             if (coor.y > 18)
//             {
//                 coor.y = 12;
//                 gotoXY(48, 20);
//                 cout << " ";
//                 gotoXY(48, coor.y);
//                 cout << char(16);
//             }
//         }
//     }
//     if (coor.y == 12 && select == 5)
//         coor.y = 12;
//     else if (coor.y == 14 && select == 5)
//         coor.y = 14;
//     else if (coor.y == 16 && select == 5)
//         coor.y = 16;
//     else if (coor.y == 18 && select == 5)
//         coor.y = 18;
//     return coor;
// }
// int random(int arr[]) {
//     int ran = rand() % 15 + 1;
//     for (int i = 0; i < 15; i++) {
//         if (arr[i] == 0) {
//             arr[i] = ran;
//             return ran;
//         }
//         else if (ran == arr[i]) {
//             ran = rand() % 15 + 1;
//             i = 0;
//         }
//     }
// }
// int process(node *pointer) {
//     string ans;
//     int select = 0;
//     int move = InputKey();
//     switch (move)
//     {
//     case 49:
//     {
//         select = 1;
//         ans = pointer->data.ans_D;
//     }break;
//     case 50:
//     {
//         select = 2;
//         ans = pointer->data.ans_C;
//     }break;
//     case 51:
//     {
//         select = 3;
//         ans = pointer->data.ans_B;
//     }break;
//     case 52:
//     {
//         select = 4;
//         ans = pointer->data.ans_A;
//     }break;
//     /*69: e, 81 : q, 82 : r, 87 : w;*/
//     case 53:
//     {
//         //Help(1);
//     }break;
//     case 27:
//     {
//         system("cls");
//         gotoXY(40, 10);
//         cout << "NGUNG CUOC CHOI!!!";
//     }break;
//     }
//     switch (select)
//     {
//     case 1:
//     {
//         if (pointer->data.ans == ans)
//             return 1;
//         else
//             return 0;
//     }break;
//     case 2:
//     {
//         if (pointer->data.ans == ans)
//             return 1;
//         else
//             return 0;
//     }break;
//     case 3:
//     {
//         if (pointer->data.ans == ans)
//             return 1;
//         else
//             return 0;
//     }break;
//     case 4:
//     {
//         if (pointer->data.ans == ans)
//             return 1;
//         else
//             return 0;
//     }break;
//     }
// }
// int Times_Choose(node *pointer) {
//     int i = 30;
//     while (i >= 0)
//     {
//         if(i == 0)
//             return 0;
//         gotoXY(0, 0);
//         cout << "Times: " << i;
//         if (i < 10)
//         {
//             gotoXY(7, 0);
//             cout << "0" << i;
//         }
//         if (_kbhit())
//         {
//             if(process(pointer) == 1){
//                 system("cls");
//                 gotoXY(20, 5);
//                 cout << "correct";
//                 Sleep(1000);
//                 return 1;
//             }else {
//                 system("cls");
//                 gotoXY(20, 5);
//                 cout << "incorrect";
//                 Sleep(1000);
//                 return 0;
//             }
//             i = 30;
//             system("cls");
//             break;
//         }
//         i--;
//         Sleep(1000);
//     }
// }
// int Menu() {
//     int chon;
//     // VeChu('a', 1); VeChu('i', 1); VeChu('l', 1); VeChu('a', 2); VeChu('t', 1); VeChu('r', 1); 
//     // VeChu('i', 2); VeChu('e', 1); VeChu('u', 1); VeChu('p', 1); VeChu('h', 1); VeChu('u', 2);
//     gotoXY(50, 12);
//     cout << "VAO GAME";
//     gotoXY(50, 14);
//     cout << "DIEM CAO NHAT";
//     gotoXY(50, 16);
//     cout << "HUONG DAN";
//     gotoXY(50, 18);
//     cout << "THOAT";
//     coordinates coor;
//     coor.x = 48;
//     coor.y = 12;
//     Selection(coor);
//     if (coor.y == 12)
//         chon = 1;
//     else if (coor.y == 14)
//         chon = 2;
//     else if (coor.y == 16)
//         chon = 3;
//     else if (coor.y == 18)
//         chon = 4;
//     return chon;
// }
// void GiaoDien() {
//     gotoXY(5, 1);
//     cout << " __________________________________________________________________________________";
//     gotoXY(5, 2);
//     cout << "|                                                                                  |";
//     gotoXY(5, 3);
//     cout << "|                                                                                  |";
//     gotoXY(5, 4);
//     cout << "|                                                                                  |";
//     gotoXY(5, 5);
//     cout << "|__________________________________________________________________________________|";
//     gotoXY(5, 7);
//     cout << " _____________________________________";
//     gotoXY(5, 8);
//     cout << "|                                     |";
//     gotoXY(5, 9);
//     cout << "|                                     |";
//     gotoXY(5, 10);
//     cout << "|                                     |";
//     gotoXY(5, 11);
//     cout << "|_____________________________________|";
//     gotoXY(5, 13);
//     cout << " _____________________________________";
//     gotoXY(5, 14);
//     cout << "|                                     |";
//     gotoXY(5, 15);
//     cout << "|                                     |";
//     gotoXY(5, 16);
//     cout << "|                                     |";
//     gotoXY(5, 17);
//     cout << "|_____________________________________|";
//     gotoXY(50, 7);
//     cout << " _____________________________________";
//     gotoXY(50, 8);
//     cout << "|                                     |";
//     gotoXY(50, 9);
//     cout << "|                                     |";
//     gotoXY(50, 10);
//     cout << "|                                     |";
//     gotoXY(50, 11);
//     cout << "|_____________________________________|";
//     gotoXY(50, 13);
//     cout << " _____________________________________";
//     gotoXY(50, 14);
//     cout << "|                                     |";
//     gotoXY(50, 15);
//     cout << "|                                     |";
//     gotoXY(50, 16);
//     cout << "|                                     |";
//     gotoXY(50, 17);
//     cout << "|_____________________________________|";
// }
// void read_file(linked_list &list) {
    
//     string quest, ans_A, ans_B, ans_C, ans_D, ans;
//     int index = 1;
//     ifstream fileout;
//     fileout.open("F:/cau_truc_du_lieu/Game_ALTP/cauhoi.txt", ios::out);
//     if (!fileout.is_open()) {
//         cout << "Can not open file." << endl;
//         return;
//     }
//     while (!fileout.eof()) {
//         getline(fileout, quest);
//         getline(fileout, ans_D);
//         getline(fileout, ans_C);
//         getline(fileout, ans_B);
//         getline(fileout, ans_A);
//         getline(fileout, ans);
//         question ques = insert_ques(index, quest, ans_A, ans_B, ans_C, ans_D, ans);
//         insert_head(list, ques);
//         index++;
//     }
//     fileout.close();
// }
// void MocThuong() {
//     string money;
//     int y = 6;
//     ifstream fileout;
//     fileout.open("F:/cau_truc_du_lieu/Game_ALTP/tien_thuong.txt", ios::out);
//     if (!fileout.is_open()) {
//         cout << "Can not open file." << endl;
//         return;
//     }
//     while (!fileout.eof()) {
//         getline(fileout, money);
//         gotoXY(40, y);
//         cout << money;
//         y++;
//     }
//     fileout.close();
// }
// void file_high_score(int high_score, int &flag){
//     int i = 0;
//     ifstream fileout;
//     fileout.open("F:/cau_truc_du_lieu/Game_ALTP/high_score.txt", ios::out);
//     if (!fileout.is_open()) {
//         cout << "Can not open file." << endl;
//         return;
//     }
//     while(!fileout.eof()) {
//         fileout >> score[i];
//         i++;
//     }
//     fileout.close();

//     if (high_score > score[0]) {
//         score[2] = score[1];
//         score[1] = score[0];
//         score[0] = high_score;
//         flag = 1;
//     }
//     else if(high_score > score[1]){
//         score[2] = score[1];
//         score[1] = high_score;
//         flag = 1;
//     }
//     else if(high_score > score[2]){
//         score[2] = high_score;
//         flag = 1;
//     }
//     else flag = 0;

//     ofstream filein;
//     filein.open("F:/cau_truc_du_lieu/Game_ALTP/high_score.txt", ios::in);
//     if (!filein.is_open()) {
//         cout << "Can not open file." << endl;
//         return;
//     }
//     for(int j = 0; j < 3; j++){
//         filein << score[j] << endl;
//     }
//     filein.close();
// }
// void high(){
//     int i = 0;
//     ifstream fileout;
//     fileout.open("F:/cau_truc_du_lieu/Game_ALTP/high_score.txt", ios::out);
//     if (!fileout.is_open()) {
//         cout << "Can not open file." << endl;
//         return;
//     }
//     while(!fileout.eof()) {
//         fileout >> score[i];
//         i++;
//     }
// 	for (int j = 0; j < 3; j++) {
// 		cout << score[j] << endl;
// 	}
//     fileout.close();
// }