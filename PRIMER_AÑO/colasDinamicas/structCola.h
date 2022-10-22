#ifndef STRUCT_COLA_H
#define STRUCT_COLA_H

/* Snippet base para nodos de colas dinamicas */
struct node
{
    int data; // dato
    struct node *link; // ptr al siguiente node
};

#endif