// io.c
// Implementation of the IJC - HW2, ex. b), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#include <stdio.h>
#include <ctype.h>

int fgetw(char *s, int max, FILE *f)
{
    int len = 0;
    int c = 0;

    s[len] = 0;

    if (!feof(f))
    {
        while(isspace(fgetc(f)) && !feof(f))
        {
        }

        do{
            c = fgetc(f);
            s[len] = c;
            len++;
            s[len] = 0;
        }
        while(!isspace(c) && !feof(f) && len<max);
    }

    if (!feof(f))
        return len;        
    else
        return EOF;
}