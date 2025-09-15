#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capacity;
    int length;
    int *arr;
} DynArr;

DynArr* da_initialize(int capacity) {
    DynArr* da = malloc(sizeof(DynArr));
    int *arr = malloc(capacity*sizeof(int));

    da->capacity = capacity;
    da->length = 0;
    da->arr = arr;

    return da;
}

void da_resize(DynArr **da_ptr) {
    DynArr *da = *da_ptr;
    da->capacity *= 2;
    int *new_da = (int *)realloc(da->arr, da->capacity*sizeof(int));
    da->arr = new_da;
}

void da_push(DynArr *da, int n) {
    if (da->length == da->capacity) {
        da_resize(&da);
    }
    da->arr[da->length++] = n;
}

void da_pop(DynArr *da) {
    if (da->length > 0) {
        da->length--;
    }
}

int da_get(DynArr *da, int i) {
    if (i < da->length) {
        return da->arr[i];
    } else {
        printf("da_get error: Out of bound index\n");
        return -1;
    }
}

void da_insert(DynArr *da, int i, int n) {
    if (i < da->length) {
        da->arr[i] = n;
        return;
    } else {
        printf("da_insert error: Out of bound index\n");
    }
}

void da_print(DynArr *da) {
    for (int i = 0; i < da->capacity; i++) {
        if (i < da->length) {
            printf("%d", da->arr[i]);
        } else {
            printf("-");
        }
    }
    printf("\n");
}


int main (int argc, char *argv[]) {
    DynArr *da = da_initialize(2);
    da_print(da);

    da_push(da, 1);
    da_print(da);

    da_push(da, 2);
    da_print(da);

    da_push(da, 4);
    da_print(da);

    da_insert(da, 2, 3); 
    da_print(da);

    printf("Element #%d = %d\n", 1, da_get(da, 1));

    da_pop(da);
    da_print(da);

    da_insert(da, 2, 3);  // out of bound
    da_get(da, 2); // out of bound
    da_print(da);


    free(da->arr);
    free(da);
}
