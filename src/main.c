#include <stdio.h>
#include "doubly-linked-list.h"

int main() {
    DLinkedList* dlist = init_list();
    if( !dlist) {
        perror("Cannot create list.");
        return 1;
    }

    push_int(dlist, 70);
    push_string(dlist, "Brian Santos");
    push_int(dlist, 123);
    push_float(dlist, 12.5);
    push_bool(dlist, true);

    from_start(dlist);

    return 0;
}