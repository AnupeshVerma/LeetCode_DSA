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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front, *back;
        
//         Front aur back dono ko ek ek point piche krna padega taki n=1 ke liye bhi kaam kare
        ListNode *start = new ListNode();
        start->next = head;
        front = start;
        back = start;
        
        while(n--)
            front = front->next;
        
        while(front->next)
        {
            front = front->next;
            back = back->next;
        }
        
        back->next = back->next->next;
        
        return start->next;
    }
};