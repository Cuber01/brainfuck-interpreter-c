#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


int stack_index = -1;
STACK_TYPE empty = {'e', -1};
STACK_TYPE stack[STACK_LIMIT];




void _Error(char* message, int line, char* file);

int isFull(void)
{
    return stack_index >= STACK_LIMIT - 1;
}
 
int isEmpty(void)
{
    return (stack_index == -1);
}
 

void push(STACK_TYPE value)
{
    if (isFull())
        _Error("Stack is full", __LINE__, __FILE__);

    stack_index++;
    stack[stack_index] = value;


    printf("pushed to stack\n");
}
 
STACK_TYPE pop()
{
    STACK_TYPE rv;
    
    if (isEmpty())
        _Error("Stack is empty", __LINE__, __FILE__);

    rv = stack[stack_index];

    stack[stack_index] = empty; //edit this
    stack_index--;

    return rv;
}
 
STACK_TYPE getValue(int i)
{
    if (isEmpty())
        _Error("Stack is empty", __LINE__, __FILE__);

    return stack[i];
}
 
void _Error(char* message, int line, char* file)
{
    printf("Error at line %d in file %s: ", line, file);
    printf("%s", message);
    exit(1);
}



 