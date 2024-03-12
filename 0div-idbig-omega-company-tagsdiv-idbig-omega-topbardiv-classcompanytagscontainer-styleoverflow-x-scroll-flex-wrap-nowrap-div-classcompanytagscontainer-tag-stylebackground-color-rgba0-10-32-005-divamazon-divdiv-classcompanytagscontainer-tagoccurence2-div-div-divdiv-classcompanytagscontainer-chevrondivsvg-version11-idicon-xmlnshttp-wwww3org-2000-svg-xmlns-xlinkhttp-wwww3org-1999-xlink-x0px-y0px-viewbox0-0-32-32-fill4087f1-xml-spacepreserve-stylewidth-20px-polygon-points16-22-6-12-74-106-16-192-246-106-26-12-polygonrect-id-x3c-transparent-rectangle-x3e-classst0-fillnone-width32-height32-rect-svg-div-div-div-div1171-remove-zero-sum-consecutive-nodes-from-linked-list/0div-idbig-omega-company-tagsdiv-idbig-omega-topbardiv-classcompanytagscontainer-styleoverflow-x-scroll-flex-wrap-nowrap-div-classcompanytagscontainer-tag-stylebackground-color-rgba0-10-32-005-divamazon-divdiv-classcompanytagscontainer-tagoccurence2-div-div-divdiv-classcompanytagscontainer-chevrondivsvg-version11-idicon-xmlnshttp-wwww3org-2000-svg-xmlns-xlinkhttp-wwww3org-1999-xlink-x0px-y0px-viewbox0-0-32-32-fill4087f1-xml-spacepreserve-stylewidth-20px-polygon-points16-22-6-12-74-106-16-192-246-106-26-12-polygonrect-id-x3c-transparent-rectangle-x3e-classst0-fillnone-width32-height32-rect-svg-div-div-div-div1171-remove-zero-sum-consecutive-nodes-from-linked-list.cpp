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
private:
    ListNode* prefixSum(ListNode* head)
    {
        ListNode *front = new ListNode(0, head);
        ListNode *start = front;

        while(start)
        {
            ListNode *end = start->next;
            int prefixSum = 0;
            
            while(end)
            {
                prefixSum += end->val;
                
                if(prefixSum==0)
                    start->next = end->next;
                
                end = end->next;
            }
            start = start->next;
        }
        return front->next;
    }
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        
        return prefixSum(head);
    }
};