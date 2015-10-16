#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void traverse_list(struct ListNode *head)
{
    while(head) {
        printf("%d\n", head->val);
        head = head -> next;
    }
    return;
}


struct ListNode* create_node(int val)
{
    struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node -> val = val;
    new_node -> next = NULL;
    return new_node;
}


struct ListNode *create_cycle_list(int cycle_pos, int size)
{
    struct ListNode *list_head = create_node(0);
    struct ListNode* parse = list_head;

    if (cycle_pos > size) return NULL;

    for (int i = 1; i <= size; i++) {
        if (i == cycle_pos) list_head = parse;
        parse -> next = create_node(i);
        parse = parse -> next;
    }
    parse->next = list_head->next;

    return list_head;
}


struct ListNode *create_linear_list(int size)
{
    struct ListNode *list_head = create_node(0);
    struct ListNode *parse = list_head;

    for(int i = 1; i <= size; i++) {
        parse->next = create_node(i);
        parse = parse->next;
    }
    return list_head;
}



