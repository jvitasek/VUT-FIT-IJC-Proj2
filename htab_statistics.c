// htab_statistics.c
// Implementation of the IJC - HW2, ex. b), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

void htab_statistics(htab_t * t)
{
    int i;
    int minListLen = -1;
    int maxListLen = -1;
    int averageListLen = 0;
    int listCount = 0;

    for(i=0; i<t->htab_size; i++)
    {
        if (t->buckets)
        {
            int listLen = 0;
            struct htab_listitem * bucket = t->buckets[i];
            if (bucket)
            {
                while(bucket)
                {
                    listLen++;
                    bucket = bucket->next;
                }
                if (minListLen==-1)
                    minListLen = listLen;
                if (maxListLen==-1)
                    maxListLen = listLen;
                if (maxListLen<listLen)
                    maxListLen = listLen;
                if (minListLen>listLen)
                    minListLen = listLen;
                averageListLen += listLen;
                listCount++;
            }
        }
    }

    if (listCount>0)
    {
        printf("Min List length: %d\n", minListLen);
        printf("Max List length: %d\n", maxListLen);
        printf("Average List length: %.2f\n", (double)averageListLen/(double)listCount);
    } else {
        printf("There is no list\n");
    }

}