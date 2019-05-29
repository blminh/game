#include "linked_list.h"
#include "key_event.h"
#include <iostream>

using namespace std;

void init_linked_list(linked_list &list) {
    list.head = NULL;
    list.tail = NULL;
}
node *create_node(question ques) {
    node *pointer = new node;
    pointer->data = ques;
    pointer->next = NULL;

    return pointer;
}
question insert_ques(int index, string quest, string ans_A, string ans_B, string ans_C, string ans_D, string ans) {
    question ques;

    ques.index = index;
    ques.ques = quest;
    ques.ans_A = ans_A;
    ques.ans_B = ans_B;
    ques.ans_C = ans_C;
    ques.ans_D = ans_D;
    ques.ans = ans;

    return ques;
}
void insert_head(linked_list &list, question ques) {
    node *pointer = create_node(ques);

    if (pointer == NULL) {
        exit(1);
    }
    if (list.head == NULL) {
        list.head = list.tail = pointer;
    }
    else {
        pointer->next = list.head;
        list.head = pointer;
    }
}
void output_ques(node *pointer_ques, int k) {
    gotoXY(8, 3);
    cout << "Cau hoi " << k << ": " << pointer_ques->data.ques;
    gotoXY(8, 9);
    cout << pointer_ques->data.ans_D;
    gotoXY(8, 15);
    cout << pointer_ques->data.ans_C;
    gotoXY(53, 9);
    cout << pointer_ques->data.ans_B;
    gotoXY(53, 15);
    cout << pointer_ques->data.ans_A;
}