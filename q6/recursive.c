#include <stdio.h>
#include <stdlib.h>

#include "list.h"



struct ListNode *reverse(struct ListNode *start, struct ListNode *current,
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

int main(int argc, char *argv[])
{

    
    struct ListNode *head = create_list(1, 5);

    int test_case = atoi(argv[1]);
    /* case 1 */
    if (test_case == 1){
        printf("reverse m = 2,  n = 3: ");
        traverse(reverseBetween(head, 2, 3));
    }

    /* case 2 reverse full list */
    if (test_case == 2){
        printf("reverse m = 1,  n = 5: ");
        traverse(reverseBetween(head, 1, 5));
    }

    /* case 3 start position is head */
    if (test_case == 3){ 
        printf("reverse m = 1,  n = 4: ");
        traverse(reverseBetween(head, 1, 4));
    }

    /* case 4 end position is end of list */
    if (test_case == 4){
        printf("reverse m = 3,  n = 5: ");
        traverse(reverseBetween(head, 3, 5));
    }
    
    /* case 5 inside the list */
    if (test_case == 5){
        printf("reverse m = 2,  n = 4: ");
        traverse(reverseBetween(head, 2, 4));
    }

    free_list(head);

    return 0;
}
