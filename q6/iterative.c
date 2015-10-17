#include <stdio.h>
#include <stdlib.h>


#include "list.h"


struct HeadTail{
    struct ListNode *head;
    struct ListNode *tail;
};

struct HeadTail* reverseList(struct ListNode *head){
    struct ListNode *current = head;
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;

    while(current){
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

struct ListNode *reverseBetween(struct ListNode *head, int m, int n){
    if (m == n) return head;

    struct ListNode *p = head;
    struct ListNode *start = NULL;
    struct ListNode *end = NULL;
    
    /* get start position, end position 
     * The start position is m-1, end is n
     */
    if (m == 1) { start = head; }
    for (int i = 1; i <= n && p; i++){
        if (i == m-1) { start = p; }
        if (i == n) { end = p;}

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
    }
    else { 
        res = reverseList(start->next); 
        start->next = res->head;
        res->tail->next = after_end;
    }

    return head;
}


int main()
{
    struct ListNode *head = NULL;
    for (int i = 1; i <= 5; i++){
        head = append(head, i);
    }
    
#if CASE == 1
    /* case 1 */
    printf("reverse m = 2,  n = 3: ");
    traverse(reverseBetween(head, 2, 3));
#endif


#if CASE == 2
    /* case 2 reverse full list */
    printf("reverse m = 1,  n = 5: ");
    traverse(reverseBetween(head, 1, 5));
#endif


#if CASE == 3
    /* case 3 start position is head */
    printf("reverse m = 1,  n = 4: ");
    traverse(reverseBetween(head, 1, 4));
#endif


#if CASE == 4 
    /* case 4 end position is end of list */
    printf("reverse m = 3,  n = 5: ");
    traverse(reverseBetween(head, 3, 5));
#endif 


#if CASE == 5
    /* case 5 inside the list */
    printf("reverse m = 2,  n = 4: ");
    traverse(reverseBetween(head, 2, 4));
#endif 

    return 0;
}
