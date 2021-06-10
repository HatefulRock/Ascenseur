#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "elevator.h"



Elevator *create_elevator(int capacity, int currentFloor, PersonList
*persons){
    Elevator *e=(Elevator*)malloc(sizeof(Elevator));
    e->capacity=capacity;
    e->currentFloor=currentFloor;
    e->targetFloor=0;
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
            e->persons=e->persons->next
        }
    }
    e->persons=stay_list
    return exit_list
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
    Person List *wlist=waitingList
    while(Counter(list)<e->capacity){
        e->person=append(wlist->person,e->person);
        wlist=wlist->next;
    }
    waitingList=wlist;
    return waitingList
}

void stepElevator(Building *b){
    
}
