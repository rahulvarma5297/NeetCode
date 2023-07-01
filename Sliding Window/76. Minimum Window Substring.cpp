#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(unordered_map<char, int>& m1, unordered_map<char, int>& m2){
        for(auto x: m2){
            if(m1[x.first] < x.second){
                return false;
            }
        }
        return true;
    } 

    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char, int> m1, m2;
        for(auto x: t){
            m2[x]++;
        }
        int ans = INT_MAX;
        int left = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            m1[s[r]]++;
            while(helper(m1, m2)){
                if(r - l + 1 < ans){
                    ans = r - l + 1;
                    left = l;
                }
                m1[s[l]]--;
                l++;
            }
        }
        if(ans == INT_MAX){
            return "";
        }
        return s.substr(left, ans);
    }
};