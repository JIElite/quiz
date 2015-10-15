#include <stdio.h>

#ifndef H_LIST
#define H_LIST 1


struct ListNode {
        int val;
        struct ListNode *next;
};


struct ListNode* create_node(int val);

void traverse_list(struct ListNode *head);


struct ListNode *create_cycle_list(int cycle_pos, int size);


struct ListNode *create_linear_list(int size);
#endif 
