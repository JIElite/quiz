#ifndef H_LIST
#define H_LIST

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *create_node(int val);

struct ListNode* append(struct ListNode *head, int val);

struct ListNode* create_list(int start, int end);

void traverse(struct ListNode *p);

void free_list(struct ListNode *head);

#endif
