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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode *newhead= new ListNode;
        ListNode *tail= new ListNode;
        tail = newhead;


        while(1)
        {
        // Agar dono me se ek khatam ho gyi to bachi wali ko direct jod denge
            if(a == NULL)
            {
                tail->next = b;
                break;
            }               
            else if(b == NULL)
            {
                tail->next = a;
                break;
            }

            if(a->val <= b->val)
            {
               ListNode* temp = new ListNode;
               temp->val = a->val;
               a = a->next;
               tail->next = temp;
               
                
            }
            else
            {
               ListNode* temp = new ListNode;
               temp->val = b->val;
               b = b->next;
               tail->next = temp;
            }
            tail = tail->next;
        }
    return newhead->next;
    }
};