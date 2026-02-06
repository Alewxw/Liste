#include <stdio.h>
#include <stdlib.h>
#include "doublelink.h"
// Laborator I - Lista dublu inlantuita

int main()
{
    t_lista L; // declaram lista
    makenull(&L); // alocare de memorie

    printf("~MENIU~\n");
    printf("-------\n\n");

    int s = -1;
    while ( s )
    {
        printf("Ce operatie vrei sa faci asupra listei?\n 1: Inserare\n 2: Cautare element\n 3: Stergere element\n 4: Afisare lista\n 0: Inchidere program\n");
        scanf("%d", &s);

        switch (s)
        {
            case 1:
            {
                t_nod_lista *t = (t_nod_lista*)malloc(sizeof(t_nod_lista)); // alocare memorie nod
                if (t == NULL)
                {
                    printf("Eroare la alocarea memoriei!\n");
                    break;
                }

                int key;
                printf("Ce valoare vrei sa aiba nodul inserat?\n");
                scanf("%d", &key);

                t->val = key;
                t->prev = NULL;
                t->next = NULL;

                list_insert(&L, t);


                break;
            }

            case 2:
            {
                int key;
                printf("Ce element vrei sa cauti in lista?\n");

                scanf("%d", &key);

                t_nod_lista *t = list_search(L, key);

                if ( NULL == t ) printf("Elementul nu a fost gasit\n");
                else printf("Gasit\n");


                break;
            }
            case 3:
            {
                printf("Ce element vrei sa stergi din lista?\n");
                int key;
                scanf("%d", &key);

                t_nod_lista *t = list_search(L, key);

                if ( NULL == t ) printf("Elementul nu a fost gasit, deci nu poate fi sters\n");
                else {
                    list_delete(&L, t);
                    printf("Elementul a fost gasit si sters\n");
                }


                break;
            }
            case 4:
            {
                list_print(L);
                printf("\n");

                break;
            }

            default:
                if ( s > 4 ) printf("Operatie inexistenta\n");


            }
    }



    return 0;
}
