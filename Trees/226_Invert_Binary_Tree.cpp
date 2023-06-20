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

class Solution {
public:
    void helper(TreeNode* root){
        if(root == NULL){
            return;
        }
        TreeNode* leftside = root -> left;
        root -> left = root -> right;
        root -> right = leftside;

        helper(root -> left);
        helper(root -> right);
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};