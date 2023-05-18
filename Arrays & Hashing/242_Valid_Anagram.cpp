#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> m1, m2;
        for(auto x: s){
            m1[x]++;
        }
        for(auto x: t){
            m2[x]++;
        }

        for(auto x: s){
            if(m1[x] != m2[x]){
                return false;
            }
        }
        return true;
    }
};

