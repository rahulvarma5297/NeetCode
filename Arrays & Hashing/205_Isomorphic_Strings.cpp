#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Two maps for s,t strings
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        
        for(int i =0 ;i < s.length(); i++){
            // insert each character if string s and t into seperate map
            map1[s[i]] = i+1;
            map2[t[i]] = i+1;
        }
        
        for(int i =0 ;i < s.length(); i++){
            // compare the maps if not equal return false;
            if (map1[s[i]] != map2[t[i]]){
                return false;
            }
        }
        return true;

    }
};