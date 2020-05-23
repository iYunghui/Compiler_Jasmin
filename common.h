#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* struct ... */
struct SymbolTable {
    int index_length;
    int index[50];
    char *name[50];
    char *type[50];
    int address[50];
    int lineno[50];
    char *element_type[50];
};

#endif /* COMMON_H */