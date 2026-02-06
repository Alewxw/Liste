#include <stdlib.h>
#include <stdio.h>
#include "doublelink.h"

void makenull ( t_lista *l )
{
    l->head = (t_nod_lista*)malloc(sizeof(t_nod_lista));

    if ( NULL == l->head )
    {
        printf("Eroare memorie");
        return ;
    }

    l->head->next = NULL;
    l->head->prev = NULL;
}

t_nod_lista* list_search ( t_lista l, int elem )
{
    t_nod_lista *curr = l.head;

    while ( NULL != curr && curr->val != elem ) // cat timp nu s-a finalizat lista si suntem pe un nod cu valoarea diferita de valoarea cautata
        curr = curr->next;

    return curr;
}

void list_insert ( t_lista *L, t_nod_lista* x)
{
    if ( NULL == x ) return;

    x->next = L->head->next;
    if ( NULL != L->head->next)  L->head->next->prev = x; // daca mai exista ceva dupa nodul nostru head care este santinela

    L->head->next = x;
    x->prev = L->head;
}

void list_delete ( t_lista* l, t_nod_lista* nod )
{
    if ( NULL == nod || NULL == l ) return;

    nod->prev->next = nod->next;  // B <-> A <-> C ; vreau sa-l sterg pe A, anteriorul lui A este B si vreau ca urmatorul sa devina C, si apoi daca exista ceva dupa A, anteriorul sau devine anteriorul nodului sters

    if ( NULL != nod->next ) nod->next->prev = nod->prev;

    free(nod);
}

void list_print ( t_lista l )
{
    t_nod_lista *curr = l.head->next;

    while ( NULL != curr )
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
}

void list_free ( t_lista *l )
{
    if ( NULL == l || NULL == l->head ) return ;

    t_nod_lista* curr = l->head->next;

    while ( NULL != curr )
    {
        t_nod_lista *next = curr->next;
        free(curr);

        curr = next;
    }

    free(l->head);
    l->head = NULL;
}
