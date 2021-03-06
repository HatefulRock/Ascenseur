#include "person.h"
#include <stdio.h>
#include <stdlib.h>

Person* createPerson(int src, int dest){
    Person *p=(Person *)malloc(sizeof(Person));
    p->src=src;
    p->dest=dest;
}

PersonList* insert(Person *p, PersonList *list) {
    PersonList *s=(PersonList *)malloc(sizeof(PersonList));
    s->person=p;
    s->next=list;
}

PersonList* append(Person *p,PersonList *list){
    if(list==NULL){
        return insert(p,list)
    } else {
        return insert(list->person,append(p,list->next))
    }
}