#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> arr;
        for(int i = 0; i < n; i++){
            // time to reach destination
            double time = (target - position[i]) / (double)speed[i];
            arr.push_back({position[i], time});
        }
        sort(arr.begin(), arr.end());
        stack<double> stk;
        for(int i = n - 1; i >= 0; i--){
            if(stk.empty()){
                stk.push(arr[i].second);
                continue;
            }
            if(!stk.empty() && arr[i].second > stk.top()){
                stk.push(arr[i].second);
            }
        }
        return stk.size();
    }
};