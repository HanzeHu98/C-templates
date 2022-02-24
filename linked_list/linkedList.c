#include "linkedList.h"

linked_list_t* list_create(){
  linked_list_t *list = malloc(sizeof(linked_list_t));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

LLNode* node_create(int from, int dest){
  LLNode *node = malloc(sizeof(LLNode));
  node->from_node = from;
  node->dest_node = dest;
  return node;
}

void list_append(linked_list_t *list, LLNode *node){
  if(list->size == 0){
    list->tail = node;
    list->head = node;
    node->next = NULL;
    list->size += 1;
  } else{
    list->tail->next = node;
    node->prev = list->tail;
    node->next = NULL;
    list->tail = node;
    list->size += 1;
  }
}

void list_delete(linked_list_t *list, LLNode *node){
  if(node->next == NULL && node->prev == NULL){
    list->head = NULL;
    list->tail = NULL;
    list->size --;
    free(node);
  }
  else if (node->next == NULL){
    list->tail = node->prev;
    node->prev->next = NULL;
    list->size --;
    free(node);
  }
  else if (node->prev == NULL){
    list->head = node->prev;
    node->next->prev == NULL;
    list->size --;
    free(node);
  }
  else{
    node->next->prev == node->prev;
    node->prev->next == node->next;
    list->size --;
    free(node);
  }
}

void print_list(linked_list_t* lList){
  LLNode* nextNode = lList->head;
  while (nextNode != NULL){
    printf("An edge going from Node: %d to Node: %d\n", nextNode->from_node, nextNode->dest_node);
    nextNode = nextNode->next;
  }
}

void free_list(linked_list_t* lList){
  LLNode* currNode, *nextNode;
  currNode = lList->head;
  while (currNode != NULL){
    nextNode = currNode->next;
    free(currNode);
    currNode = nextNode;
  }
  free(lList);
}


// Main Loop Used for debugging purposes, reading from a small graph0
void main(){
  int numEdges, from, dest;
  LLNode *node;
  linked_list_t* graph;
  FILE *file = fopen("graph0.txt", "r");
  fscanf(file, "%d", &numEdges);
  graph = list_create();
  for(int i = 0; i < numEdges; i++){
    fscanf(file, "%d", &from);
    fscanf(file, "%d", &dest);
    node = node_create(from, dest);
    list_append(graph, node);
  }
  fclose(file);
  print_list(graph);
  free_list(graph);
  return;
}