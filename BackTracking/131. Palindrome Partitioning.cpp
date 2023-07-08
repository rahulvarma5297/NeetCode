#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void helper(int start, string s, vector<string>& temp, vector<vector<string>>& ans){
        int n = s.length();

        if(start == n){
            ans.push_back(temp);
        }

        for(int i = start; i < n; i++){
            int len = i - start + 1;
            if(isPossible(s, start, i)){
                temp.push_back(s.substr(start, len));
                helper(start + len, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(0, s, temp, ans);
        return ans;
    }
};