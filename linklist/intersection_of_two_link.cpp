//160. Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        if(p1 == nullptr || p2 == nullptr){
            return nullptr;
        }

        int lenA = 0;
        int lenB = 0;

        while (p1 != nullptr){
            lenA ++;
            p1 = p1 ->next;
        }

        while (p2 != nullptr){
            lenB ++;
            p2  = p2 -> next;
        }

        
        p1 = headA;
        p2 = headB;
        if (lenA < lenB){
            swap(lenA,lenB);
            swap(p1, p2);
        }
        int diff = lenA - lenB;
        for (int i = 0; i < diff; i++){
            p1 = p1 -> next;
        }

        for (int i=0;i< lenB;i++){
            if (p1 == p2){
                return p1;
            }
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return nullptr;

    }
};
