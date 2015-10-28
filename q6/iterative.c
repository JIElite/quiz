#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "iterative.h"



struct HeadTail {
    struct ListNode *head;
    struct ListNode *tail;
};


struct HeadTail* reverseList(struct ListNode *head)
{
    struct ListNode *current = head;
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;

    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    struct HeadTail *res = malloc(sizeof(struct HeadTail));
    res->head = prev;
    res->tail = head;
    return res;
}

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
    if (m == n) return head;

    struct ListNode *p = head;
    struct ListNode *start = NULL;
    struct ListNode *end = NULL;

    /* get start position, end position
     * The start position is m-1, end is n
     */
    if (m == 1) {
        start = head;
    }
    for (int i = 1; i <= n && p; i++) {
        if (i == m-1) {
            start = p;
        }
        if (i == n) {
            end = p;
        }

        p = p->next;
    }
    struct ListNode *after_end = end->next;
    /* let end->next = NULL so that we can reuse reverseList function*/
    end->next = NULL;

    /* reconnect linked list */
    struct HeadTail *res = NULL;
    if (m == 1) {
        res = reverseList(start);
        res->tail->next = after_end;
        head = res->head;
    } else {
        res = reverseList(start->next);
        start->next = res->head;
        res->tail->next = after_end;
    }

    /* release temp message created by reverseList() */
    if (res != NULL) free(res);

    return head;
}

