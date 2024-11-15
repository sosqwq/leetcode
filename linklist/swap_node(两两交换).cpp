// 24. Swap Nodes in Pairs
#include <iostream>
#include <vector>
using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy;

        ListNode *temp;
        ListNode *temp1;
        while (current -> next != nullptr && current -> next -> next != nullptr){
            temp = current ->next;
            temp1 = current -> next ->next ->next;

            current -> next = current -> next -> next;
            current -> next -> next = temp;
            temp -> next = temp1;
 
            current = current -> next -> next;

        }
        return dummy -> next;






    }
};