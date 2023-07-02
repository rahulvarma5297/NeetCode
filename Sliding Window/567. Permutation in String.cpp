#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        if(s2.size() < n){
            return false;
        }
        vector<int> arr1(26, 0), arr2(26, 0);
        for(auto x: s1){
            arr1[x - 'a']++;
        }
        for(int i = 0; i < n; i++){
            arr2[s2[i] - 'a']++;
        }

        if(arr1 == arr2){
            return true;
        }

        for(int i = n; i < s2.length(); i++){
            arr2[s2[i] - 'a']++;
            arr2[s2[i - n] - 'a']--;
            if(arr1 == arr2){
                return true;
            }
        }
        return false;
    }
};