#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int n = prices.size();
        int ans = 0;

        for(int r = 0; r < n; r++){
            if(prices[r] > prices[l]){
                ans = max(ans, prices[r] - prices[l]);
            }
            else{
                l = r;
            }
        }
        return ans;
    }
};

// using sliding window approach