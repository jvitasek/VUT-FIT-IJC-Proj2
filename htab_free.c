// htab_free.c
// Implementation of the IJC - HW2, ex. b), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

void htab_free(htab_t * t)
{
	if (t)
	{
		htab_clear(t);
		free(t->buckets);
		free(t);
	}	
}
