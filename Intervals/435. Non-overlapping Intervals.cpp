#include<bits/stdc++.h>
using namespace std;

// maximum meeting we can attend
// This questions in directly asks how many min meeting we will miss.

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        int prev = 0;
        int count = 1;

        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= intervals[prev][1]){
                prev = i;
                count++;
            }
        }
        return n - count;
    }
};

// Be-Careful of prev -> Don't take blindly i - 1
// [1,11],[2,12],[11,22],[1,100].