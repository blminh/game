#ifndef __LIST__
#define __LIST__

#include <string>
using namespace std;

typedef struct question_s {
    int     index;
    string  ques;
    string  ans_A;
    string  ans_B;
    string  ans_C;
    string  ans_D;
    string  ans;
}question;

typedef struct node_question {
    question             data;
    node_question       *next;
} node;

typedef struct linked_list_question {
    node       *head;
    node       *tail;
} linked_list;

void init_linked_list(linked_list &list);
node *create_node(question ques);
question insert_ques(int index, string ques, string ans_A, string ans_B, string ans_C, string ans_D, string ans);
void insert_head(linked_list &list, question ques);
void output_ques(node *pointer_ques, int k);

#endif // __LIST__