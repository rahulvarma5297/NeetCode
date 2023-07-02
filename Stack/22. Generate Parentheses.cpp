#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // count of left and right
    // if left < n -> add
    // if right < left -> add
    vector<string> ans;
    void helper(int left, int right, int n, string& s){
        if(left == n && right == n){
            ans.push_back(s);
            return; 
        }

        if(left < n){
            s += '(';
            helper(left + 1, right, n, s);
            s.pop_back();
        }

        if(right < left){
            s += ')';
            helper(left, right + 1, n, s);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string s;
        helper(0, 0, n, s);
        return ans;
    }
};