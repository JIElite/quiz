#include <stdio.h>
#include <stdlib.h>

#include "list.h"


struct ListNode* detect_cycle_rec(struct ListNode *slow, struct ListNode *fast)
{
    if (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return fast;
        }
        return detect_cycle_rec(slow, fast);
    }

    return NULL;
}

struct ListNode* hasCycle(struct ListNode *head)
{
    return detect_cycle_rec(head, head);
}

void free_list(struct ListNode *head)
{
    struct ListNode *current = head;
    struct ListNode *prev = NULL;
    struct ListNode *cycleNode = NULL;

    if ((cycleNode = hasCycle(head)) != NULL) {
        cycleNode->next = NULL;
    }

    while (current) {
        prev = current;
        current = current->next;
        free(prev);
    }
}

int main()
{
    struct ListNode *cycle_list = create_cycle_list(1, 6);
    struct ListNode *linear_list = create_linear_list(5);

    /* traverse list */
    //traverse_list(cycle_list);
    traverse_list(linear_list);

    /* detected cycle */
    hasCycle(NULL);
    hasCycle(linear_list);
    hasCycle(cycle_list);

    /* free memory */
    free_list(linear_list);
    free_list(cycle_list);
    return 0;
}
