/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode* curr = head;
        
        while(curr->next)
        {
            if(curr->next->val == val)
            {
                ListNode* to_delete = curr->next;
                curr->next = curr->next->next;
                delete(to_delete);
                             
            }
            else curr = curr->next;
        }
        if(head->val == val)
            head = head->next;
        return head;
    }
};