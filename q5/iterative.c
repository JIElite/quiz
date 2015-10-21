#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct ListNode* detectCycle(struct ListNode *head)
{
    struct ListNode *fast = NULL;
    struct ListNode *slow = NULL;
    struct ListNode *finder = NULL;
    finder = fast = slow = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            while(finder != slow) {
                finder = finder->next;
                slow = slow->next;
            }
            return finder;
        }
    }

    return NULL;
}


void free_list(struct ListNode *head)
{
    struct ListNode *current = head;
    struct ListNode *prev = NULL;
    struct ListNode *cycleNode = detectCycle(head);

    struct ListNode *p = cycleNode;
    while (p != NULL) {
        if (p->next == cycleNode) p->next = NULL;
        p = p->next;
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

    /* detect cycle */
    detectCycle(NULL);
    detectCycle(linear_list);
    detectCycle(cycle_list);

    /* free memory */
    free_list(linear_list);
    free_list(cycle_list);


    return 0;
}
