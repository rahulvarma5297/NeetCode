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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* head = new ListNode(0);
        ListNode* ans = head;

        while(true){
            int index = -1;
            int val = INT_MAX;

            for(int i = 0; i < n; i++){
                if(lists[i] != NULL && lists[i] -> val < val){
                    val = lists[i] -> val;
                    index = i;
                }
            }

            if(index == -1){
                break;
            }

            ans->next = lists[index];
            ans = ans -> next;
            lists[index] = ans -> next;
        }

        return head -> next; 
    }
};