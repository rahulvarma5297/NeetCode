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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl > pr || il > ir){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pl]);
        
        int index1;
        for(int i = il; i <= ir; i++){
            if(inorder[i] == root -> val){
                index1 = i;
                break;
            }
        }

        int leftLen = index1 - il;


        root -> left = helper(preorder, inorder, pl + 1, pl + leftLen, il, index1 - 1);
        root -> right = helper(preorder, inorder, pl + leftLen + 1, pr, index1 + 1, ir);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size();
        int n = inorder.size();

        return helper(preorder, inorder, 0, m - 1, 0, n - 1); 
    }
};