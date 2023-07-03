#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // next-greater
        // store (value, index)
        int n = temperatures.size();
        stack<pair<int, int>> stk;
        vector<int> ans(n, 0);

        for(int i = n - 1; i >= 0; i--){

            while(!stk.empty() && stk.top().first <= temperatures[i]){
                stk.pop();
            }

            if(!stk.empty()){
                ans[i] = stk.top().second - i;
            }
            
            stk.push({temperatures[i], i});
        }
        return ans;
    }
};