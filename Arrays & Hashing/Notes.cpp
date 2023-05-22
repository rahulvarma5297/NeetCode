#include <bits/stdc++.h>
using namespace std;

// <------------------------------------------------------- STRING STREAM ------------------------------------------------------------------------------>
// StringStream Format
int countWords(string str)
{
    // Breaking input into word
    // using string stream

    // Used for breaking words
    stringstream s(str);

    // To store individual words
    string word;

    int count = 0;
    while (s >> word)
        count++;
    return count;
}

// Convert int to string using stringstream
int int_to_string()
{
    int val = 123;

    // object from the class stringstream
    stringstream geek;

    // inserting integer val in geek stream
    geek << val;

    // The object has the value 123
    // and stream it to the string x
    string x;
    geek >> x;

    // Now the string x holds the
    // value 123
    cout << x + "4" << endl;
    return 0;
}

// <------------------------------------------------------- STRING STREAM ------------------------------------------------------------------------------>

// 118 Pascal's Triangle Intresting way.
// Use vector<int> temp(i + 1, 1); properly (i + 1, 1).

// See about the substring from the geeksforgeeks.
// https://www.geeksforgeeks.org/substring-in-cpp/

// class Substring
// {
//     string s = "abc:def";
//     cout << s.find(":") << endl;
//     cout << s.substr(0, s.find(":")) << endl;  
//     cout << s.substr(s.find(":") + 1) << endl;
// };

// Learn all sorting algo's.