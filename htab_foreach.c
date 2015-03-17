// htab_foreach.c
// Implementation of the IJC - HW2, ex. b), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

void htab_foreach(htab_t * t, void (*enum_value)(const char* key, const int value))
{
    if (t)
	{
		int i;

		for(i = 0; i < t->htab_size; i++)
		{
            struct htab_listitem * bucket = t->buckets[i];
			while(bucket)
			{
                if (enum_value)
                    enum_value(bucket->key, bucket->data);
				bucket = bucket->next;				
			}			
		}
	}
}