// fold.c
// Implementation of the IJC - HW2, ex. a), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i;
    int c = 0; 
    int w = 80;
    char filename[1001] = {0};
    FILE* file;
    
    for(i=1; i<argc; i++)
    {
        if (!strcmp(argv[i], "-c"))
            c = 1;
        else if (!strcmp(argv[i], "-w"))
        {
            if (i<argc-1)
            {
                i++;
                w = atoi(argv[i]);
            }
        } else {
            if (filename[0]==0)
                strcpy(filename, argv[i]);
        }
    }

    if (filename[0])
        file = fopen(filename, "r");
    else
        file = stdin;

    if (file)
    {
        char* currentWord = 0;
        int accumulatedLength = 0;
        int printedLength = 0;
        int row = 0;

        while(!feof(file))
        {    
            char c1 = (char)fgetc(file);
            if (!feof(file))
            {
                if (c1!='\n' && c1!=' ' && c1!='\t')
                {                    
                    if (currentWord)
                    {
                        char* updatedWord = (char*)malloc(accumulatedLength+1);
                        memcpy(updatedWord, currentWord, accumulatedLength);
                        free(currentWord);
                        currentWord = updatedWord;                        
                    } else {
                        currentWord = (char*)malloc(1);
                    }
                    currentWord[accumulatedLength] = c1;
                    accumulatedLength++;
                } else {
                    if (c1=='\n' && accumulatedLength==0)
                    {
                        row++;
                        if (printedLength>0)
                            fputc('\n', stdout);
                        fputc('\n', stdout);
                        printedLength = 0;
                    } else {
                        if (currentWord)
                        {
                            if (printedLength+accumulatedLength>=w)
                            {
                                if (c)
                                {
                                    if (w<accumulatedLength)
                                        accumulatedLength = w;
                                }

                                if (row>0 && printedLength>0)
                                    fputc('\n', stdout);
                                printedLength = 0;                                
                            }
                            else {
                                if (printedLength>0)
                                {
                                    fputc(' ', stdout);
                                    printedLength++;
                                }
                            }
                        
                            fwrite(currentWord, 1, accumulatedLength, stdout);
                            printedLength += accumulatedLength;
                            //fputc('\n', stdout);
                            free(currentWord);
                            row++;
                        } else {
                            /*if (c1==' ' || c1=='\t')
                            {
                                if (printedLength==w)
                                {
                                    fputc('\n', stdout);
                                    printedLength = 0;    
                                }
                                fputc(' ', stdout);
                                printedLength++;                                
                            }*/
                        }
                        currentWord = 0;
                        accumulatedLength = 0;
                        i=1;
                    }
                }
            }            
        }

        if (accumulatedLength>0)
        {
            if (printedLength+accumulatedLength>w)
            {
                if (row>0)
                    fputc('\n', stdout);
                printedLength = 0;
                row++;
            }
            fwrite(currentWord, 1, accumulatedLength, stdout);
        }

        if (filename[0])
        {
            fclose(file);            
        }
    }

    return 0;
}