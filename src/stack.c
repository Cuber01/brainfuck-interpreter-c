#include <stdio.h>
#include <stdlib.h>

int stack_index = -1;
#define STACK_LIMIT 50
int stack[STACK_LIMIT];

void _Error(char* message, int line, char* file);

int isFull(void)
{
    return stack_index >= STACK_LIMIT - 1;
}
 
int isEmpty(void)
{
    return (stack_index == -1);
}
 

void push(int value)
{
    if (isFull())
        _Error("Stack is full", __LINE__, __FILE__);

    stack_index++;
    stack[stack_index] = value;


    printf("%d pushed to stack\n", value);
}
 
int pop()
{
    int rv;
    
    if (isEmpty())
        _Error("Stack is empty", __LINE__, __FILE__);

    rv = stack[stack_index];

    stack[stack_index] = -1;
    stack_index--;

    return rv;
}
 
int getValue(int ind)
{
    if (isEmpty())
        _Error("Stack is empty", __LINE__, __FILE__);

    return stack[ind];
}
 
void _Error(char* message, int line, char* file)
{
    printf("Error at line %d in file %s: ", line, file);
    printf("%s", message);
    exit(1);
}



 