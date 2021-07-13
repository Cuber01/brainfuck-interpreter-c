#include <stdio.h>
#include <stdlib.h>

#include "stack.h"


int16_t stack_index = -1;
STACK_TYPE empty = -1;
STACK_TYPE stack[STACK_LIMIT];




void _Error(char* message, int line, char* file);

int isFull(void)
{
    return (stack_index >= STACK_LIMIT - 1);
}
 
int isEmpty(void)
{
    return (stack_index == -1);
}
 

void push(STACK_TYPE value)
{
    if (isFull())
         _Error("Stack is full", __LINE__, __FILE__);

    if (value == 123){
        int a = 0;
    }

    stack_index++;
    stack[stack_index] = value;

}
 
STACK_TYPE pop()
{
    STACK_TYPE rv;
    
    if (isEmpty()) {
         _Error("Stack is empty", __LINE__, __FILE__);
    }

    rv = stack[stack_index];

    stack[stack_index] = empty;
    stack_index--;

    return rv;
}
 
STACK_TYPE getValue(int i)
{
    if (isEmpty()) {
         _Error("Stack is empty", __LINE__, __FILE__);
    }

    if (stack[i] != empty) {
        return stack[i];
    } else {
       _Error("Index is empty", __LINE__, __FILE__);
    }

    return -1;
}
 
void _Error(char* message, int line, char* file)
{
    printf("Error at line %d in file %s: ", line, file);
    printf("%s", message);
    exit(1);
}



 