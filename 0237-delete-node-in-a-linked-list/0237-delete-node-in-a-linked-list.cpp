/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        node->val = node->next->val;
      
//         Agar node ke next ka next exist krta h to usko direct node ka next bna do isse beech wala hat jayega
        if(node->next->next)
            node->next = node->next->next;
        else
            node->next = NULL;
        
    }
};