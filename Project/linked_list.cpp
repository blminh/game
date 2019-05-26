#include <string>
#include <iostream>
#include "linked_list.h"

using namespace std;

void init_linked_list(linked_list &list)
{
	cout << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << endl;
	list.head = NULL;
	list.tail = NULL;
	list.size = 0;
}
node *create_node(question ques)
{
	cout << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << endl;
	node *pointer = new node;
	pointer->data = ques;
	pointer->next = NULL;
	return pointer;
}
void insert_head(linked_list &list, question ques)
{
	cout << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << endl;
	node *pointer = create_node(ques);
	if (pointer == NULL) {
		exit(1);
	}
	if (list.head == NULL) {
		list.head = list.tail = pointer;
		list.size++;
	}
	else {
		pointer->next = list.head;
		list.head = pointer;
		list.size++;
	}
}
void delete_node(linked_list &list, int index) {
	cout << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << endl;
	node *element = new node;
	node *element1 = list.head;
	int flag = 2;
	while (element1 != NULL) {
		element = element1->next;
		if (flag == index) {
			element1 = element1->next;
			delete element1->next;
			element1->next = element;
			list.size--;
		}
		flag++;
		element1 = element1->next;
	}
	if (flag == 2)
		cout << "\nKhong co gia tri ban vua nhap";
	else cout << "\nXoa thanh cong";
}
void output_list(linked_list list) {
	cout << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << endl;
	node *element = list.head;
	while (element != NULL) {
		cout << element->data.ans;
		cout << element->data.ans_A;
		cout << element->data.ans_B;
		cout << element->data.ans_C;
		cout << element->data.ans_D;
		element = element->next;
	}
}
void release(linked_list &list) {
	cout << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << endl;
	node *element = list.head;
	int index = 1;
	while (element != NULL) {
		delete_node(list, index);
		index++;
		element = element->next;
	}
}