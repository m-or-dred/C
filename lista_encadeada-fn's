#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_t {
 char name[32], address[28];
 float height;
} data_t;

typedef struct node_t {
 data_t data;
 struct node_t *next;
 struct node_t *prev;
} node_t;

typedef struct list_t {
 node_t *head, *last;
} list_t;

unsigned length(list_t *list) {
 unsigned len = 0;
 node_t *curr = list -> head;
 while (curr)
  curr = curr -> next, ++len;
 return len;
}

void show_list(list_t *list) {
// if (list -> head) {
  node_t *curr = list -> head;
//  printf("[");
  while (curr)
    printf("\nname: %s\naddres: %s\nheight: %.2f\n", curr -> data.name, curr -> data.address, curr -> data.height),
    curr = curr -> next;
//  printf("\b]\n");
// }
// else
//  printf("[]\n");
}

void free_list(list_t *list) {
    node_t *node = list -> head;
    while (node)
        list -> head = node -> next,
        free(node),
        node = list -> head;
}

void prepend(data_t data, list_t *list) {
    node_t *node = malloc(sizeof(node_t));
    node -> data = data;
    node -> next = list -> head;
    list -> head = node;
}

void append(data_t data, list_t *list) {
 if (list -> head) {
  node_t *node = list -> head;
  while (node -> next)
   node = node -> next;
  node -> next = (node_t *) malloc(sizeof(node_t)),
  node -> next -> data = data,
  node -> next -> next = NULL;
 }
 else
  list -> head = (node_t *) malloc(sizeof(node_t)),
  list -> head -> data = data,
  list -> head -> next = NULL;
}

void insert(int index, data_t data, list_t *list) {
 if (0 <= index && index <= length(list)) {
  node_t *new_node = (node_t *) malloc(sizeof(node_t));
  if (index) {
   node_t *curr_node = list -> head;
   int next_index = 1;
   while (next_index < index)
    curr_node = curr_node -> next, ++next_index;
   new_node -> data = data,
   new_node -> next = curr_node -> next,
   curr_node -> next = new_node;
  }
  else // prepend
   new_node -> data = data,
   new_node -> next = list -> head,
   list -> head = new_node;
 }
 else printf("(index out of range)\n");
}

void invert(list_t *list, list_t *aux) {
 node_t *curr = list -> head;
 while (curr)
  prepend(curr -> data, aux),
  curr = curr -> next;
}

data_t pop_head(list_t *list) {
    data_t result;
    if (list -> head) {
        node_t *temp_node = list -> head;
        result = temp_node -> data;
        list -> head = temp_node -> next;
        free(temp_node);
    }
    else
        strcpy(result.name, "");
    return result;
}

void invert_without_aux(list_t *list) {
 unsigned i, len = length(list);
 for (i = 0; i < len; ++i)
  append(pop_head(list), list);
}

data_t pop_last(list_t *list) {
 data_t data;   strcpy(data.name, "");
 strcpy(data.name, "");
 if (list -> head -> next) {
  node_t *curr = list -> head;
  while (curr -> next -> next)
   curr = curr -> next;
  data = curr -> next -> data,
  free(curr -> next),
  curr -> next = NULL;
 }
 else if (list -> head)
  data = list -> head -> data,
  free(list -> head),
  list -> head = NULL;
// else
//  strcpy(data.name, "");
 return data;
}

data_t del(int index, list_t *list) {
 data_t data;
 unsigned len = length(list);
 if (0 <= index && index < len) {

  if (index && index < len) {
   node_t *curr_node = list -> head;
   unsigned next_index = 1;

   while (next_index < index)
    curr_node = curr_node -> next, ++next_index;

   data = curr_node -> next -> data;
   node_t *temp_node = curr_node -> next;
   curr_node -> next = temp_node -> next;
   free(temp_node);
  }

  else if (index)
   return pop_last(list);

  else
   return pop_head(list);

 }
 else
  strcpy(data.name, "");

 return data;
}

data_t get(char *key, list_t *list) {
 data_t data;
 if (!list -> head) { strcpy(data.name, ""); return data; }

 if (!strcmp(key, list -> head -> data.name)) { return pop_head(list); }

 if (list -> head -> next) {
  node_t *curr = list -> head;

  while (curr -> next && strcmp(key, curr -> next -> data.name))
   curr = curr -> next;

  if (!strcmp(key, curr -> next -> data.name)) {
   data = curr -> next -> data;

   if (curr -> next -> next) {
    node_t *temp_node = curr -> next;
    curr -> next = temp_node -> next;
    free(temp_node);
   }
   else { free(curr -> next), curr -> next = NULL; }

   return data;
  }
  else { strcpy(data.name, ""); return data; }
 }
 else { strcpy(data.name, ""); return data; }
}

//int funcao()

//int main() {
//    list_t list; list.head = NULL; data_t data;
//    strcpy(data.name, "a"); strcpy(data.address, "e"); data.height = 1.5; append(data, &list);
//    strcpy(data.name, "b"); strcpy(data.address, "ee"); data.height = 1.6; append(data, &list);
//    strcpy(data.name, "c"); strcpy(data.address, "eee"); data.height = 1.7; append(data, &list);
//    strcpy(data.name, "d"); strcpy(data.address, "eeee"); data.height = 1.8; append(data, &list);
//    show_list(&list);
//    data_t arr[][4] = {{"d", "eeee", 1.8}, {"c", "eee", 1.7}, {"b", "ee", 1.6}, {"a", "e", 1.5}};
// invert_without_aux(&list);
// free_list(&list);       show_list(&list);
// get("mady", &list);     show_list(&list);
// del(2, &list);          show_list(&list);
// pop_last(&list);        show_list(&list);
// pop_head(&list);        show_list(&list);
//}
