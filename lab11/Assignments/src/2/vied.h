// vied.h
#ifndef VIED_H
#define VIED_H

#include <stdio.h>

struct fline {
    char* line_data;
    struct fline* next;
    struct fline* prev;
};

typedef struct fline FLine;

extern FLine* head;
extern FLine* tail;
extern FLine* current;

extern int modified;

#endif

