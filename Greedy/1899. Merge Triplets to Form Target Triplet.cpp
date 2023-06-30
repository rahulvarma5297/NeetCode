#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(vector<int>& arr1, vector<int>& arr2){
        if(arr1[0] > arr2[0]){
            return false;
        }
        if(arr1[1] > arr2[1]){
            return false;
        }
        if(arr1[2] > arr2[2]){
            return false;
        }
        return true;
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool cond1 = false;
        vector<bool> cond2(3, false);

        for(auto x: triplets){
            if(helper(x, target)){
                cond1 = true;
                cond2[0] = cond2[0] || (x[0] == target[0]);
                cond2[1] = cond2[1] || (x[1] == target[1]);
                cond2[2] = cond2[2] || (x[2] == target[2]);
            }
        }

        return cond1 && cond2[0] && cond2[1] && cond2[2];
    }
};

// Better Solution:
bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
    vector<int> res(3);
    for (auto &s : triplets)
        if (s[0] <= t[0] && s[1] <= t[1] && s[2] <= t[2])
            res = { max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2]) };
    return res == t;
}