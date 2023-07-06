#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        for(auto x: tasks){
            m[x]++;
        }

        // count
        priority_queue<int> pq;
        for(auto x: m){
            pq.push(x.second);  
        }

        int ans = 0;
        // ans, count
        queue<pair<int, int>> q;

        while(!pq.empty() || !q.empty()){
            if(!pq.empty()){
                if(pq.top() - 1){
                    q.push({pq.top() - 1, ans});
                }
                pq.pop();
            }

            if(!q.empty() && ans - q.front().second == n){
                pq.push(q.front().first);
                q.pop();
            }
            ans++;
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 2;

    // find index of n and delete it
    auto it = find(arr.begin(), arr.end(), n);
    if(it != arr.end()){
        arr.erase(it);
    }

    return 0;
}