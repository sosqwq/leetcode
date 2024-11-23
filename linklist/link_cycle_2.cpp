//142 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow  = head;
        ListNode *fast = head;

        while ( fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast =  fast -> next -> next;
            if (slow == fast) {
                ListNode * include1 = head;
                ListNode * include2 = fast;
                while (include1 != include2) {
                    include1 = include1 -> next;
                    include2 = include2 -> next;

                }
                return include1;

            }
            
        }
        return nullptr;

    }
};