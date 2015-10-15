#include <stdio.h>

#include "list.h"


struct ListNode* hasCycle(struct ListNode *head)
{
        struct ListNode *fast;
        struct ListNode *slow;
        fast = slow = head;

        while (slow && fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) { return fast; }
        }

        return NULL;
}



int main()
{
        
        struct ListNode *cycle_list = create_cycle_list(1, 6);
        struct ListNode *linear_list = create_linear_list(5);

        /* traverse list */
        //traverse_list(cycle_list);
        traverse_list(linear_list);

        /* testing cycle: iterative version */
        hasCycle(NULL);
        hasCycle(linear_list);
        hasCycle(cycle_list);

        return 0;
}
