#include <stdio.h>
#include <stdlib.h>

#include "list.h"



struct ListNode *reverse(struct ListNode *start, struct ListNode *current, 
        struct ListNode *next, int count, int total, int ishead){
    
    if (count != total && next) { 
        struct ListNode *next2 = next->next;
        next -> next = current;
        return reverse(start, next, next2, count+1, total, ishead);
    } 
    else{
        if (ishead){
            start->next = next;
            return current;
        }
        else {
            start->next->next = next;
            start->next = current;
            return start;
        }
    }


}


struct ListNode *reverseBetween(struct ListNode *head, int m, int n){
    if (m == n ) return head;

    struct ListNode *entry = head;
    for ( int i = 1; i < m-1; i++) { entry = entry -> next; }
    if (m == 1) { head = reverse(entry, entry, entry->next, 0, n-m, 1); }
    else { reverse(entry, entry->next, entry->next->next, 0, n-m, 0); }
   
    return head;
}



int main(){
    struct ListNode *head = NULL;
    for (int i = 1; i <= 5; i++) { head = append(head, i); }
    traverse(head);
    
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
