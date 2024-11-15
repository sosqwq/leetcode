//19. Remove Nth Node From End of List
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
    ListNode* swapPairs(ListNode* head, int n) {
        ListNode * dummy = new ListNode(0);
        dummy -> next = head;
        ListNode * current = dummy;

        ListNode * fast = current;
        ListNode * slow = current;
        for (int i= 0; i< n+1; i++){
            fast = fast -> next;
        }

        while ( fast != nullptr){
            fast = fast -> next;
            slow = slow -> next;

        }
        slow -> next = slow -> next -> next;
        return dummy -> next;
        

        



    }
 };