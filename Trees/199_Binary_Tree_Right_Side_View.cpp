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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int si = q.size();

            for(int i = 0; i < si; i++){
                auto t = q.front();
                q.pop();
                
                if(i == si - 1){
                    ans.push_back(t -> val);
                }

                if(t -> left){
                    q.push(t -> left);
                }

                if(t -> right){
                    q.push(t -> right);
                }
            }
        } 
        return ans;
    }
};