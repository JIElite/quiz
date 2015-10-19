#include <stdio.h>
#include <stdlib.h>

#include "list.h"


struct ListNode* hasCycle(struct ListNode *head)
{
    struct ListNode *fast;
    struct ListNode *slow;
    fast = slow = head;
    
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return fast;
        }
    }

    return NULL;
}


void free_list(struct ListNode *head)
{
    struct ListNode *current = head;
    struct ListNode *prev = NULL;
    struct ListNode *cycleNode = NULL;

    while ((cycleNode = hasCycle(head)) != NULL) {
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

    /* detect cycle */
    hasCycle(NULL);
    hasCycle(linear_list);
    hasCycle(cycle_list);

    /* free memory */
    free_list(linear_list);
    free_list(cycle_list);


    return 0;
}
