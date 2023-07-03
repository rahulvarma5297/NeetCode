#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for(auto x: piles){
            high = max(high, x);
        }        

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long hours = 0;
            for(auto x: piles){
                hours += ceil(x / (double)mid);
            }
            if(hours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};