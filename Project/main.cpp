#include "linked_list.h"
#include <iostream>

using namespace std;

int main()
{
	question quest;
	node *process;
	linked_list list;
	init_linked_list(list);
	int tiep = 1;
	while (tiep == 1) {
		cout << "Nhap so thu tu: ";
		cin >> quest.index;
		cout << "nhap cau hoi: ";
		cin >> quest.ques;
		cout << "nhap dap an A: ";
		cin >> quest.ans_A;
		cout << "nhap dap an B: ";
		cin >> quest.ans_B;
		cout << "nhap dap an C: ";
		cin >> quest.ans_C;
		cout << "nhap dap an D: ";
		cin >> quest.ans_D;
		cout << "nhap dap an dung: ";
		cin >> quest.ans;
		insert_head(list, quest);
		cout << "1: tiep, 0: thoat\n";
		cin >> tiep;
	}
	output_list(list);
	cout << endl;

	system("pause");
	return 0;
}