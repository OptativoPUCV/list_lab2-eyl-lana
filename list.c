#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {

  List *list = (List *) malloc (sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->current = NULL;
  return list;

  free(list);
}

void * firstList(List * list) {

  if (list->head != NULL){
    list->current = list->head;
  }
  else return NULL;
  
  return (void *) list->head->data;

}

void * nextList(List * list) {

  if (list->current && list->current->next != NULL){
    list->current = list->current->next;
  }
  else return NULL;

  return (void *) list->current->data;
}

void * lastList(List * list) {

  if (list->tail != NULL){
    list->current = list->tail;
  }
  else return NULL;

  return (void *) list->current->data;

}

void * prevList(List * list) {

  if (list->current && list->current->prev != NULL){
    list->current = list->current->prev;
  }
  else return NULL;

  return (void *) list->current->data;

}

void pushFront(List * list, const void * data) {
  
  Node *nodo = createNode(data);
  nodo->next = list->head;

  if (list->head == NULL){
    createList();
    list->tail = nodo;
  }

  if (list->head != NULL){
    list->head->prev = nodo;
  }
  list->head = nodo;
  nodo->prev = NULL;
  free(nodo);

}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
  
  /*if (list->current != NULL){
    list->current->next = (void *) data;
  }
  else{
    list->current = (void *) data;
  }*/

}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {

  //Node *nodo = list->current;
  //Node *aux = list->current;
  if (list->current != NULL){
    list->current->prev = list->current->next;
  }
  else{
    list->head = NULL;
  }

  if (list->current->next != NULL){
    list->current->next = list->current->prev;
  }

  return (void *) list->current->data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}