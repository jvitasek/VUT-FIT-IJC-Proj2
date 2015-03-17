// wordcount.c
// Implementation of the IJC - HW2, ex. b), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

void enum_value(const char* key, const int value)
{
    printf("%s\t%d\n", key, value);
}

int main() {
    //int i;
    char buffer[1001];
    char word[1001];
    int htab_size = 30;
    int bufferlen = 0;
    htab_t* map = htab_init(htab_size);

    do
    {        
        fgets(buffer, 1001, stdin);
       
        bufferlen = strlen(buffer);
        if (bufferlen>0)
        {
            if (buffer[bufferlen-1]=='\n')                
                buffer[bufferlen-1] = 0;

            bufferlen = strlen(buffer);
        }

        if (bufferlen>0)
        {
            int pos = 0;
            word[0] = 0;
            while(pos<bufferlen && sscanf(&buffer[pos], "%s", word))
            {          
                int len = strlen(word);
                if (len>0)
                {                    
                    struct htab_listitem* item = htab_add(map, word);
                    item->data++;                    
                    pos = pos + len + 1;
                } else {
                    break;
                }
            }
        }
    }while(bufferlen>0);
    
    htab_foreach(map, enum_value);
    printf("\n");
    htab_statistics(map);

    htab_free(map);
    return 0;
}