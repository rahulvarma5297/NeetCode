// Good Question.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(string s, int i, int k, vector<int>& count){
        // rem <= k
        int maxi = 0;
        int sum = 0;

        for(int j = 0; j < 26; j++){
            maxi = max(maxi, count[j]);
            sum += count[j];
        }

        if(sum - maxi <= k){
            return true;
        }
        return false;
    }

    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> count(26, 0);

        int l = 0;
        int ans = 1;

        for(int r = 0; r < n; r++){
            count[s[r] - 'A']++;
            if(helper(s, r, k, count)){
                ans = max(ans, r - l + 1);
            }else{
                count[s[l] - 'A']--;
                l++;
            }
        }
        return ans;
    }
};