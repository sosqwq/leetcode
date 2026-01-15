#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode (): val(0), next(nullptr){};
    ListNode (int x):val(x), next(nullptr) {};
    ListNode (int x, ListNode *next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 设置一个虚拟头结点在进行移除节点操作
        ListNode * dummyHead = new ListNode (0);
        dummyHead -> next = head;
        ListNode * curr = dummyHead;

        while (curr -> next != nullptr){
            if(curr -> next -> val == val){
                ListNode * temp = curr -> next;
                curr -> next = curr -> next -> next;
                delete temp;
            }
            else {
                curr = curr-> next;
            }
        }
        head = dummyHead -> next;
        delete dummyHead;
        return head;

    }
};