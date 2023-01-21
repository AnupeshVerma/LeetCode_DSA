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
    ListNode* copy_head = new ListNode;
    bool isPalindrome(ListNode* head) {
        
        //--------------ITERATIVE SOLUTION-----------------
   /*     vector<int> v1;
        while(head)
        {
            v1.push_back(head->val);
            head = head->next;
        }
        vector<int> v2 = v1;
        reverse(v1.begin(), v1.end());
        return v1 == v2;
        */
        
        //------------------RECURSIVE SOLUTION--------------
        copy_head = head;
        return solve(head);
    }
    
    bool solve(ListNode* curr)
    {
        if(!curr)
            return true;
        
        if(!solve(curr->next))
            return false;
        
        if(curr->val != copy_head->val)
            return false;
        
        copy_head = copy_head->next;
        return true;
    }
    
};