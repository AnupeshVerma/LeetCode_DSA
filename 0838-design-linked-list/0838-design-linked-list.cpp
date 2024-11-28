struct Node {
    int val;
    Node* next;
    Node() : val(0), next(NULL) {}
    Node(int val) : val(val), next(NULL){}
};

class MyLinkedList {
Node * head;
public:
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
       Node* curr = head;
        int counter = 0;
        while(curr && counter < index){
            curr = curr -> next; counter++;
        }
        return (curr) ? curr -> val : -1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if(!head)
            head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }  
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        if(!head){
            head = node; head -> next = NULL;
        }
        else{
            Node* curr = head;
            while(curr && curr -> next){
                curr = curr -> next;
            }
            curr -> next = node; node -> next = NULL;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val); return;
        }
        Node* node = new Node(val);
        Node* prev = NULL; Node* curr = head;
        int counter = 0;
        while(curr && counter < index){
            prev = curr; curr = curr -> next; counter++;
        }
        if(prev && curr){
            prev -> next = node; node -> next = curr;
        }
        else if(prev && !curr){
            prev -> next = node; node -> next = NULL;
        }
        else{
            return; //this is the case when both prev and curr will be NULL, therefore, we wont perform anything and just return the function call back from the stack
        }
    }
    
    void deleteAtIndex(int index) {
        Node* prev = NULL; Node* curr = head;
        int counter = 0;
        while(curr && counter < index){
            prev = curr; curr = curr -> next; counter++;
        }
        if(!prev && curr){
            head = head -> next;
        }
        else if(prev && curr){
            prev -> next = curr -> next;
        }
        else{
            return;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */