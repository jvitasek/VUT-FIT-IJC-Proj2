// htab_init.c
// Implementation of the IJC - HW2, ex. b), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

htab_t* htab_init(int htab_size){

    htab_t* result = 0;

	if (htab_size > 0)
	{
		result = (htab_t*)malloc(sizeof(htab_t));

		if (result)
		{
			int i;
			
			result->htab_size = htab_size;
			result->buckets = 
				(struct htab_listitem**)malloc(sizeof(struct htab_listitem*) * htab_size);
			
			if (result->buckets)
			{
				for(i = 0; i < htab_size; i++)
					result->buckets[i] = 0;

				return result;
			} 
			else 
			{				
				free(result);
				result = 0;
			}			
		}
	}

	return 0;
}