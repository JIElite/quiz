#include <stdio.h>

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

struct ListNode* hasCycle_rev(struct ListNode *head){
    return detect_cycle_rec(head, head);
}


int main()
{
        struct ListNode *cycle_list = create_cycle_list(1, 6);
        struct ListNode *linear_list = create_linear_list(5);

        /* traverse list */
        //traverse_list(cycle_list);
        traverse_list(linear_list);

        hasCycle_rev(NULL);
        hasCycle_rev(linear_list);
        hasCycle_rev(cycle_list);
 
    return 0;
}
