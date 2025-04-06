#include <stdio.h>
#include "doubly-linked-list.h"

int main() {
    DLinkedList* dlist = init_list();
    if(!dlist) {
        perror("Cannot create list.");
        return 1;
    }

    // Adiciona um inteiro ao início da lista duplamente ligada
    push_int(dlist, 70);
    
    // Adiciona uma cadeira de caracteres ao início da lista duplamente ligada
    push_string(dlist, "Brian Santos");
    
    // Adiciona um inteiro ao final da lista duplamente ligada
    push_end_int(dlist, 123);
    
    // Adiciona um número de ponto flutuante ao início da lista duplamente ligada
    push_float(dlist, 12.5);
    
    // Adiciona um valor booleano ao início da lista duplamente ligada
    push_bool(dlist, true);

    push_end_bool(dlist, false);

    push_end_char(dlist, 'c');
    
    // Imprime a lista ligada partindo do começo
    from_start(dlist);

    // Libera a memória usada pela lista
    free_list(dlist);

    // Tenta imprimir a lista após liberá-la
    from_start(dlist);

    return 0;
}