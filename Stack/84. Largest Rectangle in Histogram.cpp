#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);

        stack<int> stk;

        for(int i = 0; i < n; i++) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            
            if(!stk.empty()) {
                left[i] = stk.top();
            }
            
            stk.push(i);
        }
        
        stk = stack<int>();
        
        for(int i = n - 1; i >= 0; i--) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            
            if(!stk.empty()) {
                right[i] = stk.top();
            }
            
            stk.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};


