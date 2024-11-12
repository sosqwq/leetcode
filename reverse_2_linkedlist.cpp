// 92. Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right){
            return head;
        }
        ListNode* dummy = new ListNode(0); // Dummy node to simplify edge cases
        dummy->next = head;
        ListNode* prev = dummy;
        //prev 是 current 的前一个节点，因此 left -1;
        for(int i = 0; i< left -1; i++){
            prev = prev -> next;
        } 
        
        ListNode* current = prev -> next;
        ListNode* temp = current->next;
        for (int i = left; i < right; i++) {
            current->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
            temp = current->next;
        }
        return dummy->next;
    }
};