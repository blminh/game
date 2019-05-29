#ifndef __PROCESSING_GAME__
#define __PROCESSING_GAME__
#include "linked_list.h"

enum ANSWER_OPT
{
    ANS_D = 1,
    ANS_C = 2,
    ANS_B = 3,
    ANS_A = 4,
    UNDEFINE
};

int random(int arr[]);
int process(node *pointer);
int Times_Choose(node *pointer);

#endif // __PROCESSING_GAME__
