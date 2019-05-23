#pragma once
#ifndef __LINKED_LINKED_LIST__
#define __LINKED_LINKED_LIST__
#include <string>
using namespace std;

typedef struct question_s
{
	int        index;
	string     ques;
	string     ans_A;
	string     ans_B;
	string     ans_C;
	string     ans_D;
	string     ans;
} question;

typedef struct node_question
{
	question                    data;
	struct node_question       *next;
} node;

typedef struct linked_list_question
{
	node       *head;
	node       *tail;
	int         size;
} linked_list;

void init_linked_list(linked_list &list);
node *create_node(question ques);
void insert_head(linked_list &list, question ques);
void delete_node(node *ques_node);
void output_list(linked_list list);
void release(linked_list &list);

#endif  //__LINKED_LINKED_LIST__