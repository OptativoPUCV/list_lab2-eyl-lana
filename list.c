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

  Node *nodo = list->current->next;
  if (nodo == NULL){
    list->current = nodo->prev;
  }
  else return NULL;
  nodo = list->current->next;
  return (void *) nodo->data;

  /*Node *nodo = list->head;
  while (nodo != NULL){
    nodo = nodo->next;
  }
  nodo->next = list->current->next;
  return (void *) nodo->data;*/

  /*Node *nodo;
  while (list->current != NULL){
    nodo = list->current->next;
    nodo->prev = list->current;
  }
  nodo->next = NULL;

  return (void *) nodo->data;*/
  free(nodo);
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