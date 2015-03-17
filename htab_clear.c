// htab_clear.c
// Implementation of the IJC - HW2, ex. b), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

void htab_clear(htab_t * t)
{
	if (t)
	{
		int i;

		for(i = 0; i < t->htab_size; i++)
		{
			while(t->buckets[i])
			{
				struct htab_listitem* deleting;

				deleting = t->buckets[i];
				t->buckets[i] = t->buckets[i]->next;

				free(deleting->key);
				free(deleting);		
			}			
		}
	}	
}