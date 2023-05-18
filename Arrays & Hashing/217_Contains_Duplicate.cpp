#include<bits/stdc++.h>

using namespace std;

// Using map.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto x: nums){
            if(m[x]){
                return true;
            }
            m[x]++;
        }
        return false;
    }
};

// Using set.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x: nums){
            s.insert(x);
        }
        if(s.size() == nums.size()){
            return false;
        }
        return true;
    }
};

// Using sorting.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){
                return true;
            }
        }
        return false;
    }
};

