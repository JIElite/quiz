#include <stdio.h>
#include <stdlib.h>

#include "list.h"


struct ListNode* detectCycleRec(struct ListNode *slow, struct ListNode *fast, struct ListNode *result, int is_meet)
{
       
    if (fast && fast->next) {
        if (is_meet){
            if (slow == result) return result;
            else return detectCycleRec(slow->next, fast, result->next, 1);
        }
        else{
            if (slow == fast && is_meet == 0) return detectCycleRec(slow, fast, result, 1);
            return detectCycleRec(slow->next, fast->next->next, result, 0);
        }
    }

    return NULL;

}

struct ListNode* detectCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL) return NULL;
    return detectCycleRec(head->next, head->next->next, head, 0);
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

    /* traverse list */
    //traverse_list(cycle_list);
    traverse_list(linear_list);

    /* detected cycle */
    detectCycle(NULL);
    detectCycle(linear_list);
    detectCycle(cycle_list);

    /* free memory */
    free_list(linear_list);
    free_list(cycle_list);
    return 0;
}
