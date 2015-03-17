// hash_function.c
// Implementation of the IJC - HW2, ex. b), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

unsigned int hash_function(const char *str, unsigned htab_size) {

    unsigned int h=0;
    const unsigned char *p;

    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;

   return h % htab_size;
}