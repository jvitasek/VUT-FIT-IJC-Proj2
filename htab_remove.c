// htab_remove.c
// Implementation of the IJC - HW2, ex. b), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

extern unsigned int hash_function(const char *str, unsigned htab_size);

void htab_remove(htab_t * t, const char *key)
{
    if (t && key)
	{
		struct htab_listitem * bucket;
		struct htab_listitem * previous_bucket=NULL;
		unsigned int listIndex;
						
        listIndex = hash_function(key, t->htab_size);
		bucket = t->buckets[listIndex];

		while(bucket)
		{
			if (strcmp(bucket->key, key)!=0)
			{
				previous_bucket = bucket;
				bucket = bucket->next;
			} else {
				if (bucket == t->buckets[listIndex])
				{
					t->buckets[listIndex] = bucket->next;
				} else {
					previous_bucket->next = bucket->next;
				}

				free(bucket->key);				
				free(bucket);							
			}
		}		
	}	
}
