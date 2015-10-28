#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct ListNode *create_node(int val)
{
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;
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

struct ListNode* create_list(int start, int end)
{
    struct ListNode *head = create_node(start);
    struct ListNode *p = head;
    
    for (int i = start+1; i <= end; i++){
        p->next = create_node(i);
        p = p->next;
    }
    
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

void free_list(struct ListNode *head)
{
    struct ListNode *current = head;
    struct ListNode *prev = NULL;

    while (current != NULL) {
        prev = current;
        current = current->next;
        free(prev);
    }

    return;
}

