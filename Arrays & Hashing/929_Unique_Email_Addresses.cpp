#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ans;

        for(auto str: emails){
            string temp = "";
            for(auto x: str){
                if(x == '@' || x == '+'){
                    break;
                }else if(x == '.'){
                    continue;
                }else{
                    temp += x;
                }

            }
            temp += str.substr(str.find("@"));
            ans.insert(temp);
        }

        return ans.size();
    }
};