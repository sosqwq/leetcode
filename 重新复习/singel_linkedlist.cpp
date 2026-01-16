class MyLinkedList {
    struct Node{
        int val;
        Node * next;
        Node(int x):val(x),next(nullptr){};
    };

    Node * head;
    int size;
public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
       int val = -1;
        if(index >= size|| index < 0 || head == nullptr){
            return val;
        }
        Node * curr = head;
            while(index > 0){
                curr = curr -> next;
                index --;
            }
        val = curr ->val;
        return val;
    }
    
  void addAtHead(int value) {
        Node * curr = new Node(value);
        curr -> next = head;
        head = curr;
        size ++;

    }
    
    void addAtTail(int val) {
        Node * tail = new Node(val);
        Node * curr = head;
        if (head == nullptr){
            head = tail;
        }
        else {
            while (curr -> next != nullptr){
                curr = curr -> next;
            }
            curr -> next  = tail;
        }
        size ++;
    }
    
    void addAtIndex(int index, int val) {
        Node * node = new Node(val);
        Node * curr = new Node(0);
        curr -> next = head;
        if (index > size ){
            return;
        }
        if (index == 0){
            addAtHead(val);
            return;
        }
        if (index == size){
            addAtTail(val);
            return;
        }

        while(index > 0){
            curr = curr -> next;
            index --;
        }
        node -> next = curr -> next;
        curr -> next = node;
        size ++;
            
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0 || head == nullptr) { 
            return;
        }
        if(index == 0){
            Node * temp = head;
            head = head -> next;
            delete temp;
        }
        else{
            Node * curr = new Node(0);
            curr -> next = head;
            while (index > 0){
                curr = curr -> next;
                index --;
            }
            Node * temp = curr -> next ;
             curr -> next= temp -> next ;
            delete temp;
        }
        size --;
 
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