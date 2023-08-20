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
    ListNode* partition(ListNode* head, int x) {
        
        vector<int>low, high;
        ListNode *temp = head;
        
        while(temp)
        {
            if(temp->val < x)
                low.push_back(temp->val);
            else
                high.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        for(int i=0; i<low.size(); i++)
        {
            temp->val = low[i];
            temp = temp->next;
        }
         for(int i=0; i<high.size(); i++)
        {
            temp->val = high[i];
            temp = temp->next;
        }
        return head;
        
    }
//         You can also make two sub-linked list and connect them afterwards
        
};