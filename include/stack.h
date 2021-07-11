#ifndef __STACK_H
#define __STACK_H

#include "main.h"

#define STACK_LIMIT 50
#define STACK_TYPE bracket_t

extern int stack_index;
extern STACK_TYPE stack[STACK_LIMIT];

int isFull(void);
int isEmpty(void);
void push(STACK_TYPE value);
STACK_TYPE pop(void);
STACK_TYPE getValue(int i);


#endif