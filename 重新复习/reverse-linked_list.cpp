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
    ListNode* reverseList(ListNode* head) {
        ListNode * curr = head;
        ListNode * pre = nullptr;
        ListNode * temp;

        while(curr != nullptr){
            temp = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
};