
//Accepted	8 ms	cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;

        dfs(root,ans);

        return ans;
    }

    void dfs(TreeNode* root,vector<int>& ans)
    {
        if(root == NULL) return ;
        dfs(root->left,ans);
        dfs(root->right,ans);
        ans.push_back(root->val);
    }
};
