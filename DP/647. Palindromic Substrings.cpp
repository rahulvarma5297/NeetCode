#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int helper(int start, string s) {
        int count = 0;
        int n = s.length();

        for (int i = start; i < n; i++) {
            if (isPossible(s, start, i)) {
                count++;
            }
        }

        return count;
    }


    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += helper(i, s);
        }

        return count;
    }

};