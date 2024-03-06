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
    ListNode* method1(ListNode* head, int k)
    {
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
    
    ListNode* method2(ListNode* head, int k, int n, ListNode* lastNode)
    {
        ListNode* lastNodeAfterRotation = head;
        int index = n-k-1;
        while(index--)
         lastNodeAfterRotation = lastNodeAfterRotation->next;   
        
        ListNode* newHead = lastNodeAfterRotation->next;
        lastNodeAfterRotation->next = NULL;
        lastNode->next = head;
        
        return newHead;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head)
            return head;
        
        int n=1;
        ListNode*lastNode=head;
        while(lastNode->next)
        {
            n++;
            lastNode = lastNode->next;
        }
        k = k % n;
        if(k==0) return head;
        
        // return method1(head, k);
        return method2(head, k, n, lastNode);
    }
};