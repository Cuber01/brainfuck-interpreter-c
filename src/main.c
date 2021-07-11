#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "main.h"
#include "stack.h"

char input[FILESIZE_LIMIT]; //expression must be an integral constant expressio
uint8_t memory[CELL_LIMIT];
uint8_t pointer;



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
        input[i] = ch;
        i++;
    }

    fclose(fp);
}

int main()
{
    fileLoad();

    for (int i = 0; i <= FILESIZE_LIMIT; i++)
    {
        char c = input[i];
        
        switch (c) {
            
            case '+': memory[pointer]++;             break;
            case '-': memory[pointer]--;             break;
            
            case '>': pointer++;                     break;
            case '<': pointer--;                     break;
            
            case '.': printf("%c", memory[pointer]); break;
            
            case '[': 
                if (memory[pointer] == 0)
                {
                    for (int j = i; j <= FILESIZE_LIMIT; j++)
                    {
                        if (input[j] == ']') 
                        {
                            i = j;
                            break;
                        }
                    }
                } break;

            case ']':
                if (memory[pointer] != 0)
                {
                    for (int j = i; j >= 0; j--)
                    {
                        if (input[j] == '[') 
                        {
                            i = j;
                            break;
                        }
                    }
                } 
            default: break;
        }
    }

    return 0;
}

