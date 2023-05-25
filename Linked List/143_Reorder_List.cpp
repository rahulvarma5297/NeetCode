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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;

        while(head){
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow -> next;
            fast = fast->next->next;
        }

        ListNode* second = reverse(slow->next);
        slow->next = NULL;

        ListNode* ans = head;

        while(second){
            ListNode* ansnxt = ans->next;
            ListNode* secnxt = second->next;

            ans->next = second;
            second->next = ansnxt;

            ans = ansnxt;
            second = secnxt;
        }
    }
};