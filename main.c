#include "stdio.h"
#include "stdlib.h"

typedef struct node {
    int val;
    struct node * next;
    struct node* prev;
} node_t;

typedef struct list {
    node_t* head;
    node_t* tail;
} list_t;

list_t new_list() {
    list_t res;
    res.head = 0;
    res.tail = 0;
    return res;
}

void pb(list_t* list_a, list_t* list_b) {
    if (!list_a->head) {
        return;
    }

    node_t* node = list_a->head;
    if (list_a->head == list_a->tail) [
        list_a->head = 0;
        list_a->tail = 0;
    ] else {
        list_a->head = node->next;
    }

    if (list_b->head == 0) {
        list_b->head = node;
        list_b->tail = node;
        node->head = 0;
        node->tail = 0;
    } else {
        list_b->head->prev = node;
        node->next = list_b->head;
        list_b->head = node;
    }
}

node_t* new_node(int value) {
    node_t* head = (node_t *) malloc(sizeof(node_t));
    if (!head) return 0;
    head->val = value;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

void add_node_back(list_t* )

int main() {
    int numbers[] = {1,2,3,4,5,6};
    node_t * head = new_node(numbers[0]);
    node_t * tail = head;

    int i = 1;
    while (i < 6)
    {
        node_t * nod = new_node(numbers[i]);
        nod->prev = tail;
        tail->next = nod;
        tail = nod;

        i++;
    }

    // move tail to beginning
    node_t* node = tail;
    tail = tail->prev;
    node->prev = 0;
    node->next = head;
    head = node;

    node_t* head_b = 0;
    node_t* tail_b = 0;

    head_b = node;
    tail_b = node;
    node->next = 0;
    node->prev = 0;
    
    node_t* ptr = tail;
    while(ptr) {
        printf("%d\n",ptr->val);
        ptr = ptr->prev;
    }


    return 0;
}