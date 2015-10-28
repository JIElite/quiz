#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

#if METHOD == 1
#include "iterative.h"
#endif 

#if METHOD == 2
#include "recursive.h"
#endif 

extern struct ListNode *reverseBetween(struct ListNode*, int, int);

int main(int argc, char *argv[]){

    assert(argc == 2);

    /* create a sequential list */
    struct ListNode *head = create_list(1, 5); 
    printf("Initial list: ");
    traverse(head);
    
    
    /* run test case */
    int test_case = atoi(argv[1]);
    assert(test_case > 0 && test_case <= 5);
    switch(test_case){
        case 1:
            /* case 1 */
            printf("reverse m = 2,  n = 3: ");
            head = reverseBetween(head, 2, 3);
            break;
        case 2:
            /* case 2 reverse full list */
            printf("reverse m = 1,  n = 5: ");
            head = reverseBetween(head, 1, 5);
            break;
        case 3:
            /* case 3 start position is head */
            printf("reverse m = 1,  n = 4: ");
            head = reverseBetween(head, 1, 4);
            break;
        case 4:
            /* case 4 end position is end of list */
            printf("reverse m = 3,  n = 5: ");
            head = reverseBetween(head, 3, 5);
            break;
        case 5:
            /* case 5 inside the list */
            printf("reverse m = 2,  n = 4: ");
            head = reverseBetween(head, 2, 4);
            break;
    }
    
    printf("After reverse:");
    traverse(head);

    /* free memory */
    free_list(head);
    return 0;
}
