// htab_lookup.c
// Implementation of the IJC - HW2, ex. b), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

extern unsigned int hash_function(const char *str, unsigned htab_size);

struct htab_listitem * htab_lookup(htab_t *t, const char *key)
{
    if (t && key)
	{
		struct htab_listitem * bucket;		
		unsigned int listIndex;
						
        listIndex = hash_function(key, t->htab_size);
		bucket = t->buckets[listIndex];

		while(bucket)
		{							
            bucket = bucket->next;			
		}		
	}

    return 0;
}