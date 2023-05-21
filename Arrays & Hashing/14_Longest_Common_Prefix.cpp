#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string curr = strs[0];

        for(int i = 1; i < n; i++){
            string temp = "";
            int len = min(curr.length(), strs[i].length());

            for(int j = 0; j < len; j++){
                if(curr[j] == strs[i][j]){
                    temp += curr[j];
                }else{
                    break;
                }
            }
            curr = temp;
        }
        return curr;
    }
};

// Or Just Sort the array and just compare the first and last element of the array

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string curr = strs[0];

        for(int i = 1; i < n; i++){
            string temp = "";
            int len = min(curr.length(), strs[i].length());

            for(int j = 0; j < len; j++){
                if(curr[j] == strs[i][j]){
                    temp += curr[j];
                }else{
                    break;
                }
            }
            curr = temp;
        }
        return curr;
    }
};
