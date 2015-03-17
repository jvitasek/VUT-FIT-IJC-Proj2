// map.h
// Implementation of the IJC - HW2, ex. b), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#ifndef __MAP__H__
#define __MAP__H__

struct htab_listitem {
   char *key;
   int data;
   struct htab_listitem *next;
};

typedef struct {   
   int htab_size;
   struct htab_listitem **buckets;
} htab_t;


htab_t* htab_init(int htab_size);
struct htab_listitem * htab_lookup(htab_t *t, const char *key);
void htab_foreach(htab_t * t, void (*enum_value)(const char* key, const int value));
void htab_remove(htab_t * t, const char *key);
void htab_clear(htab_t * t);
void htab_free(htab_t * t);
struct htab_listitem * htab_add(htab_t * t, const char *key);
void htab_statistics(htab_t * t);

#endif