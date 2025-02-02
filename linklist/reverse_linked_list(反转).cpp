// 206  reverse_linked_list（反转）.cpp

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
        ListNode * current = head;
        ListNode * prev = nullptr; 
        ListNode * temp;

        while (current != nullptr){
            temp = current -> next;
            current -> next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
};