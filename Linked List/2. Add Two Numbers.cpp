#include<bits/stdc++.h>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* fin = new ListNode(0);
        ListNode* ans = fin;
        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry){
            int d1 = l1 ? l1 -> val : 0;
            int d2 = l2 ? l2 -> val : 0;

            int sum = d1 + d2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* n = new ListNode(sum);
            ans -> next = n;
            ans = ans -> next;

            l1 = l1 ? l1 -> next : NULL;
            l2 = l2 ? l2 -> next : NULL;
        }


        return fin -> next;
    }
};