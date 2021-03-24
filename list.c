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

  Node *nodo = list->head;
  if (nodo != NULL){
    list->current = nodo;
  }
  else return NULL;

  return (void *) nodo->data;
  free(nodo);

}

void * nextList(List * list) {

  Node *nodo = list->head;
  if (nodo->next != NULL){
    list->current = nodo->next;
    //return (void *) nodo->data;
  }
  return (void *) nodo->data;
  free(nodo);

  /*Node *nodo = list->current;
  while (nodo != NULL){
    nodo = nodo->next;
  }
  return (void *) nodo->data;

  free(nodo);*/
  //return NULL;
}

void * lastList(List * list) {
    return NULL;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, const void * data) {
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
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
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}