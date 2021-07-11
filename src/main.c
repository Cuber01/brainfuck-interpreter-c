#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "main.h"
#include "stack.h"

uint8_t input_buffer[FILESIZE_LIMIT]; //expression must be an integral constant expressio
uint8_t memory[CELL_LIMIT];
uint8_t pointer;

#define END_PROGRAM 0xFF

void fileLoad()
{

    char ch;
    int i = 0;


    FILE *fp;
    fp = fopen(FILENAME, "r");

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        input_buffer[i] = ch;
        i++;
    }

    input_buffer[i] = END_PROGRAM;

    fclose(fp);
}


void Interpret()
{
    uint8_t tmp_i=0;
    int i = 0;
    uint32_t counter=0;
    printf("-- START -- \r\n");

    while( i <= FILESIZE_LIMIT )
    {        
        uint8_t c = input_buffer[i];
        //printf( "%08X %06d: %c %d %02X\r", counter++, i, c, pointer, memory[pointer]  );  fflush(stdout);        
        if( c == END_PROGRAM ) break;
        
        switch (c) {
            
            case '+': memory[pointer]++; i++;        break;
            case '-': memory[pointer]--; i++;        break;
            
            case '>': pointer++;         i++;        break;
            case '<': pointer--;         i++;        break;
            
            case '.': printf("%c", memory[pointer]); i++; break;
            
            case '[': 
                push(i);
                if (memory[pointer] == 0)
                {                    
                    for (int j = i+1; j <= FILESIZE_LIMIT; j++)
                    {
                        if (input_buffer[j] == '['){
                            push(j);                                                    
                        }
                        if (input_buffer[j] == ']') 
                        {
                            tmp_i = pop();
                            if( isEmpty() ){
                                push(tmp_i);                                
                                i = j;
                            }
                            break;
                        }
                    }
                }else{
                    i++;
                }
                break;

            case ']':
                tmp_i = pop();
                if (memory[pointer] != 0)
                {
                    i = tmp_i;
                    break;
                } else{
                    i++;
                } 
                break;
            default: 
                printf("\r\nERROR!\r\n");
                exit(1);
                break;
        }

    }

    printf("\n -- END -- \r\n");
}

int main()
{
    fileLoad();

    Interpret();

   
    return 0;
}

