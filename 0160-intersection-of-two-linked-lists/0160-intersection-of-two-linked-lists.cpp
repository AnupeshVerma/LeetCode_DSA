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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        // Brute Force 
//         while(headA)
//         {
//             ListNode* temp = headB;
//             while(temp)
//             {
//                 if(temp == headA)
//                     return temp;
                
//                 temp = temp->next;
//             }
//             headA = headA->next;
//         }
//         return NULL;
        
        // Using Hashing
        unordered_set<ListNode*> st;
        
       while(headA)
       {
           st.insert(headA);
           headA = headA->next;
       }
        while(headB)
        {
            if(st.find(headB) != st.end())
                return headB;
            headB = headB->next;
        }
        
       return NULL;
    }
};