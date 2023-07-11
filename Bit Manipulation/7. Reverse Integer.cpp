#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long int t = abs(x);
        long long int rev = 0;
        
        while(t != 0){
            int a = t % 10;
            rev = (rev * 10) + a;
            t = t/10;
        }
        if(rev > INT_MAX || rev < INT_MIN)
        {
            return 0;
        }
        if(x >= 0){
            return rev;
        }
        else{
            return -rev;
        }
    }
};