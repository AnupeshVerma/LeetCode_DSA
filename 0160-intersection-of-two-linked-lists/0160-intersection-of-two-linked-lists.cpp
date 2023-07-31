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
//         unordered_set<ListNode*> st;
        
//        while(headA)
//        {
//            st.insert(headA);
//            headA = headA->next;
//        }
//         while(headB)
//         {
//             if(st.find(headB) != st.end())
//                 return headB;
//             headB = headB->next;
//         }
        
//        return NULL;
        
        
        // Using Difference in Length
       ListNode *a = headA, *b = headB;
        int l1 = 0, l2=0;
        
        while(a)
        {
            l1++;
            a = a->next;
        }
        while(b)
        {
            l2++;
            b = b->next;
        }
        
        int diff = abs(l1-l2);
        a=headA, b=headB;
        while(diff--)
            if(l1>l2)
                headA = headA->next;
            else
                headB = headB->next;
        while(headA && headB)
        {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};