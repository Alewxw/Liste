#ifndef _lista
#define _lista

typedef struct node{
    int val;
    struct node *prev, *next;
}t_nod_lista;

typedef struct{
    t_nod_lista *head;
}t_lista;

void makenull ( t_lista *l );

t_nod_lista* list_search ( t_lista l, int elem );

void list_insert ( t_lista *l, t_nod_lista *nod );

void list_delete ( t_lista *l, t_nod_lista *nod );

void list_print ( t_lista l );

void list_free ( t_lista *l );

#endif // _lista
