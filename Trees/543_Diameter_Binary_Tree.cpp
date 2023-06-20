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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int l = maxDepth(root -> left);
        int r = maxDepth(root -> right);

        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }    
        int l = maxDepth(root -> left);
        int r = maxDepth(root -> right);

        return max({l + r, diameterOfBinaryTree(root -> left), diameterOfBinaryTree(root -> right)});
    }
};