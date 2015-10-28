#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "recursive.h"


static struct ListNode *reverse(struct ListNode *start, struct ListNode *current,
                         struct ListNode *next, int remain_times, int ishead)
{

    if (remain_times && next) {
        struct ListNode *next2 = next->next;
        next->next = current;
        return reverse(start, next, next2, remain_times-1, ishead);
    } else {
        if (ishead) {
            start->next = next;
            return current;
        } else {
            start->next->next = next;
            start->next = current;
            return start;
        }
    }


}

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
    if (m == n) return head;

    struct ListNode *entry = head;
    for ( int i = 1; i < m-1; i++) {
        entry = entry->next;
    }
    if (m == 1) {
        head = reverse(entry, entry, entry->next, n-m, 1);
    } else {
        reverse(entry, entry->next, entry->next->next, n-m, 0);
    }

    return head;
}

