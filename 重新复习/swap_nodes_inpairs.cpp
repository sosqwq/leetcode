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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead ->next = head;
        ListNode * curr = dummyHead;
        ListNode * temp;
        ListNode * temp1;
        while(curr -> next != nullptr && curr -> next -> next != nullptr){
            temp = curr -> next;
            temp1 = curr -> next -> next -> next;

            curr -> next = curr -> next -> next;
            curr -> next -> next = temp;
            temp -> next = temp1;
            curr =  temp;
        }
        return dummyHead -> next;
    }
};