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
    void bruteForce(ListNode* head)
    {
        vector<int>list;
        ListNode* temp = head;
        
        while(temp)
        {
            list.push_back(temp->val);
            temp = temp->next;
        }
        
        int n = list.size(), i=1;
        temp = head;
        temp->next = new ListNode(list[n-1]);
        temp = temp->next;
        for(i=1; i<n/2; i++)
        {
            temp->next = new ListNode(list[i]);
            temp = temp->next;
            temp->next = new ListNode(list[n-i-1]);
             temp = temp->next;
        }
       
        if(n%2 != 0 )
            temp->next = new ListNode(list[i]);
        
        
    }
public:
    void reorderList(ListNode* head) {
        if(!head->next)
            return;
        
        return bruteForce(head);
    }
};