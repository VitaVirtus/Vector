#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	int* vec;
	int size;
	int cap;
} Vector;

int at(const Vector* vector, int pos) {
    return vector->vec[pos];
}

void initializeVector(Vector* vector, int initialCapacity){
	vector->vec = (int*)malloc(initialCapacity * sizeof(int));
	if (vector->vec == NULL) {
		return;
	}
	vector->size = 0;
	vector->cap = initialCapacity;
}

bool empty(const Vector* vector) {
    return vector->size == 0;
}

void push_back(Vector* vector, int value) {
    (vector->size == vector->cap) ? vector->cap *= 2 : 0;
    vector->vec = (int*)realloc(vector->vec, vector->cap * sizeof(int));
    if (vector->vec == NULL) {
        return;
    } 
    vector->vec[vector->size++] = value;
}

void pop_back(Vector* vector) {
    (vector->size > 0) ? (vector->size--, vector->vec[vector->size] = 0) : 0;
}

int front(const Vector* vector) {
    return (vector->size > 0) ? vector->vec[0] : -1;
}

int back(const Vector* vector) {
    return (vector->size > 0) ? vector->vec[vector->size - 1] : -1;
}

int size(const Vector* vector) {
    return (vector->size > 0) ? vector->size + 1 : 0;
}

int capacity(const Vector* vector) {
    return vector->cap;
}

void insert(Vector* vector, int pos, int value) {
    if (pos >= 0 && pos <= vector->size) {
        if (vector->size == vector->cap) {
            vector->cap *= 2;
            vector->vec = (int*)realloc(vector->vec, vector->cap * sizeof(int));
            if (vector->vec == NULL) {
                return;
            }
        }

        for (int i = vector->size; i > pos; --i) {
            vector->vec[i] = vector->vec[i-1];
        }
        vector->vec[pos] = value;
    } else {
        return;
    }
}

void erase(Vector* vector, int pos) {
    if (pos >= 0 && pos < vector->size) {
        for (int i = pos; i < vector->size - 1; ++i) {
            vector->vec[i] = vector->vec[i + 1];
        }
        --vector->size;
    }
}

void clear(Vector* vector) {
    for (int i = 0; i < vector->size; ++i) {
        vector->vec[i] = 0;
    }
    vector->size = 0;
}

void shrink_to_fit(Vector* vector) {
    if (vector->size == vector->cap) {
        return;
    }
    for (int i = vector->size; i < vector->cap; ++i) {
        vector->vec[i] = 0;
    }

    vector->cap = vector->size;
    vector->vec = (int*)realloc(vector->vec, vector->cap * sizeof(int));
    if (vector->vec == NULL) {
        return;
    }
}

void destroyVector(Vector* vector) {
    for (int i = 0; i < vector->size; ++i) {
        vector->vec[i] = 0;
    }
    vector->size = 0;
    vector->cap = vector->size;
    vector->vec = (int*)realloc(vector->vec, vector->cap * sizeof(int));
    free(vector->vec);
    vector->vec == NULL;

    free(vector);
    vector == NULL;
}
