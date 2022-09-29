#include <stdlib.h>
#include "list.h"

void list_init(List *list, void (*destroy)(void *data)){
    if(list == NULL) return;
    list->size = 0;
    list->head = list->tail = NULL;
    list->destroy = *destroy;
}

int list_ins_next(List *list, ListElmt *element, const void *data){
    ListElmt *nouvelle;
    nouvelle = (ListElmt*)malloc(sizeof(ListElmt));
    if(nouvelle == NULL){
        return -1;
    }
    nouvelle->data = (void*)data;
    if(element == NULL){
        nouvelle->next = list_head(list);
        list_head(list) = nouvelle;
        if(list_tail(list) == NULL){
            list_tail(list) = nouvelle;
        }
    }
    else{
        nouvelle->next = element->next;
        element->next = nouvelle;
        if(element == list_tail(list)){
            list_tail(list) = nouvelle;
        }
    }
    list_size(list)++;
    return 0;
}