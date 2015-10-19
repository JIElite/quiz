#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct ListNode *create_node(int val)
{
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node -> val = val;
    new_node -> next = NULL;
    return new_node;
}

struct ListNode* append(struct ListNode *head, int val)
{
    if (head == NULL) return create_node(val);

    struct ListNode *p = head;
    while (p->next) p = p->next;
    p->next = create_node(val);

    return head;

}


void traverse(struct ListNode *head)
{
    struct ListNode *p = head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}


