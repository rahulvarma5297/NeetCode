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
            ListNode* nxt = head -> next;
            head -> next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* fin = new ListNode(0);
        ListNode* ans = fin;
        int cnt = 0;
        ListNode* first = head;

        while(head){
            cnt++;
            
            if(cnt == k){
                ListNode* nxt = head -> next;
                head -> next = NULL;

                ans -> next = reverse(first);
                first = nxt;

                while(ans -> next != NULL){
                    ans = ans -> next;
                }
                head = nxt;
                cnt = 0;
            }
            else{
                head = head -> next;
            }
        }

        ans -> next = first;
        return fin -> next;
    }
};