#include<bits/stdc++.h>

using namespace std;

string encode(vector<string>& strs) {
    string res = "";
    for (string s : strs) {
        res += to_string(s.size()) +  s;
    }
    return res;
}

vector<string> decode(string s){
    vector<string> ans;
    int i = 0;
    while(i < s.size()){
        int len = s[i] - '0';
        ans.push_back(s.substr(i + 1, len));
        i = i + len + 1;
    }
    return ans;
}

int main(){
    vector<string> strs = {"Hello", "World"};
    string encoded = encode(strs);
    vector<string> decoded = decode(encoded);
    for(string s : decoded){
        cout << s << " ";
    }
    return 0;
}