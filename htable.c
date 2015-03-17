#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

extern unsigned int hash_function(const char *str, unsigned htab_size);

struct htab_listitem * htab_add(htab_t * t, const char *key)
{
	if (t && key)
	{
		struct htab_listitem* bucket;
		unsigned int listIndex;
				
        listIndex = hash_function(key, t->htab_size);
		bucket = t->buckets[listIndex];

		while(bucket)
		{
			if (strcmp(bucket->key, key)!=0)
				bucket = bucket->next;
            else
                break;
		}

		if (bucket)
		{			
            //bucket->data++;
            return bucket; 
		} else {
			bucket = (struct htab_listitem *)malloc(sizeof(struct  htab_listitem));
            memset(bucket, 0, sizeof(struct htab_listitem));

			if (bucket)
			{
				int key_len = strlen(key);
				bucket->key = (char*)malloc(key_len+1);

				if (bucket->key)
				{
					strcpy(bucket->key, key);                    
					bucket->next =  t->buckets[listIndex];
					t->buckets[listIndex] = bucket;		
                    return bucket;
				} else {
					free(bucket);					
				}
			}
		}
	}	

    return 0;
}