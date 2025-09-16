#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capacity;
    int length;
    int *arr;
} Stack;

Stack* st_init(int capacity) {
    int* arr = malloc(capacity*sizeof(int));
    Stack* st = malloc(sizeof(Stack));

    st->capacity = capacity;
    st->length = 0;
    st->arr = arr;

    return st;
}

void st_resize(Stack* st) {
    int new_capacity = 2*st->capacity;
    st->capacity = new_capacity;
    int* new_arr = realloc(st->arr, new_capacity*sizeof(int));
    st->arr = new_arr;
}

void st_push(Stack* st, int n) {
    if (st->length == st->capacity) {
        st_resize(st);
    }

    st->arr[st->length++] = n;
}

int st_pop(Stack* st) {
    int res = st->arr[st->length--];
    return res;
}

int st_peek(Stack* st) {
    return st->arr[st->length - 1];
}

void st_print(Stack* st) {
    for (int i=0; i < st->capacity; i++) {
        if (i < st->length) {
            printf("%d", st->arr[i]);
        } else {
            printf("_");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Stack* st = st_init(2);

    st_push(st, 1);
    st_push(st, 2);
    st_print(st);

    st_push(st, 3);
    st_print(st);

    st_pop(st);
    st_print(st);

    printf("Top: %d", st_peek(st));
}
