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
    ListNode* bruteForce(ListNode* head)
    {
        int num = 0;
        ListNode* temp = head;
        
        while(temp)
        {
            num = num*10 + temp->val;
            temp = temp->next;
        }
        
        num = num*2;
        ListNode* newHead = NULL;
        while(num)
        {
            ListNode* newNode = new ListNode(num%10);
            num = num/10;
            
            newNode->next = newHead;
            newHead = newNode;
        }
        
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode *prev, *curr, *nest;
        curr = head;
        prev = NULL;
        
        while(curr)
        {
            nest = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nest;
        }
        return prev;
    }
    
    ListNode* solve(ListNode* head)
    {
        
        head = reverseList(head);
        
        ListNode* temp = head;
        int carry = 0;
        while(temp)
        {
            int num = 2*temp->val;
            temp->val = num%10 + carry;
             carry = num>=10 ? 1 : 0;
            temp = temp->next;
            
        }
        head = reverseList(head);
        if(carry)
        {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        
        if(!head->next && head->val == 0)
            return head;
        
        // return bruteForce(head);
        
        return solve(head);
    }
};