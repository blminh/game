#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int num = 1;
    ofstream file;
    file.open("F:/cau_truc_du_lieu/game_ai_la_trieu_phu/Project/test.txt", ios::in);
    if (!file.is_open()) {
        cout << "open fail" << endl;
    }
    while (num != 0) {
        cout << "Input: ";
        cin >> num;
        file << num << endl;
    }
    file.close();
    system("pause");
    return 0;
}