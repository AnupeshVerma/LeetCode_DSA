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
    ListNode* bruteForce(ListNode *list1, int a, int b, ListNode* list2)
    {
        ListNode* nodeA=list1, *nodeB=list1;
        while(--a)
            nodeA = nodeA->next;
        while(b--)
            nodeB = nodeB->next;
        
        ListNode* lastNode2=list2;
        while(lastNode2->next)
            lastNode2 = lastNode2->next;
        
        lastNode2->next = nodeB->next;
        nodeA->next = list2;
        
        return list1;
        
    }
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        
        return bruteForce(list1, a, b, list2);
    }
};