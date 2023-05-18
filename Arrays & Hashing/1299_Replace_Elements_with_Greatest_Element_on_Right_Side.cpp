#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int curr = -1;
        vector<int> ans(n, -1);

        for(int i = n - 1; i >= 0; i--){
            ans[i] = curr;
            curr = max(curr, arr[i]);
        }

        return ans;
    }
};