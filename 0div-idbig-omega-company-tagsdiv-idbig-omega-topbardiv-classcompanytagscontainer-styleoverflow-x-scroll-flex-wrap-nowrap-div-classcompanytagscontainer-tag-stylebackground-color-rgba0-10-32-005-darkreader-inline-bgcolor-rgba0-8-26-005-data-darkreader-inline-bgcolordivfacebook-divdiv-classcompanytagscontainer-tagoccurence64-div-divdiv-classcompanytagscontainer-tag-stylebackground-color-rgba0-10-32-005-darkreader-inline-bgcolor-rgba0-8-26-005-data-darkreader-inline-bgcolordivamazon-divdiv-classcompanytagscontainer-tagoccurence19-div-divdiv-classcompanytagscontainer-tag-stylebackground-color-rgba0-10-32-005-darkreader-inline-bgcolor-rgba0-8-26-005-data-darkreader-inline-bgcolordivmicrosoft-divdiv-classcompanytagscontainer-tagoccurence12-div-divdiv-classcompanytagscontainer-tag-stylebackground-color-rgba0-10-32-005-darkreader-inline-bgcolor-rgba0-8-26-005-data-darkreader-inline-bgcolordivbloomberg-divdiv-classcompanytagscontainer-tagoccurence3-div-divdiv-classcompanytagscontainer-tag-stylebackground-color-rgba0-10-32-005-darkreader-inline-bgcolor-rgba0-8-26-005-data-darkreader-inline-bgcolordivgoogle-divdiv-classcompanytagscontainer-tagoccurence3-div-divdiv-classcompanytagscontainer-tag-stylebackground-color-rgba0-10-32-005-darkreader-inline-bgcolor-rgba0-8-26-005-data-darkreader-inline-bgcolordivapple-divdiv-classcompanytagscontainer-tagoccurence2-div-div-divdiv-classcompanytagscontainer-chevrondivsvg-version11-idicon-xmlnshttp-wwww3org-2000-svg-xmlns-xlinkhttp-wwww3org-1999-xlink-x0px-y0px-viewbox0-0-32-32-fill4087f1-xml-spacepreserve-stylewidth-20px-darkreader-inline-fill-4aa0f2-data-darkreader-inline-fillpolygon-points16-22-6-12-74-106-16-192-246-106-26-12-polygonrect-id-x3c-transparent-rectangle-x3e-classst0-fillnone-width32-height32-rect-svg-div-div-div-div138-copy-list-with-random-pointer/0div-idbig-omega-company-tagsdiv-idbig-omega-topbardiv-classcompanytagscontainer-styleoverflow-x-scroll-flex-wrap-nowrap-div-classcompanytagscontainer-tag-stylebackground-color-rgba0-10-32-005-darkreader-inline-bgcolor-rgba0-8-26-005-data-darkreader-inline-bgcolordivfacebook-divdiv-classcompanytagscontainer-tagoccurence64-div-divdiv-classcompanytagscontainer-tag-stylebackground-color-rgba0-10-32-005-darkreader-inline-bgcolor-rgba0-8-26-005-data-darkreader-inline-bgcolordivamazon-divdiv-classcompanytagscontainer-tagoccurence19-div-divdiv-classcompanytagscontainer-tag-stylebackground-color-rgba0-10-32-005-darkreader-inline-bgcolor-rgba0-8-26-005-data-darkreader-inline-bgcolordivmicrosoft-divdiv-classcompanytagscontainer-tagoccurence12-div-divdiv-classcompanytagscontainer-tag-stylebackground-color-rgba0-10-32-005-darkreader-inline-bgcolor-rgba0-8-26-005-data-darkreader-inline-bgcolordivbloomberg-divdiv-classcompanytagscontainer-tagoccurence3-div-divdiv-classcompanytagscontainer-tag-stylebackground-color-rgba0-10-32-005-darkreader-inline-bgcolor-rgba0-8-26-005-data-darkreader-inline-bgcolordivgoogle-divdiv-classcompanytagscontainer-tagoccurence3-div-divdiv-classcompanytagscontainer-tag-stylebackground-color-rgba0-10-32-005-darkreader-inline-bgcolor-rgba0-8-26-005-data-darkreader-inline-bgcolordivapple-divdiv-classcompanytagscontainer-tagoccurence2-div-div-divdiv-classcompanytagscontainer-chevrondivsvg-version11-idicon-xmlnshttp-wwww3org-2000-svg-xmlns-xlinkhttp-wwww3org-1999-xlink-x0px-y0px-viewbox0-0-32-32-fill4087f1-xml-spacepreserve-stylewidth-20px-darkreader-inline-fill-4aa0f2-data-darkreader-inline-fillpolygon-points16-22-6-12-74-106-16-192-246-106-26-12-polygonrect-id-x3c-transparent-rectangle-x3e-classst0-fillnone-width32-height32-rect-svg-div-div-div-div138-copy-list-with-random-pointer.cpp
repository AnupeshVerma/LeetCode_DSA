/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copiedNodes;
        
        Node* temp = head;
        while(temp)
        {
            copiedNodes[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        while(temp)
        {
            copiedNodes[temp]->next = copiedNodes[temp->next];
            copiedNodes[temp]->random = copiedNodes[temp->random];
            temp = temp->next;
        }
        return copiedNodes[head];
    }
};