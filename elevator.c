#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "elevator.h"



Elevator *create_elevator(int capacity, int currentFloor, PersonList
*persons){
    Elevator *e=(Elevator*)malloc(sizeof(Elevator));
    e->capacity=capacity;
    e->currentFloor=currentFloor;
    e->persons=persons;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList
**waitingLists){
    Building *b=(Building *)malloc(sizeof(Building));
    b->nbFloor=nbFloor;
    b->elevator=elevator;
    b->waitingLists=waitingLists;
}

PersonList* exitElevator(Elevator *e){
    PersonList *stay_list=NULL;
    PersonList *exit_list=NULL;
    while(e->persons!=NULL){
        Person *p=e->persons->person;
        if(p->dest==e->currentFloor){
            exit_list=insert(p,exit_list);
            e->persons=e->persons->next;
        }else{
            stay_list=append(p,stay_list);
            e->persons=e->persons->next;
        }
    }
    e->persons=stay_list;
    //return exit_list
}

int Counter(PersonList *list){
    int counter=0;
    while(list->person!=NULL){
        counter++;
        list=list->next;
    }
    return counter;
}

PersonList* enterElevator(Elevator *e, PersonList *waitingList){
    PersonList *wlist=waitingList;
    while(Counter(e->persons)<e->capacity){
        e->persons=append(wlist->person,e->persons);
        wlist=wlist->next;
    }
    waitingList=wlist;
    return waitingList;
}

void stepElevator(Building *b){
    if(b->elevator->targetFloor==b->elevator->currentFloor){
        exitElevator(b->elevator);
        *b->waitingLists=enterElevator(b->elevator,*b->waitingLists);
    }else {
        if(b->elevator->targetFloor>b->elevator->currentFloor){
            b->elevator->currentFloor=b->elevator->currentFloor+1;
            exitElevator(b->elevator);
            *b->waitingLists=enterElevator(b->elevator,*b->waitingLists);
        }
        if(b->elevator->targetFloor<b->elevator->currentFloor){
            b->elevator->currentFloor=b->elevator->currentFloor-1;
            exitElevator(b->elevator);
            *b->waitingLists=enterElevator(b->elevator,*b->waitingLists);
        }

        }

}
