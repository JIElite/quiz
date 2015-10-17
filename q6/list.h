#ifndef H_LIST
#define H_LIST

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *create_node(int val);

void traverse(struct ListNode *p);

struct ListNode* append(struct ListNode *head, int val);


#endif 
