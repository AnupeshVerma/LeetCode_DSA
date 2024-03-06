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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head)
            return head;
        
        int n=0;
        ListNode*temp=head;
        while(temp)
        {
            n++;
            temp = temp->next;
        }
        k = k % n;
        if(k==0) return head;
        
        while(k--)
        {
            int nextNodeValue=head->val;
            ListNode *curr=head;
            while(curr->next)
            {
                int temp = nextNodeValue;
               nextNodeValue = curr->next->val;
                curr->next->val = temp;
                curr = curr->next;
                
            }
            head->val = nextNodeValue;
        }
        
        return head;
    }
};