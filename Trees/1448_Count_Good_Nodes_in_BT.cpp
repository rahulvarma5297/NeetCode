#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int ans = 0;
    void helper(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return;
        }
        int new_val = val;
        if (root->val >= val)
        {
            ans++;
            new_val = root->val;
        }
        helper(root->left, new_val);
        helper(root->right, new_val);
    }

    int goodNodes(TreeNode *root)
    {
        helper(root, INT_MIN);
        return ans;
    }
};