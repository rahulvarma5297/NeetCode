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
    bool ans = false;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        if(p -> val != q -> val){
            return false;
        }
        return (isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right));
    }

    void helper(TreeNode* root, TreeNode* subRoot){
        if(root == NULL){
            return;
        }
        bool val = isSameTree(root, subRoot);
        ans = ans || val;
        helper(root -> left, subRoot);
        helper(root -> right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        helper(root, subRoot);
        return ans;
    }
};


// Clean Code:
class Solution {
public:
    bool ans = false;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        if(p -> val != q -> val){
            return false;
        }
        return (isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }

        if(isSameTree(root, subRoot)){
            return true;
        }
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};