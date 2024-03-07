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
    ListNode* middleNode(ListNode* head) {
//         Brute Force Approach
//         ListNode* temp = head;
//         int node_count = 0;
        
//         while(temp)
//         {
//             node_count++;
//             temp = temp->next;
//         }
        
//         temp = head;
//         int mid = node_count/2;
        
//         while(mid--)
//             temp = temp->next;
        
//         return temp;
        
        
//         Optimal Approach
        ListNode *slow=head, *fast=head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
            
        return slow;
            
    }
};