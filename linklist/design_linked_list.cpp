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
        int data = -1;

        if (index >= size|| index < 0 || head == nullptr){
            return data;
        }

        Node * current = head;
        while (index >0){
            current = current ->next;
            index--;
            
        }
        data = current -> val;
        return  data;
    }
    
    void addAtHead(int val) {
        Node * curr = new Node(val);
        curr -> next = head;
        head  = curr;
        size ++;
    }
    
    void addAtTail(int val) {
        Node * tail = new Node(val);
        if (head == nullptr){
            head = tail;
        }
        else {
        Node * current = head;
        while (current -> next != nullptr){
            current = current ->next;
        } 
        current -> next = tail;}
         size ++;
    }
    
    void addAtIndex(int index, int val) {
        Node * node = new Node(val);
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

        Node * current = head;

        while ( index > 1){
            index --;
            current = current ->next;  

        }
        
        node ->next = current ->next;
         current ->next = node;
         size ++;
            
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0 || head == nullptr) { 
            return;
    }
        if (index == 0){
            Node * temp = head;
            head = head ->next;
            delete temp ;
        }
        else{
            Node * current = head;
        while( index > 1){
            index --;
            
            current = current ->next;
            
        }
        Node * temp = current -> next;
        current -> next  = temp ->next;
        delete temp;

        }
        size--;
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