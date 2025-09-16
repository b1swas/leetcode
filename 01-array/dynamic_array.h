#ifndef DYNARR_H
#define DYNARR_H

typedef struct {
    int capacity;
    int length;
    int *arr;
} DynArr;

DynArr* da_initialize(int capacity);
void da_push(DynArr *da, int n);
void da_pop(DynArr *da);
int da_get(DynArr *da, int i);
void da_insert(DynArr *da, int i, int n);
void da_print(DynArr *da);

#endif
